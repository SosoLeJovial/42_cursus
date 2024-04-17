/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:02:57 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/18 01:16:29 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

/*
	Etapes : 

	-> check l'input ✅
		-> check extension / file vide ? ✅
	-> creer la structure ✅
	-> creer la map et check si elle est valide ✅
	-> si valide rentrer toutes les informations dans la structure ✅
	-> lancer le jeu
	-> quitter proprement
*/

int	main(int ac, char **av)
{
	char	*path;
	t_data	*data;

	path = av[1];
	data = NULL;
	if (ac != 2 || !ft_valid_ber(path))
		return (ft_msg(2, "Error\n"), 1);
	data = ft_init_data(data, path);
	if (!data)
		return (ft_msg(2, "Error\n"), 1);
	if (checker_path(path))
		return (ft_msg(2, "Error\n"), 1);
	if (!ft_init_mlx(data))
		return (ft_msg(2, "Error\n"), 1);
	printf("player : %zu\nexit : %zu\ncollectibles : %zu\nplayer_y : %zu\nplayer_x : %zu\nexit_y : %zu\nexit_x : %zu\nmovement : %zu\n", data->game->player, data->game->exit, data->game->collectibles, data->game->player_y, data->game->player_x, data->game->exit_y, data->game->exit_x, data->game->movement);
	free_data(data);
	return (0);
}
