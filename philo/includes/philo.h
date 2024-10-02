/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:32:26 by tsofien-          #+#    #+#             */
/*   Updated: 2024/10/02 06:15:21 by tsofien-         ###   ########.fr       */
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

typedef struct s_table t_table;

typedef enum state
{
	START,
	THINKING,
	EATING,
	SLEEPING,
}	state;

typedef enum MSG
{
	DEAD,
	FORK,
	EAT,
	SLEEP,
	THINK,
}	MSG;

typedef struct s_env
{
	int				nb_philo;
	long long		eat;
	long long		die;
	long long		sleep;
	long long		think;
	int				iter;
}	t_env;

typedef struct s_fork
{
	int				position;
	bool			taken;
	pthread_mutex_t	mut_fork;
}	t_fork;

typedef struct s_philo
{
	int					position;
	long long			last_meal;
	bool				dead;
	bool				fork;
	state				state;
	t_table				*table;
	pthread_t			philo;
	t_fork				*left_f;
	t_fork				*right_f;
	t_env				*data;
	pthread_mutex_t		philo_mut;
}	t_philo;

typedef struct s_table
{
	int				nb_philo;
	t_philo			*philo;
	t_fork			*fork;
	bool			start_flag;
	bool			death;
	bool			print;
	long long		start_time;
	pthread_mutex_t	table_mut;
	pthread_mutex_t	print_mut;
	pthread_mutex_t	death_mut;
	pthread_mutex_t	start_mutex;
}	t_table;

/* Routine */
void		*routine(void	*args);
bool		take_fork(t_philo *philo, long long start, int position);
void		put_down_fork(t_philo *philo, int position);
int			loop_philo(int iter, t_philo *philo, long long start);
bool		check_philo_state(t_table *table, t_philo *philo, char **av);
bool		eating(t_philo *philo, long long start, int position);


/* Helpers */
void		update_state_philo(t_philo *philo, state philo_state);
void		update_last_meal(t_philo *philo, long long meal);
void		update_philo_fork(t_philo *philo, bool taken);


/* Routine utils */
void		philo_msg(MSG msg, long long time, int position, t_philo *philo);
void		custom_wait(long long time_in_ms);
int			check_death(t_table *table);
long long	get_current_time(void);
bool		check_last_meal(t_philo *philo, t_table *table, char **av);

/* Config */
t_table		*init_table(t_table *table, char **av);
t_fork		*init_fork(size_t size);
t_philo		*init_philo(t_fork *fork, size_t size, t_table *table, char **av);
int			init_env(t_env **env, char **av);
bool		detach_thread(t_philo *philo, size_t size);

/* Parsing */
int			ft_isdigit(int c);
int			ft_atoi(const char *nptr);
size_t		ft_strlen(const char *s);
int			ft_check_args(int ac, char**av);

/* Utils */
void		ft_msg(int fd, char *msg);
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_bzero(void *s, size_t n);
#endif