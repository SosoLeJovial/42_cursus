/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:55:12 by tsofien-          #+#    #+#             */
/*   Updated: 2023/11/16 13:26:22 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>



char	*ft_strtrim(char const *s1, char const *set)
{
	char		*to_return;
	size_t		start;
	size_t		end;
	size_t		i;
	size_t		j;

	start = -1;
	end = ft_strlen(s1);
	i = 0;
	while (s1[++start])
	{
		while (s1[start] == set[i])
			i++;
		if (set[i] == '\0')
			break ;
		else
			i = 0;
	}
	to_return = (char *) malloc((end - start) * sizeof(char));
	if (!to_return)
		return (NULL);
	j = -1;
	while (to_return[++j])
	{
		to_return[j] = s1[start + j];
	}
	return (to_return);
}

int	main(void)
{
	char s1[] = "Ekip Cool mon poto Ekip";
	char set[] = "Ekip";

	printf("%s", ft_strtrim(s1, set));
	return (0);
}
