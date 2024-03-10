/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 21:08:03 by mneves-l          #+#    #+#             */
/*   Updated: 2024/03/10 19:39:55 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int    time(void)
{
    struct timeval      time;

    gettimeofday(&time, NULL);
    return((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void    printer(const char *msg, t_philo *philo)
{
    pthread_mutex_lock(&data()->print);
    printf("%d %d %s\n", diff_time(), philo->id, msg);
    pthread_mutex_unlock(&data()->print);
}

int    diff_time(void)
{
    return((time()) - data()->start_time);
}