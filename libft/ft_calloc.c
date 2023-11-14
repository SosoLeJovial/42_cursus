/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:05:34 by tsofien-          #+#    #+#             */
/*   Updated: 2023/11/14 11:20:28 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = (void *) malloc(nmemb * size);
	if (nmemb == 0 || size == 0)
		return (NULL);
	if (ptr == 0)
		return (NULL);
	else
		return (ptr);
}