/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:24:21 by tsofien-          #+#    #+#             */
/*   Updated: 2023/11/12 20:51:34 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	ptr = (char *) haystack;
	if (needle[0] == '\0')
		return (ptr);
	while (ptr[i] && i < (int) len)
	{
		while (ptr[i + j] == needle[j] && i + j < (int) len)
		{
			if (needle[j + 1] == '\0')
				return (ptr + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}

int	main(void)
{
	const char	*largestring = "A la piscine nous scions des scitrons";
	const char	*smallstring = "sciontrons";
	char		*ptr;
	char		*test;

	test = strnstr(largestring, smallstring, 38);
	ptr = strnstr(largestring, smallstring, 38);

	printf("%s\n%s\n", ptr, test);
	return (0);
}