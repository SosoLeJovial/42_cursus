/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:41:30 by tsofien-          #+#    #+#             */
/*   Updated: 2023/11/14 15:08:58 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

char	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	main(void)
{
	int i = 0;
 
        while (i < 0x100)
        {
                if (ft_toupper(i) != toupper(i))
                {
                        printf("Mine : %c | Originale : %c || a l'itération : %d\n",ft_toupper(i), toupper(i), i);
                }
                i++;
        }
}
