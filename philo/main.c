/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:36:42 by mneves-l          #+#    #+#             */
/*   Updated: 2024/03/16 14:58:21 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	*philo;

	if (check_arg(ac, av))
		error("Invalid arguments", 0, NULL);
	philo = init_data(&data, av);
	if (!philo)
		return (0);
	if (data.nb_philo >= 1)
		work(&data, philo);
}
