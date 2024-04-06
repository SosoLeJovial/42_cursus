/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:13:22 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/06 19:48:13 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include <fcntl.h>
// 0 pour un emplacement vide,
// 1 pour un mur,
// C pour un item à collecter (C pour collectible),
// E pour une sortie (E pour exit),
// P pour la position de départ du personnage.

int ft_map_valid(const char *path)
{
	int fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	if (!ft_check_char(fd))
		return (close(fd), 0);
	return (1);
}
int ft_check_char(int fd)
{
	int		byte_read;
	char	buf[2];
	char	**map_line;

	byte_read = 1;
	map_line = NULL;
	while(byte_read != 0)
	{
		byte_read = read(fd, buf, 1);
		if (byte_read == -1)
			break ;
		if (!(buf[0] == '0') || !(buf[0] == '1') || !(buf[0] == 'C') || !(buf[0] == 'E') || !(buf[0] == 'P') || !(buf[0] == '\n'))
			return (0);
		*map_line = ft_strjoin(*map_line, buf);
		if (!*map_line)
			return (0);
	}
	return (1);
}
