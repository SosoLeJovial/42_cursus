/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:43:04 by tsofien-          #+#    #+#             */
/*   Updated: 2023/11/12 20:27:08 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str;
	unsigned char	*str1;

	str = (unsigned char *) s1;
	str1 = (unsigned char *) s2;
	while (n--)
	{
		if (str != str1)
			return (*str - *str1);
		str++;
		str1++;
	}
	return (0);
}
/*
int main()
{
    char s1[] = "a";
    char s2[] = "a";
    
    printf("%d\n", memcmp(s1, s2, sizeof(s1)));
    printf("%d\n", ft_memcmp(s1, s2, sizeof(s1)));
    return (0);
}*/