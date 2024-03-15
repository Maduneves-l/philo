/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:36:49 by mneves-l          #+#    #+#             */
/*   Updated: 2024/03/15 20:53:13 by mneves-l         ###   ########.fr       */
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
	int				nb_philo;
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	int				max_meals;
	int				start_time;
	int 			is_dead;
	pthread_mutex_t death;
	pthread_mutex_t print;
	pthread_mutex_t	*forks;
	t_philo			*philo;
}					t_data;

typedef struct s_philo
{
	int				id;
	int 			x_eat;
	int 			last_meal;
	pthread_t		thread;
	int 			lock;
	t_data 			*data;
}					t_philo;


//check_arg.c
int					check_arg(int ac, char **av);
int					check_max(char **av);
long int			ft_atoi(char *str);
int					check_int(char **av);
int					ft_isdigit(int c);

//utils.c
int    ft_time(void);
void    printer(const char *msg, long long time, t_philo *philo, t_data *data);
int    diff_time(long long a, long long b);
void    exit_program(t_data *data, t_philo *philo);
void				error(char *s, int flag, t_data *data);



//philo.c
t_philo    *start_philo(t_data *data, t_philo *philo);
void    start_mutex(t_data *data);
t_philo    *init_data(t_data *data, char **av);
void    work(t_data *data, t_philo *philo);



//eating.c
int     eating(t_philo *philo, t_data *data);

void    lock_fork(t_philo *philo, t_data *data, int side);

void    unlock_fork(t_philo *philo, t_data *data, int side);




//daily.c
void    *daily(void *philos);
int    lock_dead(t_data *data);
int     check_dead(t_philo *philo, t_data *data);
int     ft_sleep(int time, t_data *data);






#endif