/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:01:51 by tsofien-          #+#    #+#             */
/*   Updated: 2024/10/02 17:45:55 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_last_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(&philo->meal);
}

bool	check_dead(t_table *table)
{
	long time;
	int i;

	while (1)
	{
		i = 0;
		while (i < table->nb_of_philo)
		{
			time = get_current_time();
			pthread_mutex_lock(&table->philo[i]->meal);
			printf("time: %ld\n", time - table->philo[i]->last_meal);
			if (table->philo[i]->last_meal && time - table->philo[i]->last_meal > table->time_to_die)
			{
				philo_msg(DEAD, time - table->philo[i]->last_meal, \
					table->philo[i]->id, table->philo[i]);
				pthread_mutex_unlock(&table->philo[i]->meal);
				return (true);
			}
			pthread_mutex_unlock(&table->philo[i]->meal);
			i++;
		}
		if (get_current_time() - table->start_time > 3000)
		{
			return (true);
		}	
	}
	return (false);
}
