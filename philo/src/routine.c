/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:10:26 by tsofien-          #+#    #+#             */
/*   Updated: 2024/09/16 23:15:25 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	take_fork(t_philo *philo);
static void	put_down_fork(t_philo *philo);

void*	routine(void *args)
{
	t_table			*table;
	size_t			iter;
	long long		start;

	iter = 0;
	table = (t_table *)args;
	while (1 || iter++ < table->philo->data->iter)
	{
		pthread_mutex_lock(&table->start_mutex);
		if (table->start_flag == true)
		{
			pthread_mutex_unlock(&table->start_mutex);
			start = get_current_time();
			printf("starting: %lld ms\n", get_current_time() -  start);
			take_fork(table->philo);
			put_down_fork(table->philo);
			break ;
		}
		pthread_mutex_unlock(&table->start_mutex);
	}
	return (NULL);
}

static void	take_fork(t_philo *philo)
{
	if (philo->position % 2)
	{
		if (pthread_mutex_lock(&philo->left_f->mut_fork) != 0)
			return ;
		if (pthread_mutex_lock(&philo->right_f->mut_fork) != 0)
			return ;
	}
	else
	{
		if (pthread_mutex_lock(&philo->right_f->mut_fork) != 0)
			return ;
		if (pthread_mutex_lock(&philo->left_f->mut_fork) != 0)
			return ;
	}
}

static void	put_down_fork(t_philo *philo)
{
	if (philo->position % 2)
	{
		if (pthread_mutex_unlock(&philo->left_f->mut_fork) != 0)
			return ;
		if (pthread_mutex_unlock(&philo->right_f->mut_fork) != 0)
			return ;
	}
	else
	{
		if (pthread_mutex_unlock(&philo->right_f->mut_fork) != 0)
			return ;
		if (pthread_mutex_unlock(&philo->left_f->mut_fork) != 0)
			return ;
	}
}

