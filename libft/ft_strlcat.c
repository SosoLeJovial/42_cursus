/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:47:43 by tsofien-          #+#    #+#             */
/*   Updated: 2023/11/14 10:59:48 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	size_t	len_dst;
	size_t	src_len;

	len_dst = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (len_dst == size)
		return (size + src_len);
	if (src_len < (size - len_dst))
	{
		ft_memcpy((dst + len_dst), src, (src_len + 1));
	}
	else
	{
		ft_memcpy(dst + len_dst, src, (size - (len_dst - 1)));
		dst[size - 1] = '\0';
	}
	return (len_dst + src_len);
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