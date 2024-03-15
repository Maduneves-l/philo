/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:12:26 by mneves-l          #+#    #+#             */
/*   Updated: 2024/03/15 20:51:05 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo    *start_philo(t_data *data, t_philo *philo)
{
    int i;

    i = -1;

    philo = malloc(sizeof(t_philo) * data->nb_philo);
    if(!philo)
        error("Error: malloc", 0, NULL);
    data->start_time = ft_time();
    philo->data = data;
    while(++i < data->nb_philo)
    {
        philo[i].id = i;
        philo[i].x_eat = 0;
        philo[i].last_meal = ft_time();
        philo[i].data = data;   
        philo[i].lock = 0;  
    }
    return (philo);
}
        
void    start_mutex(t_data *data)
{
    int     i;

    i = -1;
    data->forks = malloc(sizeof(t_data) * data->nb_philo);
    if(!data->forks)
        error("Error: malloc", 0, NULL);
    while(++i < data->nb_philo)
    {
        if(pthread_mutex_init(&data->forks[i], NULL))
            error("Error: mutex init", 0, NULL);
      
    }
    if(pthread_mutex_init(&data->death, NULL))
        error("Error: mutex init", 0, NULL);
    if(pthread_mutex_init(&data->print, NULL))
        error("Error: mutex init", 0, NULL);
}


t_philo    *init_data(t_data *data, char **av)
{
    t_philo *philo;
    
    philo = 0;
    data->nb_philo = ft_atoi(av[1]);
    data->time_to_die = ft_atoi(av[2]);
    data->time_to_eat = ft_atoi(av[3]);
    data->time_to_sleep = ft_atoi(av[4]);
    data->is_dead = 0;
    if(av[5])
        data->max_meals = ft_atoi(av[5]);
    else    
        data->max_meals = -1;
    if(data->nb_philo < 1 || data->nb_philo > 200)
        error("wrong number of philo", 0, NULL);
    start_mutex(data);
    philo = start_philo(data, philo);
    data->philo = philo;
    return (philo);
}

void    work(t_data *data, t_philo *philo)
{
    int     i;
    i = -1;

    while(++i < data->nb_philo)
    {
        if(pthread_create(&(philo[i].thread), NULL, daily, (philo + i)))
            error("Error: thread create", 1, data);
    }
    i = -1;
    while(++i < data->nb_philo)
    {
        if(pthread_join(philo[i].thread, NULL))
            error("Error: thread join", 1, data);
    }
    exit_program(data, philo);
}

