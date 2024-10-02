/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:33:46 by tsofien-          #+#    #+#             */
/*   Updated: 2024/10/02 06:15:33 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* 
	Debunk :
	Thread = a logical sequence of instructions inside a process
	⚠️ each thread got its own context, ID, stack, instruction 
	pointer, processor register !
	Mutex = offer possibilty to handle access from a common resource 
	https://stackoverflow.com/questions/34524/what-is-a-mutex 
	😆 incredible description
	Command for checking threads while executing : valgrind tool=helgrind
 */

int	main(int ac, char **av)
{
	t_table		*table;
	t_philo		*philo;

	if (ac < 5 || !ft_check_args(ac, av))
		return (ft_msg(2, "Error args!\n"), 1);
	table = NULL;
	table = init_table(table, av);
	if (!table)
		return (ft_msg(2, "Init table fail\n"), 1);
	philo = init_philo(table->fork, table->nb_philo, table, av);
	if (!philo)
		return (1);
	pthread_mutex_lock(&table->start_mutex);
	table->start_flag = true;
	pthread_mutex_unlock(&table->start_mutex);
	if (!detach_thread(philo, table->nb_philo))
		return (1);
	check_philo_state(table, philo, av);
	free(philo);
	free(table->fork);
	free(table);
	return (0);
}

bool	check_philo_state(t_table *table, t_philo *philo, char **av)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < table->nb_philo)
		{
			if (check_last_meal(&philo[i], table, av))
			{
				pthread_mutex_lock(&table->table_mut);
				table->death = true;
				pthread_mutex_unlock(&table->table_mut);
				pthread_mutex_lock(&table->print_mut);
				table->print = false;
				pthread_mutex_unlock(&table->print_mut);
			}
			else
			{
				break ;
				i++;
				continue ;
			}
		}
	}
	return (false);
}	 
bool	check_last_meal(t_philo *philo, t_table *table, char **av)
{
	long long	meal;
	long long	start;

	pthread_mutex_lock(&philo->philo_mut);
	meal = philo->last_meal;
	pthread_mutex_unlock(&philo->philo_mut);
	pthread_mutex_lock(&table->start_mutex);
	start = table->start_time;
	pthread_mutex_unlock(&table->start_mutex);
	if (meal - start > ft_atoi(av[3]))
		return (true);
	return (false);
}
