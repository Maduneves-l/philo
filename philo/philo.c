/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:12:26 by mneves-l          #+#    #+#             */
/*   Updated: 2024/03/02 22:30:43 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_fork  *start_forks(void)
{
    int i;
    t_fork  *fork;

    i = 0;
    fork = malloc(sizeof(t_fork) * data()->nb_philo);
    if(!fork)
    {
        free(data()->philo);
        return NULL;
    }
    while(i < data()->nb_philo)
    {
        fork[i].lock = 0;
        if(pthread_mutex_init(&fork[i].fork, NULL))
            return (NULL);
    }
    return(fork);

}

void    start_mutex(void)
{
    int     i;
    t_fork  *forks;

    forks = start_forks();
    i = 0;
    while(i < data()->nb_philo)
    {
        data()->philo[i].forks = forks;
        data()->philo[i].id = i + 1;
        data()->philo[i].last_meal = time();
        data()->philo[i].nb_meal = 0;
    }
    pthread_mutex_init(&data()->death, NULL);
    pthread_mutex_init(&data()->print, NULL);

}


void    init_data(char **av)
{
    data()->nb_philo = ft_atoi(av[1]);
    data()->time_to_die = ft_atoi(av[2]);
    data()->time_to_eat = ft_atoi(av[3]);
    data()->time_to_sleep = ft_atoi(av[4]);
    if(av[5])
        data()->max_meals = ft_atoi(av[5]);
    else    
        data()->max_meals = -1;
    if(data()->nb_philo < 1 || data()->nb_philo > 200)
        error("wrong number of philo", 0);
    data()->is_dead = 0;
    data()->philo = malloc(sizeof(t_philo) * data()->nb_philo);
    if (!data()->philo)
        return(NULL);
    start_mutex();
}

void    work(void)
{
    int     i;
    i = -1;

    while(++i < data()->nb_philo)
    {
        if(pthread_create(&data()->philo[i].thread, NULL, &daily, &data()->philo[i]))
            error("Error: thread create", 1);
    }
    i = -1;
    while(++i < data()->nb_philo)
    {
        if(pthread_join(data()->philo[i].thread, NULL))
            error("Error: thread join", 1);
    }
}

