/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 21:03:37 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/08 03:22:52 by tsofien-         ###   ########.fr       */
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
		j = -1;
		while (s[i][++j])
			if (!(s[i][j] == '0') || !(s[i][j] == '1') || !(s[i][j] == 'C') || !(s[i][j] == 'E') || !(s[i][j] == 'P') || !(s[i][j] == '\n'))
				return (0);
	}
	if (checker_wall(s[0]) && checker_wall(s[line_map -1]))
		return (0);
	return (1);
}

int	checker_wall(char *map)
{
	int j;

		j = -1;
		while (map[++j] && map[j] != '\0')
			if (map[j] != '1' || map[j] != '\n')
				return (0);
	return (1);
}

int	check_valid_line(char *line_map)
{
	int j;

	if (!line_map)
		return (0);
	if (line_map[0] != '1')
		return (0);
	j = -1;
	while (line_map[++j] && line_map[j] != '\0')
		j++;
	if (line_map[j - 2] != '2')
		return (0);
	return (1);
}
