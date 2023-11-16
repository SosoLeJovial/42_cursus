/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:45:56 by tsofien-          #+#    #+#             */
/*   Updated: 2023/11/16 14:57:37 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*to_return;

	i = -1;
	j = -1;
	k = -1;
	to_return = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!to_return)
		return (NULL);
	while (s1[++i] != '\0')
	{
		while (set[++j] != '\0')
		{
			if (s1[i] == set[j])
				i++;
		}
		to_return[++k] = s1[i];
		j = -1;
	}
	to_return[k] = '\0';
	return (to_return);
}

// int	main(void)
// {
// 	char s1[] = "Ekip Cool mon poto Ekip";
// 	char set[] = "Ekip";
//     char *to_return;

//     to_return = ft_strtrim(s1, set);

// 	printf("%s", to_return);
//     free(to_return);
// 	return (0);
// }
