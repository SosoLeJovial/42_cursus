/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:13:04 by tsofien-          #+#    #+#             */
/*   Updated: 2024/10/03 19:38:17 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_sim(t_table **table)
{
	pthread_mutex_lock(&(*table)->print);
	(*table)->print_sim = true;
	pthread_mutex_unlock(&(*table)->print);
	pthread_mutex_lock(&(*table)->sim);
	(*table)->start = true;
	pthread_mutex_unlock(&(*table)->sim);	
}

bool	check_dead(t_table *table, t_philo *philo)
{
	long time;
	int i;

	while (1)
	{
		i = 0;
		while (i < table->nb_of_philo)
		{
			time = get_current_time();
			pthread_mutex_lock(&philo[i].meal);
			if (philo[i].last_meal && time - philo[i].last_meal > table->time_to_die)
			{
				table->start = false;
				table->sim_over = false;
				philo_msg(DEAD, time - table->start_time, philo[i].id, &philo[i]);
				pthread_mutex_unlock(&philo[i].meal);
				return (true);
			}
			pthread_mutex_unlock(&philo[i].meal);
			i++;
		}
	}
	return (false);
}

bool	check_sim(t_philo *philo)
{
	bool	ret;

	ret = false;
	pthread_mutex_lock(&philo->table->sim);
	if (philo->table->sim_over)
		ret = true;
	pthread_mutex_unlock(&philo->table->sim);
	return (ret);
}

void	end_sim(t_table **table, t_philo *philo, int j)
{
	int	i;

	pthread_mutex_lock(&(*table)->sim);
	(*table)->start = false;
	(*table)->sim_over = true;
	pthread_mutex_unlock(&(*table)->sim);
	i = j;
	while 	(i >= 0)
	{
		pthread_join(philo[i].thread, NULL);
		i--;
	}
}
