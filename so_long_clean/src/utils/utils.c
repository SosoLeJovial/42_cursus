/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:43:46 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/17 20:21:18 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_msg(int fd, char *msg)
{
	write(fd, msg, ft_strlen(msg));
}

int	ft_valid_ber(char *path)
{
	int		fd;
	char	buf[2];

	if (!path)
		return (0);
	if (!ft_strnstr(path, ".ber", ft_strlen(path)))
		return (0);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	if (read(fd, buf, 1) == 0)
		return (close(fd), 0);
	return (close(fd), 1);
}
