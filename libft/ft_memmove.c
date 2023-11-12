/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:25:34 by tsofien-          #+#    #+#             */
/*   Updated: 2023/11/12 20:39:41 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*source;

	dst = (unsigned char *) dest;
	source = (unsigned char *) src;
	if (!dest || !dest || !src)
		return (dst);
	else
	{
		while (n--)
			*dst++ = *source++;
	}
	return ((void *) dest);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char src[] = "tester mon cochon";
	char dest[sizeof(src)];
	
	ft_memmove(dest, src, sizeof(src));
	printf("%s", dest);
	return (0);
}*/