/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:18:32 by tsofien-          #+#    #+#             */
/*   Updated: 2024/03/26 15:31:49 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isint(long number)
{
	int	result;

	result = 0;
	if ((-2147483647) < number && number < 2147483647)
		return (result);
	else
		return (result += 1);
}

int	strcontaindigit(char *str)
{
	int	i;
	int	ct;

	i = 0;
	ct = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i++]))
			ct++;
	}
	return (ct);
}

int	strcontainonedigit(char *nptr)
{
	int		i;
	char	c;

	i = 0;
	c = nptr[i];
	while (c == ' ' || c == '\n' || c == '\t' || \
		c == '\v' || c == '\f' || c == '\r')
		i++;
	if (c == '-' || c == '+')
		i++;
	while (c)
	{
		if (c >= '0' && c <= '9')
			return (1);
		i++;
	}
	return (0);
}

int	ft_checker_digit(char **argv)
{
	int		i;
	int		j;
	char	*str;

	j = 1;
	str = argv[j];
	while (str)
	{
		i = -1;
		if (!*str || !strcontaindigit(str) || !strcontainonedigit(str))
			return (1);
		while (str[++i] && str[i] != '\0')
		{
			if (!ft_isdigit(str[i]) && str[i] != 32 \
			&& str[i] != '-' && str[i] != '+')
				return (1);
			if (str[i] == '-' && !ft_isdigit(str[i + 1]))
				return (1);
		}
		j++;
	}
	return (0);
}
