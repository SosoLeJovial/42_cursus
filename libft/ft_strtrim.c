/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:53:25 by tsofien-          #+#    #+#             */
/*   Updated: 2023/11/16 18:16:30 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

// size_t	ft_charset(char const *s1, char const *set)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s1[i] == set[i] && (set[i] || s1[i]))
// 	{
// 		if 
// 		i++;
// 	}
// 	return (i);
// }

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*to_return;

	i = ft_strlen(set);
	end = ft_strlen(s1);
	start = 0; 
	while (s1[start] == set[start] && set[start])
		i++;
	while (s1[end] == set[i] && set[i])
	{
		end--;
		i--;
	}
	to_return = malloc((end - start) * sizeof(char));
	if (!to_return)
		return (0);
	return (to_return);
}