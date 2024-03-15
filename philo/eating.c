/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:41:48 by mneves-l          #+#    #+#             */
/*   Updated: 2024/03/15 17:22:26 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int     eating(t_philo *philo)
{
    int f_left;
    int f_right;

    f_right = ((philo->id == 0) * (data()->nb_philo - 1) + (philo->id != 0) * (philo->id));    
    f_left = (philo->id - (philo->id != 0));

    lock_fork(philo, f_left);
    if(lock_dead())
        return 1;
    lock_fork(philo, f_right);
    if(lock_dead())
        return 1;
    printer("is eating", philo);
    philo->x_eat++;
    philo->last_meal = ft_time();

    ft_sleep(data()->time_to_eat);
    unlock_fork(f_left);
    unlock_fork(f_right);
    return 0;
    
}

void    lock_fork(t_philo *philo, int side)
{
    while(!check_dead(philo))
    {
        pthread_mutex_lock(&(data()->philo->forks[side].fork));
        if (!data()->philo[side].forks->lock)
        {

            data()->philo[side].forks->lock = 1;
            pthread_mutex_unlock(&(data()->philo->forks[side].fork));
            break ; 
        }
        else
            pthread_mutex_unlock(&(data()->philo->forks[side].fork));    
    }
    if(!lock_dead())
        printer("has taken a fork", philo);
}

void    unlock_fork(int side)
{
    pthread_mutex_lock(&(data()->philo->forks[side].fork));
	data()->philo[side].forks->lock = 0;
	pthread_mutex_unlock(&(data()->philo->forks[side].fork));
}
