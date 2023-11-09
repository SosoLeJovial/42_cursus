/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soso <soso@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:52:53 by soso              #+#    #+#             */
/*   Updated: 2023/11/09 14:13:14 by soso             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    *ft_bzero(void *s, size_t n)
{
    unsigned char *str;
    
    str = (unsigned char *)s;
    while (n--)
    {
        *str = 48;
        str++;
    }
}

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
}