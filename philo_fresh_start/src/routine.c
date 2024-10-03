/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:42:34 by tsofien-          #+#    #+#             */
/*   Updated: 2024/10/03 19:39:22 by tsofien-         ###   ########.fr       */
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
	start = get_current_time();
	pthread_mutex_lock(&philo->table->sim);
	philo->table->start_time = start;
	pthread_mutex_unlock(&philo->table->sim);
	// printf("Thread %d is rdy start at  %ld\n", philo->id, start);
	eat_sleep_routine(philo, start, id);
	return (NULL);
}

void	eat_sleep_routine(t_philo *philo, long start, int id)
{
	int	size;
	int	i;
	
	i = 0;
	size = philo->table->nb_of_meals;
	update_last_meal(philo);
	while (!check_sim(philo) && i++ != size)
	{
		if (!is_eating(philo, id, start))
		{
			if (philo_state(philo) != THINKING)
			{
				philo_msg(THINKING, get_current_time() - start, id, philo);
				update_state_philo(philo, THINKING);
			}
			usleep(50);
			continue ;
		}
		if (check_sim(philo)) 
			break ;
		philo_msg(SLEEPING, get_current_time() - start, id, philo);
		custom_wait(philo->table->time_to_sleep);
	}
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
		if (!take_fork(philo,false))
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
