/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:43:34 by tsofien-          #+#    #+#             */
/*   Updated: 2023/11/10 11:06:53 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == c)
			return (s + i);
	}
	return (0);
}
/*
int	main()
{
	printf("%s\n%s", strchr("te st ", 32), ft_strchr("te st ", 32));
	return (0);
}*/
