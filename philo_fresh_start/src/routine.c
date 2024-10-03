/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:42:34 by tsofien-          #+#    #+#             */
/*   Updated: 2024/10/03 03:43:13 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eat_sleep_routine(t_philo *philo, long start, int id);
static void	update_thread_init(t_philo *philo);
bool	waiting_all(t_philo *philo);

void	*routine(void *arg)
{
	t_philo	*philo;
	long	start;
	int		id;

	philo = (t_philo *)arg;
	id = philo->id;
	// update_thread_init(philo);
	if (!waiting_all(philo))
		return (NULL);
	printf("Thread %d is rdy\n", philo->id);
	start = get_current_time();	
	eat_sleep_routine(philo, start, id);
	return (NULL);
}

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

static void	update_thread_init(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal);
	philo->table->thread_init++;
	pthread_mutex_unlock(&philo->meal);
}

static void	eat_sleep_routine(t_philo *philo, long start, int id)
{
	int	size;
	int	i;
	
	i = 0;
	size = philo->table->nb_of_meals;
	while (!check_sim(philo) && i++ != size)
	{
		philo_msg(EATING, get_current_time() - start, id, philo);
		custom_wait(philo->table->time_to_eat);
		update_last_meal(philo);
		philo_msg(SLEEPING, get_current_time() - start, id, philo);
		custom_wait(philo->table->time_to_sleep);
	}
}

bool	check_sim(t_philo *philo)
{
	bool	ret;

	ret = false;
	pthread_mutex_lock(&philo->table->sim);
	if (philo->table->sim_over)
		ret = true;
	pthread_mutex_unlock(&philo->table->sim);
	return (ret);
}

bool	take_fork_left(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork->mut_fork);
	if (philo->left_fork->taken)
		return (pthread_mutex_unlock(&philo->left_fork->mut_fork));
	philo->left_fork->taken = true;
	pthread_mutex_unlock(&philo->left_fork->mut_fork);
	return (true);
}
