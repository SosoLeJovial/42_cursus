/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 10:11:39 by tsofien-          #+#    #+#             */
/*   Updated: 2024/10/03 03:46:52 by tsofien-         ###   ########.fr       */
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

void	end_sim(t_table **table, t_philo *philo, int j)
{
	int	i;

	pthread_mutex_lock(&(*table)->sim);
	(*table)->start = false;
	(*table)->sim_over = true;
	pthread_mutex_unlock(&(*table)->sim);
	i = j;
	while 	(i >= 0)
	{
		pthread_join(philo[i].thread, NULL);
		i--;
	}
}

void	start_sim(t_table **table)
{
	pthread_mutex_lock(&(*table)->print);
	(*table)->print_sim = true;
	pthread_mutex_unlock(&(*table)->print);
	pthread_mutex_lock(&(*table)->sim);
	(*table)->start = true;
	pthread_mutex_unlock(&(*table)->sim);	
}
