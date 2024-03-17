/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:18:32 by tsofien-          #+#    #+#             */
/*   Updated: 2024/03/17 21:32:07 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

int ft_atoi(const char *nptr)
{
	int i;
	int s;
	int res;

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
			return (2147483648);
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

	result = 0;
	if (ft_isint(number) != 0)
		return (result += 1);
	else
		return (result);
}

int	ft_isint(int number)
{
	int result;

	result = 0;
	if ((-2147483647) < number && number < 2147483647)
		return (result);
	else
		return (result += 1);
}

void ft_free_args(char **tab)
{
	int	i;

	i = 1;
	while (tab[i])
		i++;
	while (i > 0)
		free(tab[--i]);
	free(tab);
}
