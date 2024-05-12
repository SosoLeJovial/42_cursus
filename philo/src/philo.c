/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:33:46 by tsofien-          #+#    #+#             */
/*   Updated: 2024/05/10 19:39:01 by tsofien-         ###   ########.fr       */
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
int sleep_time = 0;

void*	routine()
{
	sleep_time++;
	printf("sleep_tim : %d\n", sleep_time);
	printf("Hello world! I am thread\n");
	return (NULL);
}

t_env	*init_table(t_env *table, char **av)
{
	int	i;

	table = ft_calloc(sizeof(t_env), 1);
	if (!table)
		return (0);
	table->nb_philo = ft_atoi(av[1]);
	table->eat = (size_t)ft_atoi(av[2]);
	table->die = (size_t)ft_atoi(av[3]);
	table->sleep = (size_t)ft_atoi(av[4]);
	printf("nb_philo = %d\n eat = %ld\n die = %ld\n sleep = %ld\n", table->nb_philo, table->eat, table->die, table->sleep);
	table->philos = ft_calloc(sizeof(pthread_t), table->nb_philo);
	i = 0;
	while (i < table->nb_philo)
	{
		printf("philo n %d created :", i);
		if (pthread_create(&table->philos[i], NULL, routine, NULL) != 0)
			return (ft_msg(2, "fail creating thread \n"), NULL);
		if (pthread_join(table->philos[i], NULL) != 0)
			return (ft_msg(2, "fail creating thread \n"), NULL);
		i++;
	}
	return (table);
}

int main(int ac, char**av)
{
	t_env	*table;

	table = NULL;
	if (ac < 4 || !ft_check_args(ac, av))
		return (ft_msg(2, "Error args!\n"), 1);
	table = init_table(table, av);
	if (!table)
		return (ft_msg(2, "bullshit\n"),1);
	printf("Args okay\n");
	// free(&table);
	return (0);
}
