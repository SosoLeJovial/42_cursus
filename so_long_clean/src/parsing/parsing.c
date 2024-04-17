/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:10:36 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/18 01:14:27 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	update_player(t_data *d, int y, int x);
static void	update_exit(t_data *d, int y, int x);

int	ft_check_char(char **s, int size, t_data *d)
{
	int	y;
	int	x;

	y = -1;
	while (++y < size)
	{
		x = 0;
		while (s[y][x])
		{
			if (s[y][x] == '0' || s[y][x] == '1' || s[y][x] == '\n')
				;
			else if (s[y][x] == 'C')
				d->game->collectibles += 1;
			else if (s[y][x] == 'P')
				update_player(d, y, x);
			else if (s[y][x] == 'E')
				update_exit(d, y, x);
			else
				return (0);
			x++;
		}
	}
	return (1);
}

int	ft_line_map(char *path)
{
	int		line_number;
	int		fd;
	char	*line;

	line_number = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		if (!(line[0] == '\n'))
			line_number++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (line_number);
}

static void	update_player(t_data *d, int y, int x)
{
	d->game->player++;
	d->game->player_x = (size_t)x;
	d->game->player_y = (size_t)y;
}

static void	update_exit(t_data *d, int y, int x)
{
	d->game->exit++;
	d->game->exit_x = (size_t)x;
	d->game->exit_y = (size_t)y;
}
