/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daily.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 22:22:13 by mneves-l          #+#    #+#             */
/*   Updated: 2024/03/15 17:21:29 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *daily(void *philos)
{
    t_philo     *philo;
    philo = (t_philo *)philos;

    if(philo->id % 2)
        usleep(5000);
    while (!lock_dead())
    {
        if (eating(philo))
			return (NULL);
		if (philo->x_eat == data()->max_meals)
			break ;
		if (!lock_dead())
		{
			printer("is sleeping", philo);
			ft_sleep(data()->time_to_sleep);
		}
		if (! lock_dead())
			printer("is thinking", philo);
    }
    return NULL;
}

int    lock_dead()
{
    int death;
    
    pthread_mutex_lock(&(data()->death));
    death = data()->is_dead;
    pthread_mutex_unlock(&(data()->death));
    return (death);
}

int     check_dead(t_philo *philo)
{
    if(lock_dead())
        return 1;
    usleep(500);
    if(ft_time() - philo->last_meal > data()->time_to_die)
    {
        pthread_mutex_lock(&(data()->death));
        data()->is_dead++;
        if(data()->is_dead == 1)
            printer("died", philo);
        pthread_mutex_unlock(&(data()->death));
        return 1;
    }
    return 0;
}

int     ft_sleep(int time)
{
    int i;
    int j;

    i = ft_time();
    j = 0;

    while(!(lock_dead()) && j < time)
    {
        if(check_dead(data()->philo))
            return 1;
        usleep(100);
        j = ft_time() - i;
    }
    return (j >= time);
}