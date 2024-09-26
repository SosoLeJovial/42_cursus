/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:44:30 by tsofien-          #+#    #+#             */
/*   Updated: 2024/09/26 01:15:38 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	free_all(t_philo *philo, t_fork *fork, t_table)
{
	int	i;

	i = 0;
	while ((philo[i])
	{
		if (philo)
		{
			if (philo[i]->left_f)
				pthread_mutex_destroy(philo->left_f)
		}
		i++;
	}
}
