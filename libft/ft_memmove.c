/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:25:34 by tsofien-          #+#    #+#             */
/*   Updated: 2023/11/14 09:23:14 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*source;
	unsigned char	tmp;

	dst = (unsigned char *) dest;
	source = (unsigned char *) src;
	if (!src)
		return (dst);
		
	else
	{
		while (n--)
		{
			tmp = *source++;
			*dst++ = tmp;
		}
	}
	return ((void *) dest);
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