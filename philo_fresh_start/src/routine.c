/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:42:34 by tsofien-          #+#    #+#             */
/*   Updated: 2024/10/02 17:47:26 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eat_sleep_routine(t_philo *philo, long start, int id);

void	*routine(void *arg)
{
	t_philo	*philo;
	long	start;
	int		id;

	philo = (t_philo *)arg;
	id = philo->id;
	while (1)
	{
		pthread_mutex_lock(&philo->table->sim);
		if (philo->table->start)
		{
			update_last_meal(philo);
			pthread_mutex_unlock(&philo->table->sim);
			break ;
		}
		pthread_mutex_unlock(&philo->table->sim);
		usleep(100);
	}
	start = get_current_time();	
	eat_sleep_routine(philo, start, id);
	printf("Simulation over!\n");
	return (NULL);
}

static void	eat_sleep_routine(t_philo *philo, long start, int id)
{
	while (1)
	{
		philo_msg(EATING, get_current_time() - start, id, philo);
		custom_wait(philo->table->time_to_eat);
		update_last_meal(philo);
		philo_msg(SLEEPING, get_current_time() - start, id, philo);
		custom_wait(philo->table->time_to_sleep);
		if (get_current_time() - start > 3000)
			break ;
	}
	return ;
}
