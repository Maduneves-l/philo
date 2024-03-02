/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:21:03 by mneves-l          #+#    #+#             */
/*   Updated: 2024/03/02 21:51:27 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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