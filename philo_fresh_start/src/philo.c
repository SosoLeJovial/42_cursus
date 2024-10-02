/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 06:26:46 by tsofien-          #+#    #+#             */
/*   Updated: 2024/10/02 17:47:11 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	init_env(t_philo **philo, t_table **table, char **av, int *thread);
static bool	create_thread(t_table *table, t_philo *philo, int *thread);

int	main(int ac, char **av)
{
	t_table	*table;
	t_philo	*philo;
	int		nb_thread;

	table = NULL;
	philo = NULL;
	nb_thread = 0;
	if (ac < 5 || !ft_check_args(ac, av))
		return (ft_msg(2, "Error table!\n"), 1);
	if (!init_env(&philo, &table, av, &nb_thread))
		return (ft_msg(2, "Error init program!\n"), 1);
	start_sim(&table);
	while (!check_dead(table))
		;
	printf("reach mdrrr\n");
	end_sim(&table, philo, nb_thread - 1);
	free_table(&table);
	return (0);
}

static bool	init_env(t_philo **philo, t_table **table, char **av, int *thread)
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
	create_thread(*table, *philo, thread);
	return (true);
}

static bool	create_thread(t_table *table, t_philo *philo, int *thread)
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
			*thread = i;
			ret = false;
			break  ;
		}
		i++;
	}
	*thread = i;
	return (ret);
}
