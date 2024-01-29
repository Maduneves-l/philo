/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:46:09 by mneves-l          #+#    #+#             */
/*   Updated: 2024/01/29 13:26:31 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (1);
	if (check_int(av))
		return (1);
	if (check_max(av))
		return (1);
	return (0);
}

int	check_max(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_atoi(av[i]) > INT_MAX)
			return (1);
		i++;
	}
	return (0);
}

long int	ft_atoi(char *str)
{
	int			i;
	int			sign;
	long int	res;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return (res * sign);
}

int	check_int(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
