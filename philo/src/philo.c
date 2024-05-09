/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:33:46 by tsofien-          #+#    #+#             */
/*   Updated: 2024/05/09 13:01:12 by tsofien-         ###   ########.fr       */
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

void*	routine(void*)
{
	printf("test thread\n");
	sleep(3);
	printf("ending thread\n");
	return (NULL);
}

int main(int ac, char**av)
{
	pthread_t	t1;
	pthread_t	t2;

	if (ac < 4 || !ft_check_args(ac, av))
		return (ft_msg(2, "Error args!\n"), 1);
	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
		return (ft_msg(2, "Error, fail thread!\n"), 1);
	if (pthread_create(&t2, NULL, &routine, NULL) != 0)
		return (ft_msg(2, "Error, fail thread!\n"), 1);
	if (pthread_join(t1, NULL) != 0)
		return (1);
	if (pthread_join(t2, NULL) != 0)
		return (1);
	printf("Args okay\n");
	return (0);
}
