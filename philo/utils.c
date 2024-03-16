/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 21:08:03 by mneves-l          #+#    #+#             */
/*   Updated: 2024/03/16 17:31:22 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	printer(const char *msg, long long time, t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&(data->print));
	printf("%lli %d %s\n", (ft_time() - time), (philo->id + 1), msg);
	pthread_mutex_unlock(&(data->print));
}

int	diff_time(long long a, long long b)
{
	return (ft_abs(b - a));
}

void	exit_program(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
		pthread_mutex_destroy(&(data->forks[i]));
	pthread_mutex_destroy(&(data->print));
	free(data->forks);
}

void	error(char *s, int flag, t_data *data)
{
	if (flag == 1)
	{
		free(data->forks);
		free(data->philo);
	}
	printf("Error: %s\n", s);
	exit(EXIT_FAILURE);
}
