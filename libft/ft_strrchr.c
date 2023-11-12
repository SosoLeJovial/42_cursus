/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:50:30 by tsofien-          #+#    #+#             */
/*   Updated: 2023/11/12 20:28:02 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i != 0)
	{
		if (s[i] == c)
			return (s + i);
		i--;
	}
	return (0);
}

/*
int	main()
{
	printf("|%s|", ft_strrchr("te st co el ", 32));
	return (0);
}*/
