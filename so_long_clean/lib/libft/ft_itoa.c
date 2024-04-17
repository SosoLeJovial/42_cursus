/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:55:49 by tsofien-          #+#    #+#             */
/*   Updated: 2023/11/22 13:02:08 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static size_t	ft_count_digits(long int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	if (n == 0)
		i++;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return ((size_t) i);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	long int	num;

	num = n;
	i = ft_count_digits(num);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	while (i >= 0 && str[i] != '-')
	{
		str[i] = (num % 10) + '0';
		num /= 10;
		i--;
	}
	return (str);
}
/*
int	main(void)
{
	char	*str;

	str = ft_itoa(0);
	if (!str)
		return (1);
	printf("%s \n", str);
	free(str);
	return (0);
}
*/
