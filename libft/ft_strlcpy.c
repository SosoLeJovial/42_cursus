/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:11:33 by soso              #+#    #+#             */
/*   Updated: 2023/11/14 14:59:04 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	i;

	if (!dst || !src)
		return (0);
	srcsize = ft_strlen(src);
	i = 0;
	if (dstsize != 0)
	{
		while (src[i] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srcsize);
}
	// char		*d;
	// const char	*s;
	// size_t		n;

	// d = dst;
	// s = src;
	// n = size;
	// if (n != 0)
	// {
	// 	while (--n != 0)
	// 	{
	// 		if (*s == '\0')
	// 			break ;
	// 		*d++ = *s++;
	// 	}
	// }
	// if (n == 0)
	// {
	// 	if (size != 0)
	// 		*d = '\0';
	// 	while (*s++)
	// 		;
	// }
	// return (s - src - 1);
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	dest[] = "1";
	char	src[] = " ok";
	
	ft_strlcpy(dest, src, sizeof(dest));
	printf("|%s|", dest);
}*/