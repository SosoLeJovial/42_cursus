/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:32:26 by tsofien-          #+#    #+#             */
/*   Updated: 2024/09/27 23:26:58 by tsofien-         ###   ########.fr       */
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

typedef enum STATE
{
	THINKING,
	EATING,
	SLEEPING,
}	STATE;

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
	size_t			eat;
	size_t			die;
	size_t			sleep;
	size_t			think;
	int				iter;
}	t_env;

typedef struct s_fork
{
	int				position;
	pthread_mutex_t	mut_fork;
}	t_fork;

typedef struct s_philo
{
	int					position;
	long long			last_meal;
	bool				dead;
	t_table				*table;
	pthread_t			philo;
	t_fork				*left_f;
	t_fork				*right_f;
	t_env				*data;
}	t_philo;

typedef struct s_table
{
	int				nb_philo;
	t_philo			*philo;
	t_fork			*fork;
	bool			start_flag;
	bool			death;
	long long		start_time;
	pthread_mutex_t	table_mut;
	pthread_mutex_t	start_mutex;
}	t_table;

/* Routine */
void		*routine(void	*args);
bool		take_fork(t_philo *philo, long long start);
int			loop_philo(int iter, t_philo *philo, long long start);
bool		check_philo_state(t_table *table);


/* Routine utils */
void		philo_msg(MSG msg, long long time, int position);
void		custom_wait(long long time_in_ms);
int			check_death(t_table *table, t_philo *philo, long long start);
long long	get_current_time(void);

/* Config */
t_table		*init_table(t_table *table, char **av);
t_fork		*init_fork(size_t size);
t_philo		*init_philo(t_fork *fork, size_t size, t_table *table, char **av);
int			init_env(t_env **env, char **av);
bool		join_thread(t_philo *philo, size_t size);

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