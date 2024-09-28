/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:58:49 by tsofien-          #+#    #+#             */
/*   Updated: 2024/09/28 06:01:39 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_msg(MSG msg, long long time, int position)
{
	if (msg == DEAD)
		printf("%lld %d died\n", time, position);
	else if (msg == FORK)
		printf("%lld %d has taken a fork\n", time, position);
	else if (msg == EAT)
		printf("%lld %d is eating\n", time, position);
	else if (msg == SLEEP)
		printf("%lld %d is sleeping\n", time, position);
	else if (msg == THINK)
		printf("%lld %d is thinking\n", time, position);
}

long long	get_current_time(void)
{
	struct timeval	tv;
	long long		time;

	if (gettimeofday(&tv, NULL))
		return (ft_msg(2, "Error time!\n"), 1);
	time = tv.tv_sec * 1000LL + tv.tv_usec / 1000;
	return (time);
}

void	custom_wait(long long time_in_ms)
{
	long long current_time;
	long long time_remaining;
	long long start;

	start = get_current_time();
	while (1)
	{
		current_time = get_current_time();
		time_remaining = time_in_ms - (current_time - start);
		if ((current_time - start) >= time_in_ms)
			break ;
		if (time_remaining > 10)
			usleep(5000);
		else
			usleep(100);
	}
}

int	check_death(t_table *table, t_philo *philo, long long start)
{
	bool	death;

	death = false;
	if ((get_current_time() - philo->last_meal) > (long long)philo->data->die)
	{
		philo_msg(DEAD, get_current_time() - start, philo->position);
		death = true;
	}
	if (pthread_mutex_lock(&table->table_mut) != 0)
		return (-1);
	if (table->death)
		death = true;
	if (pthread_mutex_unlock(&table->table_mut) != 0)
		return (-1);
	return (death);
}

bool	check_philo_state(t_table *table)
{
	int	i;

	while (!table->death && table->start_flag)
	{
		i = 0;
		while (i < table->nb_philo)
		{
			pthread_mutex_lock(&table->table_mut);
			if (table->philo->dead)
			{
				table->death = true;
				pthread_mutex_unlock(&table->table_mut);
				break ;
			}
			pthread_mutex_unlock(&table->table_mut);
			i++;
		}
		if (!table->death)
			continue ;
		else
			return (false);
	}
	return (true);
}	 
