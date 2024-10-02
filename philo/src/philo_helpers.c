/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 05:55:14 by tsofien-          #+#    #+#             */
/*   Updated: 2024/10/02 06:03:05 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_state_philo(t_philo *philo, state philo_state)
{
	pthread_mutex_lock(&philo->philo_mut);
	philo->state = philo_state;
	pthread_mutex_unlock(&philo->philo_mut);
}

void	update_last_meal(t_philo *philo, long long meal)
{
	pthread_mutex_lock(&philo->philo_mut);
	philo->last_meal = meal;
	pthread_mutex_unlock(&philo->philo_mut);
}

void	update_philo_fork(t_philo *philo, bool taken)
{
	pthread_mutex_lock(&philo->philo_mut);
	philo->fork = taken;
	pthread_mutex_unlock(&philo->philo_mut);
}
