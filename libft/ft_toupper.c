/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:41:30 by tsofien-          #+#    #+#             */
/*   Updated: 2023/11/20 01:16:38 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

char	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c -= 32);
	return (c);
}
int	main(void)
{
	int i = 0;

	while (i < 0x100)
	{
		if (ft_toupper(i) != toupper(i))
	    {
	        printf("Error at %d\n", i);
			printf("ft_toupper: %c\n", ft_toupper(i));
			printf("toupper: %c\n", toupper(i));
	    }
	    i++;
    }
	return (0);
}
