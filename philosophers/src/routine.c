/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:42:34 by tsofien-          #+#    #+#             */
/*   Updated: 2024/10/04 01:32:49 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;
	long	start;
	int		id;

	philo = (t_philo *)arg;
	id = philo->id;
	if (!waiting_all(philo))
		return (NULL);
	waiting_room(philo, &start);
	if (philo->id % 2 == 0)
		custom_wait(philo->table->time_to_eat / 2);
	eat_sleep_routine(philo, start, id);
	return (NULL);
}

void	eat_sleep_routine(t_philo *philo, long start, int id)
{
	update_last_meal(philo);
	while (!check_sim(philo) && philo->nb_of_meals != 0)
	{
		if (!is_eating(philo, id, start))
		{
			if (philo_state(philo) != THINKING)
			{
				philo_msg(THINKING, get_current_time() - start, id, philo);
				update_state_philo(philo, THINKING);
			}
			continue ;
		}
		if (philo->nb_of_meals > 0)
			philo->nb_of_meals--;
		philo_msg(SLEEPING, get_current_time() - start, id, philo);
		custom_wait(philo->table->time_to_sleep);
		update_state_philo(philo, THINKING);
		philo_msg(THINKING, get_current_time() - start, id, philo);
		usleep(500);
	}
}

bool	is_eating(t_philo *philo, int id, long start)
{
	if (id % 2)
	{
		if (!take_fork(philo, true))
			return (false);
		if (!take_fork(philo, false))
			return (put_down_fork(philo, true), false);
	}
	else
	{
		if (!take_fork(philo, false))
			return (false);
		if (!take_fork(philo, true))
			return (put_down_fork(philo, false), false);
	}
	philo_msg(FORK, get_current_time() - start, id, philo);
	philo_msg(FORK, get_current_time() - start, id, philo);
	philo_msg(EATING, get_current_time() - start, id, philo);
	custom_wait(philo->table->time_to_eat);
	put_down_fork(philo, true);
	put_down_fork(philo, false);
	update_last_meal(philo);
	return (true);
}

bool	take_fork(t_philo *philo, bool direction)
{
	if (direction)
	{
		pthread_mutex_lock(&philo->left_fork->mut_fork);
		if (philo->left_fork->taken)
			return (pthread_mutex_unlock(&philo->left_fork->mut_fork));
		philo->left_fork->taken = true;
		pthread_mutex_unlock(&philo->left_fork->mut_fork);
	}
	else
	{
		pthread_mutex_lock(&philo->right_fork->mut_fork);
		if (philo->right_fork->taken)
			return (pthread_mutex_unlock(&philo->right_fork->mut_fork));
		philo->right_fork->taken = true;
		pthread_mutex_unlock(&philo->right_fork->mut_fork);
	}
	return (true);
}

void	put_down_fork(t_philo *philo, bool direction)
{
	if (direction)
	{
		pthread_mutex_lock(&philo->left_fork->mut_fork);
		philo->left_fork->taken = false;
		pthread_mutex_unlock(&philo->left_fork->mut_fork);
	}
	else
	{
		pthread_mutex_lock(&philo->right_fork->mut_fork);
		philo->right_fork->taken = false;
		pthread_mutex_unlock(&philo->right_fork->mut_fork);
	}
}
