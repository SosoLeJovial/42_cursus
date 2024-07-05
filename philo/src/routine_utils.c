/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:58:49 by tsofien-          #+#    #+#             */
/*   Updated: 2024/07/03 20:59:38 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_msg(MSG msg, long time, int position)
{
	if (msg == DEAD)
		printf("%ld ms %d died\n", time, position);
	else if (msg == FORK)
		printf("%ld ms %d has taken a fork\n", time, position);
	else if (msg == EAT)
		printf("%ld ms %d is eating\n", time, position);
	else if (msg == SLEEP)
		printf("%ld ms %d is sleeping\n", time, position);
	else if (msg == THINK)
		printf("%ld ms %d is thinking\n", time, position);
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
