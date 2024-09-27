/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:10:26 by tsofien-          #+#    #+#             */
/*   Updated: 2024/09/27 23:52:06 by tsofien-         ###   ########.fr       */
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
			pthread_mutex_unlock(&table->start_mutex);
			break ;
		}
		pthread_mutex_unlock(&table->start_mutex);
	}
	start = get_current_time();
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
	while (i++ < iter)
	{
		if (take_fork(philo, start) != 0)
			return (-1);
		philo_msg(SLEEP, get_current_time() - start, philo->position);
		custom_wait(philo->data->sleep);
		philo_msg(THINK, get_current_time() - start, philo->position);
		custom_wait(philo->data->think);
		if (check_death(philo->table, philo, start))
			break ;
	}
	if (check_death(philo->table, philo, start))
	{
		pthread_mutex_lock(&philo->table->start_mutex);
		philo->table->start_flag = false;
		pthread_mutex_unlock(&philo->table->start_mutex);
	}
	return (1);
}

bool	take_fork(t_philo *philo, long long start)
{
	if (philo->position % 2)
	{
		if (pthread_mutex_lock(&philo->left_f->mut_fork) != 0)
			return (false);
		if (pthread_mutex_lock(&philo->right_f->mut_fork) != 0)
			return (false);
		philo_msg(FORK, get_current_time() - start, philo->position);
		philo_msg(FORK, get_current_time() - start, philo->position);
		philo_msg(EAT, get_current_time() - start, philo->position);
		custom_wait(philo->data->eat);
		if (pthread_mutex_unlock(&philo->left_f->mut_fork) != 0)
			return (false);
		if (pthread_mutex_unlock(&philo->right_f->mut_fork) != 0)
			return (false);
	}
	else
	{
		if (pthread_mutex_lock(&philo->right_f->mut_fork) != 0)
			return (false);
		if (pthread_mutex_lock(&philo->left_f->mut_fork) != 0)
			return (false);
		philo_msg(FORK, get_current_time() - start, philo->position);
		philo_msg(FORK, get_current_time() - start, philo->position);
		philo_msg(EAT, get_current_time() - start, philo->position);
		custom_wait(philo->data->eat);
		if (pthread_mutex_unlock(&philo->right_f->mut_fork) != 0)
			return (false);
		if (pthread_mutex_unlock(&philo->left_f->mut_fork) != 0)
			return (false);
	}
	philo->last_meal = get_current_time();
	return (true);
}
