/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:16:24 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/29 20:21:47 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void*	ft_realloc(void *ptr, size_t size)
{
	void	*new_data;

	if (!size)
		return (NULL);
	if (!ptr)
		return (malloc(size));
	new_data = malloc(size);
	if (!new_data)
		return (NULL);
	ft_memcpy(new_data, ptr, size);
	free(ptr);
	return (new_data);
}
