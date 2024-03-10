/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daily.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 22:22:13 by mneves-l          #+#    #+#             */
/*   Updated: 2024/03/10 19:59:45 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *daily(void *philos)
{
    t_philo     *philo;
    philo = (t_philo *)philos;

    if(philo->id % 2)
        usleep(5000);
    while (!check_death())
    {
        
    }
}

int    check_dead()
{
    int death;
    
    pthread_mutex_lock(&(data()->death));
    death = data()->is_dead;
    pthread_mutex_unlock(&(data()->death));
    return (death);
}