/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:33:46 by tsofien-          #+#    #+#             */
/*   Updated: 2024/05/12 23:59:39 by tsofien-         ###   ########.fr       */
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

int 					mails = 1;
pthread_mutex_t         mut;

void*	routine()
{
	pthread_mutex_lock(&mut);
	int i = -1;
	while (++i < 1000000)
		mails++;
	printf("count mails in routine: %d\n", mails);
	pthread_mutex_unlock(&mut);
	return (NULL);
}

int main(int ac, char**av)
{
	t_env	*table;
	struct timeval tv;

	pthread_mutex_init(&mut, NULL);
	gettimeofday(&tv, NULL);
	int time_exact =  tv.tv_sec + tv.tv_usec * 1000000;
	printf("time exact: %d\n", time_exact/1000);
    printf("Seconds since 1/1/1970: %lu\n",tv.tv_sec);
	table = NULL;
	if (ac < 5 || !ft_check_args(ac, av))
		return (ft_msg(2, "Error args!\n"), 1);
	table = init_table(table, av);
	if (!table)
		return (ft_msg(2, "bullshit\n"),1);
	free(table->philos);
	free(table);
	return (0);
}
