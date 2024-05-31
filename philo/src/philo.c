/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:33:46 by tsofien-          #+#    #+#             */
/*   Updated: 2024/05/30 18:59:35 by tsofien-         ###   ########.fr       */
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

int main(int ac, char**av)
{
	t_env	*table;
	struct timeval tv;
	long long time_exact;

	if (ac < 5 || !ft_check_args(ac, av))
		return (ft_msg(2, "Error args!\n"), 1);
	if (gettimeofday(&tv, NULL))
		return (ft_msg(2, "Error time!\n"), 1);
	time_exact = (long long)tv.tv_sec * 1000000LL + tv.tv_sec;
	printf("time exact: %lld\n", time_exact);
    printf("Seconds since 1/1/1970: %lld\n", time_exact);
	table = NULL;
	table = init_table(table, av);
	if (!table)
		return (ft_msg(2, "bullshit\n"), 1);
	free(table->philo);
	free(table->fork);
	free(table);
	return (0);
}
