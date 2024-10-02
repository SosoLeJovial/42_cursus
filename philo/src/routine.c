/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:10:26 by tsofien-          #+#    #+#             */
/*   Updated: 2024/10/02 06:08:47 by tsofien-         ###   ########.fr       */
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
	int				position;

	i = 0;
	pthread_mutex_lock(&philo->philo_mut);
	position = philo->position;
	pthread_mutex_unlock(&philo->philo_mut);
	update_last_meal(philo, start);
	while (i++ != iter && !philo->dead)
	{
		if (!eating(philo, start, position))
			return (-1);
		philo_msg(SLEEP, get_current_time() - start, position, philo);
		update_state_philo(philo, EATING);
		custom_wait(philo->data->sleep);
	}
	return (1);
}

bool	take_fork(t_philo *philo, long long start, int position)
{
	if (position % 2)
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
	philo_msg(FORK, get_current_time() - start, position, philo);
	philo_msg(FORK, get_current_time() - start, position, philo);
	return (true);
}

void	put_down_fork(t_philo *philo, int position)
{
	if (position % 2)
	{
		pthread_mutex_lock(&philo->left_f->mut_fork);
		philo->left_f->taken = false;
		pthread_mutex_unlock(&philo->left_f->mut_fork);
		pthread_mutex_lock(&philo->right_f->mut_fork);
		philo->right_f->taken = false;
		pthread_mutex_unlock(&philo->right_f->mut_fork);
	}
	else
	{
		pthread_mutex_lock(&philo->right_f->mut_fork);
		philo->right_f->taken = false;
		pthread_mutex_unlock(&philo->right_f->mut_fork);
		pthread_mutex_lock(&philo->left_f->mut_fork);
		philo->left_f->taken = false;
		pthread_mutex_unlock(&philo->left_f->mut_fork);
	}
	update_philo_fork(philo, false);
}

bool	eating(t_philo *philo, long long start, int position)
{
	while (!philo->fork)
	{
		if (check_death(philo->table))
			break ;
		if (!take_fork(philo, start, position))
		{
			if (check_death(philo->table))
				return (false);
			if (philo->state != THINKING)
			{
				update_state_philo(philo, THINKING);
				philo_msg(THINK, get_current_time() - start, position, philo);
			}
			usleep(100);
			continue ;
		}
	}
	philo_msg(EAT, get_current_time() - start, position, philo);
	update_state_philo(philo, THINKING);
	custom_wait(philo->data->eat);
	update_last_meal(philo, get_current_time());
	put_down_fork(philo, position);
	update_philo_fork(philo, false);
	return (true);
}
