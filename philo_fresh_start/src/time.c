/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 06:29:47 by tsofien-          #+#    #+#             */
/*   Updated: 2024/10/03 22:47:11 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_current_time(void)
{
	struct timeval	tv;
	long			time;

	if (gettimeofday(&tv, NULL))
		return (ft_msg(2, "Error time!\n"), 1);
	time = tv.tv_sec * 1000LL + tv.tv_usec / 1000;
	return (time);
}

void	custom_wait(long time_in_ms)
{
	long	current_time;
	long	time_remaining;
	long	start;

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

void	ft_msg(int fd, char *msg)
{
	if (write(fd, msg, ft_strlen(msg)))
		return ;
}

void	philo_msg(t_state msg, long time, int id, t_philo *philo)
{
	pthread_mutex_lock(&philo->table->print);
	if (check_sim(philo) && msg != DEAD) 
	{
		pthread_mutex_unlock(&philo->table->print);
		return ;	
	}
	if (!philo->table->print_sim)
	{
		pthread_mutex_unlock(&philo->table->print);
		return ;
	}
	if (msg == DEAD)
		printf("%ld %d died\n", time, id);
	else if (msg == FORK)
		printf("%ld %d has taken a fork\n", time, id);
	else if (msg == EATING)
		printf("%ld %d is eating\n", time, id);
	else if (msg == SLEEPING)
		printf("%ld %d is sleeping\n", time, id);
	else if (msg == THINKING)
		printf("%ld %d is thinking\n", time, id);
	pthread_mutex_unlock(&philo->table->print);
}
