/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:11:33 by soso              #+#    #+#             */
/*   Updated: 2023/11/12 20:27:40 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		n;

	d = dst;
	s = src;
	n = size;
	if (n != 0)
	{
		while (--n != 0)
		{
			if (*s == '\0')
				break ;
			*d++ = *s++;
		}
	}
	if (n == 0)
	{
		if (size != 0)
			*d = '\0';
		while (*s++)
			;
	}
	return (s - src - 1);
}
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