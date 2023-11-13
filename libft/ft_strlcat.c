/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:47:43 by tsofien-          #+#    #+#             */
/*   Updated: 2023/11/13 11:33:32 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_dst;

	i = 0;
	j = 0;
	len_dst = ft_strlen(dst);
	if (size == 0)
		return (ft_strlen((char *)src));
	while (dst[i] != '\0' && i < size)
		i++;
	while (i < size - 1)
		dst[i++] = src[j++];
	if (size != 0 && size >= len_dst)
		dst[i] = '\0';
	if (size < ft_strlen(dst))
		return (ft_strlen((char *)src) + size);
	else
		return (ft_strlen((char *)src) + len_dst);
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
}*/