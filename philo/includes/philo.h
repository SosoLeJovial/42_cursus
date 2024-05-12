/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:32:26 by tsofien-          #+#    #+#             */
/*   Updated: 2024/05/12 19:30:28 by tsofien-         ###   ########.fr       */
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
	THINKING = 0,
	EATING = 1,
	SLEEPING = 2,
}	STATE;

typedef struct s_fork
{
	bool	taken;
	int		position;
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
	int			nb_philo;
	t_fork		*fork;
	t_philo		*philo;
	pthread_t 	*philos;
	size_t		eat;
	size_t		die;
	size_t		sleep;

} t_env;

void*	routine();

/* Config */
t_env	*init_table(t_env *table, char **av);
t_fork	*init_fork(t_fork *fork, size_t size);
t_philo	*init_philo(t_philo *philo, t_fork *fork, size_t size);

/* Parsing */
int			ft_isdigit(int c);
int			ft_atoi(const char *nptr);
size_t		ft_strlen(const char *s);
int			ft_check_args(int ac, char**av);

/* Utils */
void	ft_msg(int fd, char *msg);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);

#endif