/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:24:21 by tsofien-          #+#    #+#             */
/*   Updated: 2023/11/10 17:28:38 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned char	*haystach;
	unsigned char	*needle;
	int				i;

	haystach = (unsigned char *)big;
	needle = (unsigned char *)little;
	if (!needle)
		return (haystach);
	i = 0;
	while (len--)
	{
		while (little == big)
			i++;
		if (little[i] == '\0' && big[i + len] != '\0')
			return (big[len]);
	}
	return (NULL);

}
/*
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
}*/