/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:54:45 by tsofien-          #+#    #+#             */
/*   Updated: 2024/05/13 00:20:35 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_env	*init_table(t_env *table, char **av)
{

	table = ft_calloc(sizeof(t_env), 1);
	if (!table)
		return (0);
	table->nb_philo = ft_atoi(av[1]);
	table->fork = ft_calloc(sizeof(t_fork), table->nb_philo);
	if (!table->fork)
		return (NULL);
	table->philo = ft_calloc(sizeof(t_philo), table->nb_philo);
	if (!table->philo)
		return (NULL);
	table->eat = (size_t)ft_atoi(av[2]);
	table->die = (size_t)ft_atoi(av[3]);
	table->sleep = (size_t)ft_atoi(av[4]);
	table->fork = init_fork(table->fork, table->nb_philo);
	table->philo = init_philo(table->philo, table->fork, table->nb_philo);
	return (table);
}

t_fork	*init_fork(t_fork *fork, size_t size)
{
	size_t	i;

	i = 0;
	while(i < size)
	{
		fork[i].taken = false;
		fork[i].position = i + 1;
		i++;
	}
	return (fork);
}

t_philo	*init_philo(t_philo *philo, t_fork *fork, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (pthread_create(&philo[i].philo, NULL, routine, NULL) != 0)
			return (ft_msg(2, "fail creating thread \n"), NULL);
		philo[i].position = i + 1;
		philo[i].left_f = &fork[i];
		philo[i].right_f = &fork[(i + 1) % size];
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (pthread_join(philo[i].philo, NULL) != 0)
			return (ft_msg(2, "fail creating thread \n"), NULL);
		i++;
	}
	return (philo);
}
