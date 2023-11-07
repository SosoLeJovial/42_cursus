/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:04:34 by tsofien-          #+#    #+#             */
/*   Updated: 2023/11/07 12:29:48 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n && n > 0)
	{
		if (s1[i] != s2[i])
		{
			if (s1[i] > s2[i])
				return (1);
			else
				return (-1);
		}
		i++;
	}
	return (0);
}
/*
int	main()
{
	printf("%d\n", strncmp("okay bro", "okay ", -1));
	printf("%d", ft_strncmp("okay bro", "okay ", 1));
}*/
