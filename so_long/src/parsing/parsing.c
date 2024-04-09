/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 21:03:37 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/09 15:05:06 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int ft_check_char(char **s, int line_map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < line_map)
	{
		j = 0;
		while (s[i][j])
		{
			if ((s[i][j] == '0' || s[i][j] == '1' || s[i][j] == 'C' || s[i][j] == 'E' || s[i][j] == 'P' || s[i][j] == '\n'))
				j++;
			else
				return (0);
		}
	}
	if (!checker_wall(s[0]) || !checker_wall(s[line_map -1]))
		return (0);
	if (!check_valid_line(s, line_map))
		return (0);
	if (!check_line_length(s, line_map))
		return (0);
	return (1);
}

int	check_line_length(char **s, int size)
{
	int	length;
	int		i;
	int		j;

	i = 0;
	j = 0;
	length = 0;
	while(s[i][j])
		j++;
	length = j;
	while (++i < size - 2)
	{
		j = 0;
		while (s[i][j])
			j++;
		if (j != length)
			return (0);
	}
	j = 0;
	while(s[i][j])
		j++;
	if (j != length)
		return (0);
	return (1);
}

int	checker_wall(char *map)
{
	int j;

		j = 0;
		while (map[j] && map[j] != '\0')
			if (map[j] == '1' || map[j] == '\n')
				j++;
			else
				return (0);
	return (1);
}

int	check_valid_line(char **map, int size)
{
	int j;
	int	i;

	if (!map)
		return (0);
	i = 1;
	while (i < size - 1)
	{
		j = 0;
		if (map[i][0] != '1')
			return (0);
		while (map[i][j] && map[i][j] != '\0')
			j++;
		if (map[i][j - 2] != '1')
			return (0);
		i++;
	}
	return (1);
}
