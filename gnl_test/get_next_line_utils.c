/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 20:58:32 by tsofien-          #+#    #+#             */
/*   Updated: 2024/02/01 12:36:01 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	char	*s;

	s = (char *)str;
	while (*s)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	if (*s == (char)c)
		return (s);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	c;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	c = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[c] != '\0')
		str[i++] = s2[c++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (dest && dest[i])
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_save(char *buffer, char *line_final)
{
	char	*line;

	// look for what is inside buffer, take until \n and strjoin line_final and the part of buffer
	if (!ft_strchr(buffer, '\n'))
		return (ft_strjoin(line_final, buffer));
	line = ft_line_break(buffer);
	line_final = ft_strjoin(line_final, line);
	free(line);
	return (line_final);
}

char	*ft_line_break(char *buffer)
{
	char 	*new_line;
	int		i;
	int		len;

	i = 0;
	while (buffer && buffer[i])
	{
		if (buffer[i] == '\n')
			break ;
		i++;
	}
	new_line = malloc((i + 1) * sizeof(char));
	if (!new_line)
		return (NULL);
	len = i + 1;
	i = 0;
	while (i < len)
	{
		new_line[i] = buffer[i];
		i++;
	}
	return (new_line);
}

// int	main(void)
// {
// 	char	*str;

// 	str = "Coucou \n il y'a du monde";
// 	printf("string : %s", ft_line_break(str));
// 	return (0);
// }
