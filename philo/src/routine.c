/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:10:26 by tsofien-          #+#    #+#             */
/*   Updated: 2024/05/30 22:40:14 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void*	routine(void	*args)
{
	t_env	*env;

	env = (t_env *)args;
	pthread_mutex_lock(&env->env);
	sleep(1);
	if (env->eat)
		printf("eat exist %ld\ndie: %ld\nsleep: %ld\n", env->eat, env->die, env->sleep);
	pthread_mutex_unlock(&env->env);
	printf("hello from routine\n");
	/* while no one died or number of iteration */
	// bool	alive;
	// int		iteration;

	// (void *)args;
	// iteration = 0;
	// alive = true;
	// while (alive == true || iteration < env->iter)
	// {
	// 	/* Eating */
	// 	/* Sleeping */
	// 	/* Thinking */
	// 	printf("nice shit\n");
	// 	break ;
	// }
	// printf("eat: %ld\n", args->eat);
	return (NULL);
}
