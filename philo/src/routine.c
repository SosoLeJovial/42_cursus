/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:10:26 by tsofien-          #+#    #+#             */
/*   Updated: 2024/10/01 13:32:27 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void*	routine(void *args)
{
	t_table			*table;
	t_philo			*philo;
	long long		start;

	philo = (t_philo *)args;
	table = philo->table;
	while (1)
	{
		pthread_mutex_lock(&table->start_mutex);
		if (table->start_flag == true)
		{
			start = get_current_time();
			table->start_time = start;
			pthread_mutex_unlock(&table->start_mutex);
			break ;
		}
		pthread_mutex_unlock(&table->start_mutex);
	}
	loop_philo(philo->data->iter, philo, start);
	pthread_mutex_lock(&table->start_mutex);
	table->start_flag = false;
	pthread_mutex_unlock(&table->start_mutex);
	return (NULL);
}

int	loop_philo(int iter, t_philo *philo, long long start)
{
	int				i;

	i = 0;
	philo->last_meal = start;
	while (i++ != iter && !philo->dead)
	{
		if (!eating(philo, start))
			return (printf("YEN A UN QUI EST MORT PEEPOSAD\n"), -1);
		philo_msg(SLEEP, get_current_time() - start, philo->position, philo);
		philo->state = SLEEPING;
		custom_wait(philo->data->sleep);
	}
	return (1);
}

bool	take_fork(t_philo *philo, long long start)
{
	if (philo->position % 2)
	{
		pthread_mutex_lock(&philo->left_f->mut_fork);
		if (philo->left_f->taken)
			return (pthread_mutex_unlock(&philo->left_f->mut_fork), false);
		philo->left_f->taken = true;
		pthread_mutex_unlock(&philo->left_f->mut_fork);
		pthread_mutex_lock(&philo->right_f->mut_fork);
		if (philo->right_f->taken)
			return (pthread_mutex_unlock(&philo->right_f->mut_fork), false);
		philo->right_f->taken = true;
		pthread_mutex_unlock(&philo->right_f->mut_fork);
	}
	else
	{
		pthread_mutex_lock(&philo->right_f->mut_fork);
		if (philo->right_f->taken)
			return (pthread_mutex_unlock(&philo->right_f->mut_fork), false);
		philo->right_f ->taken = true;
		pthread_mutex_unlock(&philo->right_f->mut_fork);
		pthread_mutex_lock(&philo->left_f->mut_fork);
		if (philo->left_f->taken)
			return (pthread_mutex_unlock(&philo->left_f->mut_fork), false);
		philo->left_f->taken = true;
		pthread_mutex_unlock(&philo->left_f->mut_fork);
	}
	philo->fork = true;
	philo_msg(FORK, get_current_time() - start, philo->position, philo);
	philo_msg(FORK, get_current_time() - start, philo->position, philo);
	return (true);
}

void	put_down_fork(t_philo *philo)
{
		pthread_mutex_lock(&philo->left_f->mut_fork);
		printf("put down left\n");
		philo->left_f->taken = false;
		pthread_mutex_unlock(&philo->left_f->mut_fork);
		pthread_mutex_lock(&philo->right_f->mut_fork);
		printf("put down right\n");
		philo->right_f->taken = false;
		pthread_mutex_unlock(&philo->right_f->mut_fork);
	philo->fork = false;	
}

bool		eating(t_philo *philo, long long start)
{
	while (!philo->fork)
	{
		if (!take_fork(philo, start))
		{
			if (check_death(philo->table))
				return (false);
			if (philo->state != THINKING)
			{
				philo->state = THINKING;
				philo_msg(THINK, get_current_time() - start, philo->position, philo);
			}
			usleep(100);
			continue ;
		}
	}
	philo_msg(EAT, get_current_time() - start, philo->position, philo);
	philo->state = EATING;
	custom_wait(philo->data->eat);
	philo->last_meal = get_current_time();
	put_down_fork(philo);
	philo->fork = false;
	return (true);
}
