/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soso <soso@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:35:10 by tsofien-          #+#    #+#             */
/*   Updated: 2023/11/08 16:41:48 by soso             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memchr(void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	chr;
	size_t	i;

	chr = (unsigned char) c;
	str = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (str[i] == chr)
			return (void *)(str + i);
		i++;
	}
	return (0);
}
/*
int main()
{
    char s[] = "Aticleworld";
    char *ptr = ft_memchr(s, 99 ,sizeof(s));
    if (ptr != NULL)
    {
        printf ("'c' found at position %ld.\n", ptr-s+1);
        printf ("search character found:  %s\n", ptr);
    }
    else
    {
        printf ("search character not found\n");
    }
    return 0;
}
*/