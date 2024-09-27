/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:33:46 by tsofien-          #+#    #+#             */
/*   Updated: 2024/09/27 23:23:18 by tsofien-         ###   ########.fr       */
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

	if (ac < 5 || !ft_check_args(ac, av))
		return (ft_msg(2, "Error args!\n"), 1);
	table = NULL;
	table = init_table(table, av);
	if (!table)
		return (ft_msg(2, "Init table fail\n"), 1);
	table->philo = init_philo(table->fork, table->nb_philo, table, av);
	if (!table->philo)
		return (1);
	pthread_mutex_lock(&table->start_mutex);
	table->start_flag = true;
	pthread_mutex_unlock(&table->start_mutex);
	if (!join_thread(table->philo, table->nb_philo))
		return (1);
	check_philo_state(table);
	free(table->philo);
	free(table->fork);
	free(table);
	return (0);
}
