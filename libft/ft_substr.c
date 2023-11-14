/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:42:43 by tsofien-          #+#    #+#             */
/*   Updated: 2023/11/14 11:53:56 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*ptr;

	ptr = (char *) malloc(len * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i + start])
	{
		ptr[i] = s[i + start];
		i++;
	}
	return (ptr);
}
