/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:10:26 by tsofien-          #+#    #+#             */
/*   Updated: 2024/07/03 21:00:50 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void*	routine(void *args)
{
	t_env	*env;

	env = (t_env *)args;
	while (1)
	{
		pthread_mutex_lock(&env->start_mutex);
		if (env->start_flag == true)
		{
			pthread_mutex_unlock(&env->start_mutex);
			printf("starting\n");
			break ;
		}
		pthread_mutex_unlock(&env->start_mutex);
	}
	return (NULL);
}


