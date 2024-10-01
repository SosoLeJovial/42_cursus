/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:58:49 by tsofien-          #+#    #+#             */
/*   Updated: 2024/10/01 13:06:20 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_msg(MSG msg, long long time, int position, t_philo *philo)
{
	(void)philo;
	pthread_mutex_lock(&philo->table->print_mut);
	if (philo->table->death)
	{
		pthread_mutex_unlock(&philo->table->print_mut);
		return ;
	}
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
	pthread_mutex_unlock(&philo->table->print_mut);
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
			usleep(500);
	}
}

int			check_death(t_table *table)
{
	bool	death;

	death = false;
	pthread_mutex_lock(&table->table_mut);
	if (table->death)
		death = true;
	pthread_mutex_unlock(&table->table_mut);
	return (death);
}
