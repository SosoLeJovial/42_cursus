/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:25:34 by tsofien-          #+#    #+#             */
/*   Updated: 2023/11/14 09:48:02 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*str;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	if (str2 < str)
	{
		while (n > 0)
		{
			str[n - 1] = str2[n - 1];
			n--;
		}
	}
	else
	{
		while (i < n)
		{
			str[i] = str2[i];
			i++;
		}
	}
	return (dest);
}
/*
int	main(void)
{
	char src[] = "tester mon cochon";
	char dest[17];
	char source[] = "tester mon cochon";
	char dst[17];
	
	memmove(dst, source, 19);
	ft_memmove(dest, src, 19);
	printf("mine : %s \noriginal : %s", dest, dst);
	return (0);
}*/