/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:13:22 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/06 18:13:26 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
// 0 pour un emplacement vide,
// 1 pour un mur,
// C pour un item à collecter (C pour collectible),
// E pour une sortie (E pour exit),
// P pour la position de départ du personnage.

int ft_map_valid(const char *path, int flags)
{
	int fd;

	fd = open(path, flags);
	if (fd < 0)
		return (NULL);
	if (ft_check_char(fd) != 0)
		return (close(fd),NULL);

}
int ft_check_char(int fd)
{
	int byte_read;
	char *buffer;

	byte_read = read(fd, );
}
