/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 23:27:57 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/18 03:02:09 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	checker_path(char *path)
{
	t_data			*cpy;
	int				error;

	error = 0;
	cpy = NULL;
	cpy = ft_init_data(cpy, path);
	if (!cpy)
		return (free_data(cpy), 0);
	expand_virus(cpy, &error);
	free_data(cpy);
	return (error);
}

void	expand_virus(t_data *d, int *error)
{
	int		valid;

	valid = contamination(d, (int)d->game->player_x, (int)d->game->player_y);
	if (!valid)
		*error = 1;
}

int	contamination(t_data *s, int x, int y)
{
	if (x < 0 || y < 0)
		return (0);
	if (s->game->exit == 0 && s->game->collectibles == 0)
		return (1);
	if (s->map[y][x] == 'C')
		s->game->collectibles--;
	if (s->map[y][x] == 'E')
		s->game->exit--;
	if (s->map[y][x] != '1' && s->map[y][x] != 'V')
		s->map[y][x] = 'V';
	if (s->map[y + 1][x] != '1' && s->map[y + 1][x] != 'V')
		if (contamination(s, x, y + 1) > 0)
			return (1);
	if (s->map[y - 1][x] != '1' && s->map[y - 1][x] != 'V')
		if (contamination(s, x, y - 1) > 0)
			return (1);
	if (s->map[y][x] != '1' && s->map[y][x + 1] != 'V')
		if (contamination(s, x + 1, y) > 0)
			return (1);
	if (s->map[y][x] != '1' && s->map[y][x - 1] != 'V')
		if (contamination(s, x - 1, y) > 0)
			return (1);
	return (0);
}
