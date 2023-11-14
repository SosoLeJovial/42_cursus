/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:43:04 by tsofien-          #+#    #+#             */
/*   Updated: 2023/11/14 09:37:18 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str;
	unsigned char	*str1;
	size_t			i;

	str = (unsigned char *) s1;
	str1 = (unsigned char *) s2;
	i = 0;
	while (n-- && str[i] && str1[i])
	{
		if (str[i] != str1[i])
			return (str[i] - str1[i]);
		i++;
	}
	return (0);
}
/*
#include <string.h>
int main()
{
    char s1[] = "Coucoo";
    char s2[] = "Coucou";
    
    printf("%d\n", memcmp(s1, s2, 0));
    printf("%d\n", ft_memcmp(s1, s2, 0));
    return (0);
}
*/