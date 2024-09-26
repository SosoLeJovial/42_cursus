/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:10:26 by tsofien-          #+#    #+#             */
/*   Updated: 2024/09/26 04:41:37 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	take_fork(t_philo *philo);
static void	put_down_fork(t_philo *philo);

void*	routine(void *args)
{
	t_table			*table;
	int				iter;
	long long		start;

	iter = 0;
	table = (t_table *)args;
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
	printf("starting: %lld ms\n", get_current_time() -  start);
	while (1 && iter++ != table->philo->data->iter)
	{
		take_fork(table->philo);
		custom_wait(table->philo->data->eat);
		put_down_fork(table->philo);
		philo_msg(EAT, get_current_time() - start, table->philo->position);
	}
	return (NULL);
}

static void	take_fork(t_philo *philo)
{
	if (philo->position % 2)
	{
		if (pthread_mutex_lock(&philo->left_f->mut_fork) != 0)
			return ;
		philo->left_f->taken = true;
		if (pthread_mutex_unlock(&philo->left_f->mut_fork) != 0)
			return ;

		if (pthread_mutex_lock(&philo->right_f->mut_fork) != 0)
			return ;
		philo->right_f->taken = true;
		if (pthread_mutex_unlock(&philo->right_f->mut_fork) != 0)
			return ;
	}
	else
	{
		if (pthread_mutex_lock(&philo->right_f->mut_fork) != 0)
			return ;
		philo->right_f->taken = true;
		if (pthread_mutex_unlock(&philo->right_f->mut_fork) != 0)
			return ;
		if (pthread_mutex_lock(&philo->left_f->mut_fork) != 0)
			return ;
		philo->left_f->taken = true;
		if (pthread_mutex_unlock(&philo->left_f->mut_fork) != 0)
			return ;
	}
}

static void	put_down_fork(t_philo *philo)
{
	if (philo->position % 2)
	{
		if (pthread_mutex_lock(&philo->left_f->mut_fork) != 0)
			return ;
		philo->left_f->taken = false;
		if (pthread_mutex_unlock(&philo->left_f->mut_fork) != 0)
			return ;
		if (pthread_mutex_lock(&philo->right_f->mut_fork) != 0)
			return ;
		philo->right_f->taken = false;
		if (pthread_mutex_unlock(&philo->right_f->mut_fork) != 0)
			return ;
	}
	else
	{
		if (pthread_mutex_lock(&philo->right_f->mut_fork) != 0)
			return ;
		philo->right_f->taken = false;
		if (pthread_mutex_unlock(&philo->right_f->mut_fork) != 0)
			return ;
		if (pthread_mutex_lock(&philo->left_f->mut_fork) != 0)
			return ;
		philo->left_f->taken = false;
		if (pthread_mutex_unlock(&philo->left_f->mut_fork) != 0)
			return ;
	}
}

