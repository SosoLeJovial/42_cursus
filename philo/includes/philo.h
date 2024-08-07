/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:32:26 by tsofien-          #+#    #+#             */
/*   Updated: 2024/07/03 16:33:07 by tsofien-         ###   ########.fr       */
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

typedef struct s_fork
{
	bool			taken;
	int				position;
	pthread_mutex_t	mut_fork;
}	t_fork;

typedef struct s_philo
{
	pthread_t	philo;
	int			position;
	t_fork		*left_f;
	t_fork		*right_f;
}	t_philo;


typedef struct s_env
{
	int				nb_philo;
	t_fork			*fork;
	t_philo			*philo;
	size_t			eat;
	size_t			die;
	size_t			sleep;
	size_t			iter;
	bool			start_flag;
	long long		start_time;
	pthread_mutex_t	env;
	pthread_mutex_t	start_mutex;
} t_env;

/* Routine */
void*		routine(void	*args);

/* Routine utils */
void		philo_msg(MSG msg, long time, int position);
long long	get_current_time(void);

/* Config */
t_env		*init_table(t_env *table, char **av);
t_fork		*init_fork(size_t size);
t_philo		*init_philo(t_fork *fork, size_t size, t_env *env);
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