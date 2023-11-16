/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:55:49 by tsofien-          #+#    #+#             */
/*   Updated: 2023/11/16 19:43:44 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_count_int(int n)
{
	int	char_count;

	char_count = 0;
	if (n < 0)
	{
		n *= -1;
		char_count++;
	}
	while ((n % 10) != 0)
		char_count++;
	return (char_count);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len_result;
	int		i;

	len_result = ft_count_int(n);
	result = malloc(sizeof(char) * (len_result + 1));
	if (!result)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		result[i] = '-';
		n *= -1;
		i++;
	}
	while (len_result > 0)
	{
		result[i] = (n % 10) + '0';
		len_result--;
		i++;
	}
	return (result);
}
/*
int	main(void)
{
	printf("%s \n", ft_itoa(atoi("123")));
	return(0);
}
*/
