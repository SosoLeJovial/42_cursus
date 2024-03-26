/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:18:32 by tsofien-          #+#    #+#             */
/*   Updated: 2024/03/26 19:56:02 by tsofien-         ###   ########.fr       */
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
	if ((number < -2147483647) || (number > 2147483647))
		return (1);
	return (0);
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

int	strcontainonedigit(char *c)
{
	int		i;

	i = 0;
	while (c[i] == ' ' || c[i] == '\n' || c[i] == '\t' || \
		c[i] == '\v' || c[i] == '\f' || c[i] == '\r')
		i++;
	if (c[i] == '-' || c[i] == '+')
		i++;
	while (c[i])
	{
		if (c[i] >= '0' && c[i] <= '9')
			return (1);
		i++;
	}
	return (0);
}

int	ft_checker_digit(char **s)
{
	int		i;
	int		j;

	j = 1;
	while (s[j])
	{
		i = -1;
		if (!*s[j] || !strcontaindigit(s[j]) || !strcontainonedigit(s[j]))
			return (1);
		while (s[j][++i] && s[j][i] != '\0')
		{
			if (!ft_isdigit(s[j][i]) && s[j][i] != 32 \
			&& s[j][i] != '-' && s[j][i] != '+')
				return (1);
			if (s[j][i] == '-' && !ft_isdigit(s[j][i + 1]))
				return (1);
		}
		j++;
	}
	return (0);
}
