/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:35:10 by tsofien-          #+#    #+#             */
/*   Updated: 2023/11/14 00:26:35 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	if (!str || !n)
		return ((void *)str);
	while (n--)
		*str++ = (unsigned char)c;
	return ((void *) str);
}
/*
int	main(void)
{
	char s1[] = "et oui";
	char s2[] = "et non";
	size_t n = 2;

	memset(s1, '.', n);
	ft_memset(s2, '.', n);
	printf("%s\n%s", s1, s2);
	return (0);
}*/
