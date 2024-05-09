/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:32:26 by tsofien-          #+#    #+#             */
/*   Updated: 2024/05/09 13:09:07 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>

typedef enum STATE
{
	THINKING = 0,
	EATING = 1,
	SLEEPING = 2,
}	STATE;

typedef struct s_env
{
	int		nb_philo;
	char**	fork;
} t_env;

/* Parsing */
int	ft_isdigit(int c);
int	ft_atoi(const char *nptr);
size_t	ft_strlen(const char *s);
int	ft_check_args(int ac, char**av);


/* Utils */
void	ft_msg(int fd, char *msg);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);

#endif