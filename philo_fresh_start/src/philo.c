/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 06:26:46 by tsofien-          #+#    #+#             */
/*   Updated: 2024/10/03 18:31:50 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	init_env(t_philo **philo, t_table **table, char **av);
static bool	create_thread(t_table *table, t_philo *philo);

int	main(int ac, char **av)
{
	t_table	*table;
	t_philo	*philo;

	table = NULL;
	philo = NULL;
	if (ac < 5 || !ft_check_args(ac, av))
		return (ft_msg(2, "Error table!\n"), 1);
	if (!init_env(&philo, &table, av))
		return (ft_msg(2, "Error init program!\n"), 1);
	start_sim(&table);
	check_dead(table, philo);
	end_sim(&table, philo, table->nb_of_philo - 1);
	free_table(&table);
	return (0);
}

static bool	init_env(t_philo **philo, t_table **table, char **av)
{
	*table = init_table(av);
	if (!*table)
		return (false);
	if (!mutex_init(*table))
		return (free(*table), false);
	*philo = init_philo(*table, (*table)->forks);
	if (!philo)
		return (free_table(table), false);
	(*table)->philo = philo;
	if (!create_thread(*table, *philo))
		return (free_table(table), false);
	return (true);
}

static bool	create_thread(t_table *table, t_philo *philo)
{
	int		i;
	bool	ret;

	i = 0;
	ret = true;
	while (i < table->nb_of_philo)
	{
		philo[i].thread_created = true;
		if (pthread_create(&philo[i].thread, NULL, routine, &philo[i]))
		{
			philo[i].thread_created = false;
			pthread_mutex_lock(&table->thread_mut);
			table->thread_init = -1;
			pthread_mutex_unlock(&table->thread_mut);
			return (ft_msg(2, "Error thread!\n"), end_sim(&table, philo, i - 1), false);
		}
		i++;
	}
	pthread_mutex_lock(&table->thread_mut);
	table->thread_init++;
	pthread_mutex_unlock(&table->thread_mut);
	return (ret);
}
