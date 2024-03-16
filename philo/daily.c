/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daily.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 22:22:13 by mneves-l          #+#    #+#             */
/*   Updated: 2024/03/16 17:31:12 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*daily(void *philos)
{
	t_philo	*philo;

	philo = (t_philo *)philos;
	if (philo->id % 2)
		usleep(5000);
	while (!lock_dead(philo->data))
	{
		if (eating(philo, philo->data))
			return (NULL);
		if (philo->x_eat == philo->data->max_meals)
			break ;
		if (!lock_dead(philo->data))
		{
			printer("is sleeping", philo->data->start_time, philo, philo->data);
			ft_sleep(philo->data->time_to_sleep, philo->data);
		}
		if (!lock_dead(philo->data))
			printer("is thinking", philo->data->start_time, philo, philo->data);
	}
	return (NULL);
}

int	lock_dead(t_data *data)
{
	int	death;

	pthread_mutex_lock(&(data->death));
	death = data->is_dead;
	pthread_mutex_unlock(&(data->death));
	return (death);
}

int	check_dead(t_philo *philo, t_data *data)
{
	if (lock_dead(data))
		return (1);
	usleep(500);
	pthread_mutex_lock(&(data->death));
	if (diff_time(philo->last_meal, ft_time()) >= data->time_to_die)
	{
		pthread_mutex_lock(&(data->print));
		data->is_dead++;
		pthread_mutex_unlock(&(data->print));
		if (data->is_dead == 1)
			printer("died", philo->last_meal, philo, data);
		pthread_mutex_unlock(&(data->death));
		return (1);
	}
	else
		pthread_mutex_unlock(&(data->death));
	return (0);
}

int	ft_sleep(int time, t_data *data)
{
	int	i;
	int	j;

	i = ft_time();
	j = 0;
	while (!(lock_dead(data)) && j < time)
	{
		if (lock_dead(data))
			return (1);
		usleep(100);
		j = diff_time(i, ft_time());
	}
	return (j >= time);
}

int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}
