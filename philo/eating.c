/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:41:48 by mneves-l          #+#    #+#             */
/*   Updated: 2024/03/15 20:54:50 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int     eating(t_philo *philo, t_data *data)
{
    int f_left;
    int f_right;

    f_right = ((philo->id == 0) * (philo->data->nb_philo - 1) + (philo->id != 0) * (philo->id));    
    f_left = (philo->id - (philo->id != 0));

    lock_fork(philo,data, f_left);
    if(lock_dead(data))
        return 1;
    lock_fork(philo, data, f_right);
    if(lock_dead(data))
        return 1;
    printer("is eating", data->start_time,  philo, data);
    philo->x_eat++;
    philo->last_meal = ft_time();

    ft_sleep(data->time_to_eat, data);
    unlock_fork(philo, data, f_left);
    unlock_fork(philo, data, f_right);
    return 0;
    
}

void    lock_fork(t_philo *philo, t_data *data, int side)
{
    while(!check_dead(philo, data))
    {
        pthread_mutex_lock(&philo->data->forks[side]);
        if (!data->philo[side]->lock)
        {
            data->philo[side]->lock= 1;
            pthread_mutex_unlock(&philo->data->forks[side]);
            break ; 
        }
        else
            pthread_mutex_unlock(&philo->data->forks[side]);    
    }
    if(!lock_dead(data))
        printer("has taken a fork", data->start_time, philo, data);
}

void    unlock_fork(t_philo *philo, t_data *data, int side)
{
    pthread_mutex_lock(&philo->data->forks[side]);
	data->philo[side].lock = 0;
	pthread_mutex_unlock(&philo->data->forks[side]);
}
