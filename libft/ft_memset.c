/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:35:10 by tsofien-          #+#    #+#             */
/*   Updated: 2023/11/12 20:44:12 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	if (!str || !n)
		return (s);
	while (n--)
	{
		*str = (unsigned char)c;
		str++;
	}
	return ((void *) str);
}
/*
int	main()
{
	char s1[] = "et oui";
	char s2[] = "et oui";

	memset(s1, '.', 10);
	ft_memset(s2, '.', 2);
	printf("%s\n%s", s1, s2);
	return (0);
}*/
