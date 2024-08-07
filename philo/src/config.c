/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:54:45 by tsofien-          #+#    #+#             */
/*   Updated: 2024/07/03 16:38:43 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_env	*init_table(t_env *table, char **av)
{
	table = ft_calloc(sizeof(t_env), 1);
	if (!table)
		return (0);
	pthread_mutex_init(&table->env, NULL);
	pthread_mutex_init(&table->start_mutex, NULL);
	table->start_flag = false;
	table->start_time = 0;
	table->nb_philo = ft_atoi(av[1]);
	table->fork = init_fork(table->nb_philo);
	if (!table->fork)
		return (NULL);
	table->eat = (size_t)ft_atoi(av[2]);
	table->die = (size_t)ft_atoi(av[3]);
	table->sleep = (size_t)ft_atoi(av[4]);
	if (av[5])
		table->iter = (size_t)ft_atoi(av[5]);
	return (table);
}

t_fork	*init_fork(size_t size)
{
	size_t	i;
	t_fork	*fork;

	fork = ft_calloc(size, sizeof(t_fork));
	if (!fork)
		return (NULL);
	i = 0;
	while(i < size)
	{
		fork[i].taken = false;
		pthread_mutex_init(&fork[i].mut_fork, NULL);
		fork[i].position = i + 1;
		i++;
	}
	return (fork);
}

t_philo	*init_philo(t_fork *fork, size_t size, t_env *env)
{
	size_t		i;
	t_philo 	*philo;

	philo = ft_calloc(size, sizeof(t_philo));
	if (!philo)
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (pthread_create(&philo[i].philo, NULL, routine, env) != 0)
			return (ft_msg(2, "fail creating thread \n"), NULL);
		philo[i].position = i + 1;
		philo[i].left_f = &fork[i];
		philo[i].right_f = &fork[(i + 1) % size];
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
