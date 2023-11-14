/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:43:04 by tsofien-          #+#    #+#             */
/*   Updated: 2023/11/14 09:55:23 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n - 1 && str[i] == str2[i])
		i++;
	return (str[i] - str2[i]);
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
