/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:18:32 by tsofien-          #+#    #+#             */
/*   Updated: 2024/02/29 16:21:09 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

int ft_atoi(const char *nptr)
{
	int i;
	int s;
	long res;

	i = 0;
	s = 1;
	res = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t' ||
		   nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (res != ((res * 10) + nptr[i] - '0') / 10)
			return ((s + 1) / 2 / -1);
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	return (res * s);
}
int ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

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