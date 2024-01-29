/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:36:49 by mneves-l          #+#    #+#             */
/*   Updated: 2024/01/29 13:28:15 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h> // pthread_create, pthread_join
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h> // gettimeofday
# include <unistd.h>

typedef struct s_data
{
	int		nb_philo;
	int		time_to_eat;
	int		time_to_die;
	int		time_to_sleep;
	int		ntimes_eat;

}			t_data;

//check_arg.c
int			check_arg(int ac, char **av);
int			check_max(char **av);
long int	ft_atoi(char *str);
int			check_int(char **av);
int			ft_isdigit(int c);

//error.c
void		error(void);

#endif