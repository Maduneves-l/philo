/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:36:49 by mneves-l          #+#    #+#             */
/*   Updated: 2024/03/15 17:22:10 by mneves-l         ###   ########.fr       */
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

typedef struct s_forks
{
	int 	lock;
	pthread_mutex_t fork;
}				t_fork;

typedef struct s_philo
{
	int				id;
	int 			x_eat;
	int				nb_meal;
	int 			last_meal;
	pthread_t		thread;
	t_fork			*forks;
	
}					t_philo;

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
	t_philo			*philo;
}					t_data;



//main.c
t_data				*data(void);

//check_arg.c
int					check_arg(int ac, char **av);
int					check_max(char **av);
long int			ft_atoi(char *str);
int					check_int(char **av);
int					ft_isdigit(int c);

//utils.c
int    ft_time(void);
void    printer(const char *msg, t_philo *philo);
int    diff_time(void);
void    exit_program(void);
void				error(char *s, int flag);



//philo.c
void				init_data(char **av);
void    			start_mutex(void);
t_fork  			*start_forks(void);
void   				 work(void);

//eating.c
int     eating(t_philo *philo);
void    lock_fork(t_philo *philo, int side);
void    unlock_fork(int side);



//daily.c
void    *daily(void *philos);
int    lock_dead();
int     check_dead(t_philo *philo);
int     ft_sleep(int time);





#endif