/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:54:45 by tsofien-          #+#    #+#             */
/*   Updated: 2024/09/27 23:43:18 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table *init_table(t_table *table, char **av)
{
	table = ft_calloc(sizeof(t_table), 1);
	if (!table)
		return (0);
	table->start_flag = false;
	table->death = false;
	table->start_time = 0;
	table->nb_philo = ft_atoi(av[1]);
	table->fork = init_fork(table->nb_philo);
	if (!table->fork)
		return (NULL);
	pthread_mutex_init(&table->start_mutex, NULL);
	pthread_mutex_init(&table->table_mut, NULL);
	return (table);
}

t_fork *init_fork(size_t size)
{
	size_t	i;
	t_fork	*fork;

	fork = ft_calloc(size, sizeof(t_fork));
	if (!fork)
		return (NULL);
	i = 0;
	while(i < size)
	{
		if (pthread_mutex_init(&fork[i].mut_fork, NULL) != 0)
			return (NULL);
		fork[i].position = i + 1;
		i++;
	}
	return (fork);
}

int	init_env(t_env **env, char **av)
{
	*env = ft_calloc(sizeof(t_env), 1);
	if (!*env)
		return (0);
	(*env)->nb_philo = ft_atoi(av[1]);
	(*env)->eat = (size_t) ft_atoi(av[2]);
	(*env)->die = (size_t) ft_atoi(av[2]);
	(*env)->sleep = (size_t) ft_atoi(av[3]);
	(*env)->think = (size_t) ft_atoi(av[4]);
	(*env)->iter = -1;
	if (av[5])
		(*env)->iter = ft_atoi(av[5]);
	return (1);
}

t_philo	*init_philo(t_fork *fork, size_t size, t_table *table, char **av)
{
	size_t		i;
	t_philo 	*philo;

	philo = ft_calloc(size, sizeof(t_philo));
	if (!philo)
		return (NULL);
	i = 0;
	while (i < size)
	{
		philo[i].dead = false;
		philo[i].last_meal = 0;
		philo[i].table = table;
		philo[i].position = i + 1;
		philo[i].left_f = &fork[i];
		philo[i].right_f = &fork[(i + 1) % size];
		philo[i].right_f = &fork[(i + 1) % size];
		if (!init_env(&(philo[i].data), av))
			return (ft_msg(2, "fail creating philo's env \n"), NULL);
		if (pthread_create(&philo[i].philo, NULL, routine, &philo[i]) != 0)
			return (ft_msg(2, "fail creating thread \n"), NULL);
		i++;
	}
	return (philo);
}

bool	join_thread(t_philo *philo, size_t size)
{
	size_t		i;

	i = 0;
	while (i < size)
	{
		if (pthread_join(philo[i].philo, NULL) != 0)
			return (ft_msg(2, "fail joining thread\n"), false);
		i++;
	}
	return (true);
}
