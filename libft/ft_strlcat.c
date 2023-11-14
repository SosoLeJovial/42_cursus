/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:47:43 by tsofien-          #+#    #+#             */
/*   Updated: 2023/11/14 14:58:45 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	c;
	size_t	d;

	if (dstsize <= (unsigned long)ft_strlen(dst))
		return (dstsize + (unsigned long)ft_strlen(src));
	c = (unsigned long) ft_strlen(dst);
	d = 0;
	while (src[d] != '\0' && c + 1 < dstsize)
	{
		dst[c] = src[d];
		c++;
		d++;
	}
	dst[c] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[d]));
}
/*
int	main(void)
{
	char dst[20] = "cool";
	char src[] = "lel";
	char dest[20] = "cool";
	char sorc[] = "lel";

	strlcat(dst, src, 20);
	ft_strlcat(dest, sorc, 20);
	printf("%s | %s\n", dst, dest);
}
*/
