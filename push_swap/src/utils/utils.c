/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:18:32 by tsofien-          #+#    #+#             */
/*   Updated: 2024/03/23 16:00:31 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

int ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isint(long number)
{
	int result;

	result = 0;
	if ((-2147483647) < number && number < 2147483647)
		return (result);
	else
		return (result += 1);
}

int strcontaindigit(char *str)
{
	int	i;
	int ct;

	i = 0;
	ct = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i++]))
			ct++;
	}
	return (ct);
}

int strcontainonedigit(char *nptr)
{
	int	i;

	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t' ||
		nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i])
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
			return (1);
		i++;
	}
	return (0);
}

int ft_checker_digit(char **argv)
{
	int	i;
	int	j;

	j = 1;
	while (argv[j])
	{
		i = -1;
		if (!*argv[j] || !strcontaindigit(argv[j]) || !strcontainonedigit(argv[j]))
			return (1);
		while (argv[j][++i] && argv[j][i] != '\0')
			{
					if (!ft_isdigit(argv[j][i]) && argv[j][i] != 32 && argv[j][i] != '-' && argv[j][i] != '+')
							return (1);
					if (argv[j][i] == '-' && !ft_isdigit(argv[j][i + 1]))
							return (1);
			}
			
		j++;
	}
	return (0);
}
