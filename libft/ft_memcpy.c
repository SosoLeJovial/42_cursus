/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:10:55 by tsofien-          #+#    #+#             */
/*   Updated: 2023/11/12 20:34:00 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*sorc;
	unsigned char	*dst;

	sorc = (unsigned char *) src;
	dst = (unsigned char *) dest;
	while (n--)
	{
		dst = sorc;
		dst++;
		sorc++;
	}
	return (dst);
}
