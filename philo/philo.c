/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:12:26 by mneves-l          #+#    #+#             */
/*   Updated: 2024/02/19 20:19:29 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    init_forks(t_data *data)
{
//=(
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
        error("wrong number of philo");
    data()->philo = malloc(sizeof(t_philo) * data()->nb_philo);
    if (!data()->philo)
        return(NULL);

}

