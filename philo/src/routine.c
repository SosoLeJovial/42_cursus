/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:10:26 by tsofien-          #+#    #+#             */
/*   Updated: 2024/08/23 22:35:34 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void*	routine(void *args)
{
	t_env		*env;
	long long	start;

	env = (t_env *)args;
	while (1)
	{
		pthread_mutex_lock(&env->start_mutex);
		if (env->start_flag == true)
		{
			pthread_mutex_unlock(&env->start_mutex);
			start = get_current_time();
			usleep(10000);
			printf("starting:\n");
			printf("time taken: %lld ms\n", get_current_time() - start);
			break ;
		}
		pthread_mutex_unlock(&env->start_mutex);
	}
	return (NULL);
}


