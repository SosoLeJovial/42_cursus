/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soso <soso@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:43:04 by soso              #+#    #+#             */
/*   Updated: 2023/11/08 17:52:35 by soso             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int ft_memcmp(void *s1, void *s2, size_t n)
{
    unsigned char *str;
    unsigned char *str1;
    int i;
    str = (unsigned char *) s1;
    str1 = (unsigned char *) s2;
    i = 0;
    while (i < n)
    {
        if (str[i] != str1[i])
            return (str[i] - str1[i]);
        i++;
    }
    
    return (0);
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
    char s1[] = "ceci est un test";
    char s2[] = "ceci n'est pas un test";
    
    printf("%d", ft_memcmp(s1, s2, sizeof(s1)));
    printf("%d", ft_memcmp(s1, s2, sizeof(s1)));
    return (0);
}*/