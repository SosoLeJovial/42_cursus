/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:01:51 by tsofien-          #+#    #+#             */
/*   Updated: 2024/10/03 19:18:58 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	waiting_all(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->table->thread_mut);
		if (philo->table->thread_init == 1)
		{
			pthread_mutex_unlock(&philo->table->thread_mut);
			return (true);
		}
		else if (philo->table->thread_init == -1)
			break ;
		pthread_mutex_unlock(&philo->table->thread_mut);
		usleep(50);
	}
	pthread_mutex_unlock(&philo->table->thread_mut);
	return (false);
}

void	update_last_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(&philo->meal);
}

void	update_state_philo(t_philo *philo, t_state state)
{
	pthread_mutex_lock(&philo->meal);
	philo->state = state;
	pthread_mutex_unlock(&philo->meal);
}

t_state	philo_state(t_philo *philo)
{
	t_state	ret;

	pthread_mutex_lock(&philo->meal);
	
	ret = philo->state;
	pthread_mutex_unlock(&philo->meal);
	return (ret);
}
