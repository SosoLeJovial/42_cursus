/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:52:53 by soso              #+#    #+#             */
/*   Updated: 2023/11/11 21:35:59 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
	{
		*str = 0;
		str++;
	}
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
    char s1[] = "true story";
    char s2[] = "love story";

    ft_bzero(s1, 3);
    bzero(s2, sizeof(s2));

    printf("%s\n%s", s1, s2);
    return (0);
}*/