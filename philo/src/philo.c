/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:33:46 by tsofien-          #+#    #+#             */
/*   Updated: 2024/05/03 20:56:17 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>


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


int main(void)
{
	bool lock;

	lock = true;
	pthread *thread;
	return (0);
}