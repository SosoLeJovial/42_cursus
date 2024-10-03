/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:32:26 by tsofien-          #+#    #+#             */
/*   Updated: 2024/10/03 19:18:01 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>

typedef struct s_table	t_table;

typedef enum state
{
	START,
	DEAD,
	FORK,
	THINKING,
	EATING,
	SLEEPING,
}	t_state;

typedef struct s_fork
{
	int				position;
	bool			taken;
	bool			mut_init;
	pthread_mutex_t	mut_fork;
}	t_fork;

typedef struct s_philo
{
	int				id;
	long			last_meal;
	bool			mut_meal;
	bool			thread_created;
	t_fork			*right_fork;
	t_fork			*left_fork;
	t_state			state;
	t_table			*table;
	pthread_t		thread;
	pthread_mutex_t	meal;
}	t_philo;

typedef struct s_table
{
	int				thread_init;
	int				nb_of_philo;
	int				nb_of_meals;
	long			start_time;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	bool			sim_over;
	bool			print_sim;
	bool			start;
	bool			print_mut;
	bool			sim_mut;
	bool			thread_bool;
	t_philo			**philo;
	t_fork			*forks;
	pthread_mutex_t	thread_mut;
	pthread_mutex_t	print;
	pthread_mutex_t	sim;
}	t_table;

/* Config */
bool				mutex_init(t_table *table);
t_table				*init_table(char **av);
t_fork				*init_fork(int size);
t_philo				*init_philo(t_table *table, t_fork *fork);

/* Monitor */
void				start_sim(t_table **table);
void				end_sim(t_table **table, t_philo *philo, int j);
bool				check_sim(t_philo *philo);
bool				check_dead(t_table *table, t_philo *philo);

/* Routine */
void				*routine(void *philo);
void				eat_sleep_routine(t_philo *philo, long start, int id);
bool				take_fork(t_philo *philo, bool direction);
bool				is_eating(t_philo *philo, int id, long start);

/* Routine Utils */
bool				waiting_all(t_philo *philo);
void				update_last_meal(t_philo *philo);
void				update_state_philo(t_philo *philo, t_state state);
t_state				philo_state(t_philo *philo);

/* Time */
void				custom_wait(long time_in_ms);
long				get_current_time(void);
void				philo_msg(t_state msg, long time, int id, t_philo *philo);

/* Free */
void				free_fork(t_fork *fork, t_table *table);
void				free_philo(t_philo **philo);
void				free_table(t_table **table);

/* Parsing */
int					ft_isdigit(int c);
int					ft_atoi(const char *nptr);
int					ft_check_args(int ac, char**av);
size_t				ft_strlen(const char *s);

/* Utils */
void				ft_msg(int fd, char *msg);
void				*ft_calloc(size_t nmemb, size_t size);
void				ft_bzero(void *s, size_t n);
#endif