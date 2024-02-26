/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 13:24:35 by tsofien-          #+#    #+#             */
/*   Updated: 2024/02/26 18:56:38 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_sanitize(int number)
{
	int	result;

	result = -1;
	if (ft_isdigit(number) == 0 && ft_isint(number) == 1)
		result = 1;
	else
		return (0);
	return (result);
}

int	ft_isint(int number)
{
	int result;

	result = -1;
	if ((-2147483647) < number && number < 2147483647)
		result = 1;
	else
		result = 0;
	return (result);
}
