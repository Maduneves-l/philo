/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 21:08:03 by mneves-l          #+#    #+#             */
/*   Updated: 2024/03/15 17:15:38 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int    ft_time(void)
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
    return((ft_time()) - data()->start_time);
}

void    exit_program(void)
{
    int i;

    i = -1;

    while(++i < data()->nb_philo)
        pthread_mutex_destroy(&data()->philo[i].forks->fork);
    pthread_mutex_destroy(&data()->print);
    pthread_mutex_destroy(&data()->death);
    free(data()->philo->forks);
    free(data()->philo);
    free(data());
}
void	error(char *s, int flag)
{
	if(flag == 1)
	{
		free(data()->philo->forks);
		free(data()->philo);
	}
	printf("Error: %s\n", s);
	exit(EXIT_FAILURE);
}
