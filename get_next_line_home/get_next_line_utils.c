/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:41:28 by tsofien-          #+#    #+#             */
/*   Updated: 2023/12/21 19:05:29 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		sizetotal;
	char	*res;
	int		i;
	int		j;

	i = 0;
	sizetotal = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (sizetotal + 1));
	if (!res)
		return (NULL);
	while (s1 && s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] != 0)
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[sizetotal] = 0;
	return (free(s1), res);
}

int	line_break(char *line)
{
	int	i;

	if (!line)
		return (-1);
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

char	*fill_eol(char *str, size_t index)
{
	char	*s;
	size_t	len;
	size_t	i;

	len = ft_strlen(str) - index;
	s = calloc(sizeof(char), len + 1);
	if (!s)
		return (NULL);
	i = 0;
	while (str[index] && i < len)
	{
		s[i] = str[index];
		i++;
		index++;
	}
	s[i] = '\0';
	return (s);
}

// int	main(void)
// {
// 	char	*gnl;
// 	int		fd;

// 	fd = open("text.md", O_RDWR);
// 	gnl = get_next_line(fd);
// 	printf("|%s|\n", gnl);
// 	while (gnl != NULL)
// 	{
// 		gnl = get_next_line(fd);
// 		printf("|%s|\n", gnl);
// 	}
// 	free(gnl);
// 	close(fd);
// 	return (0);
// }
