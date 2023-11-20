/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:53:25 by tsofien-          #+#    #+#             */
/*   Updated: 2023/11/17 11:23:31 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*ptr;

	i = 0;
	j = 0;
	k = 0;
	ptr = (char *)s1;
	while (ptr[i] && ft_strchr(set, ptr[i]))
		i++;
	j = ft_strlen(ptr) - 1;
	while (ptr[j] && ft_strchr(set, ptr[j]) && j > i)
		j--;
	ptr = malloc(sizeof(char) * (j - i + 2));
	if (!ptr)
		return (NULL);
	while (i <= j)
		ptr[k++] = s1[i++];
	ptr[k] = '\0';
	return (ptr);
}