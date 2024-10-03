/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 10:11:39 by tsofien-          #+#    #+#             */
/*   Updated: 2024/10/04 01:27:01 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_table(t_table **table)
{
	if ((*table)->sim_mut)
		pthread_mutex_destroy(&(*table)->sim);
	if ((*table)->print_mut)
		pthread_mutex_destroy(&(*table)->print);
	if ((*table)->thread_bool)
		pthread_mutex_destroy(&(*table)->thread_mut);
	if ((*table)->philo)
		free_philo((*table)->philo);
	if ((*table)->forks)
		free_fork((*table)->forks, *table);
	if (*table)
		free(*table);
}

void	free_philo(t_philo **philo)
{
	int	i;

	i = 0;
	while (i < (*philo)->table->nb_of_philo)
	{
		if ((*philo)[i].mut_meal)
			pthread_mutex_destroy(&(*philo)[i].meal);
		i++;
	}
	free(*philo);
}

void	free_fork(t_fork *fork, t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_of_philo)
	{
		if (fork[i].mut_init)
			pthread_mutex_destroy(&fork[i].mut_fork);
		i++;
	}
	free(fork);
}
