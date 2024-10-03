/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:01:51 by tsofien-          #+#    #+#             */
/*   Updated: 2024/10/03 02:55:08 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_last_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(&philo->meal);
}

bool	check_dead(t_table *table, t_philo *philo)
{
	long time;
	int i;

	while (1)
	{
		i = 0;
		while (i < table->nb_of_philo)
		{
			time = get_current_time();
			pthread_mutex_lock(&philo[i].meal);
			if (philo[i].last_meal && time - philo[i].last_meal > table->time_to_die)
			{
				table->start = false;
				table->sim_over = false;
				philo_msg(DEAD, time - table->start_time, philo[i].id, &philo[i]);
				pthread_mutex_unlock(&philo[i].meal);
				return (true);
			}
			pthread_mutex_unlock(&philo[i].meal);
			i++;
			usleep(100);
		}
		if (get_current_time() - table->start_time > 3000)
		{
			return (true);
		}	
	}
	return (false);
}
