/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:30:59 by tsofien-          #+#    #+#             */
/*   Updated: 2023/11/27 23:31:42 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

int	ft_atoi(const char *nptr)
{
	int		i;
	int		s;
	long	res;

	i = 0;
	s = 1;
	res = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t' || \
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

// int	main(void)
// {
// 	printf("%d | %d", ft_atoi("-922223372036854775807"), 
// atoi("-922223372036854775807"));
// 	return (0);
// }