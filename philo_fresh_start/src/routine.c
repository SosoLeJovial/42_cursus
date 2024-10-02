/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:42:34 by tsofien-          #+#    #+#             */
/*   Updated: 2024/10/02 18:53:44 by tsofien-         ###   ########.fr       */
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
	while (!philo->table->start)
		usleep(500);
	start = get_current_time();	
	eat_sleep_routine(philo, start, id);
	return (NULL);
}

static void	eat_sleep_routine(t_philo *philo, long start, int id)
{
	printf("Simulation begin %d!\n", philo->table->sim_over);
	while (philo->table->sim_over == false)
	{
		philo_msg(EATING, get_current_time() - start, id, philo);
		custom_wait(philo->table->time_to_eat);
		update_last_meal(philo);
		philo_msg(SLEEPING, get_current_time() - start, id, philo);
		custom_wait(philo->table->time_to_sleep);
	}
	printf("Simulation over %d!\n", philo->table->sim_over);
	return ;
}
