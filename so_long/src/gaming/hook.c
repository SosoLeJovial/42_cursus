/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 02:37:53 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/16 19:35:03 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	move_player(int keysym, t_data *data)
{
	if (keysym == KEY_W)
		data->movement++;
	if (keysym == KEY_Q)
		data->movement++;
	if (keysym == KEY_S)
		data->movement++;
	if (keysym == KEY_D)
		data->movement++;
	write(1, "Moves: ", 7);
	ft_putnbr_fd(data->movement, 1);
	write(1, "\n", 1);
	return (0);
}
