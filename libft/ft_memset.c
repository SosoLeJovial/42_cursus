/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:35:10 by tsofien-          #+#    #+#             */
/*   Updated: 2023/11/07 13:30:42 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	*ft_memset(void *s, int c, unsigned int n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
	{
		*str = (unsigned char)c;
		str++;
	}
}
/*
int	main()
{
	char s1[] = "et oui";
	char s2[] = "et oui";

	memset(s1, '.', 10);
	ft_memset(s2, '.', 2);
	printf("%s\n%s", s1, s2);
	return (0);
}*/
