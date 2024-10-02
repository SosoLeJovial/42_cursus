/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 06:45:57 by tsofien-          #+#    #+#             */
/*   Updated: 2024/10/02 15:59:55 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table	*init_table(char **av)
{
	t_table	*table;

	table = ft_calloc(sizeof(t_table), 1);
	if (!table)
		return (NULL);
	table->nb_of_philo = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	table->nb_of_meals = -1;
	if (av[5])
		table->nb_of_meals = ft_atoi(av[5]);
	table->sim_over = false;
	table->start = false;
	table->print_sim = true;
	table->forks = init_fork(table->nb_of_philo);
	if (!table->forks)
		return (free_table(&table), NULL);
	return (table);
}

bool	mutex_init(t_table *table)
{
	table->sim_mut = true;
	if (pthread_mutex_init(&table->sim, NULL))
		table->sim_mut = false;
	table->print_mut = true;
	if (pthread_mutex_init(&table->print, NULL))
		table->print_mut = false;
	if (!table->sim_mut || !table->print_mut)
		return (false);
	return (true);
}

t_philo	*init_philo(t_table *table, t_fork *fork)
{
	int		i;
	t_philo	*philo;

	philo = ft_calloc(table->nb_of_philo, sizeof(t_philo));
	if (!philo)
		return (NULL);
	i = 0;
	while (i < table->nb_of_philo)
	{
		philo[i].id = i + 1;
		philo[i].last_meal = 0;
		philo[i].state = START;
		philo[i].table = table;
		philo[i].right_fork = &fork[i];
		if (i == table->nb_of_philo - 1)
			philo[i].left_fork = &fork[0];
		else
			philo[i].left_fork = &fork[i + 1];
		philo[i].mut_meal = true;
		if (pthread_mutex_init(&philo[i].meal, NULL))
			philo[i].mut_meal = false;
		i++;
	}
	return (philo);
}

t_fork	*init_fork(int size)
{
	int		i;
	t_fork	*fork;

	fork = ft_calloc(size, sizeof(t_fork));
	if (!fork)
		return (NULL);
	i = 0;
	while (i < size)
	{
		fork[i].mut_init = true;
		if (pthread_mutex_init(&fork[i].mut_fork, NULL) != 0)
			fork->mut_init = false;
		fork[i].taken = false;
		fork[i].position = i + 1;
		i++;
	}
	return (fork);
}
