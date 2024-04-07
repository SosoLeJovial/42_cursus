/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:38:54 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/07 11:47:24 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"
// #include "./libmlx/mlx.h"

#include <stdio.h>
// open, close, read, write,
// malloc, free, perror,
// strerror, exit
// • Toutes les fonctions de la
// bibliothèque mathématique
// (option de compilation -lm,
// man man 3 math)
// • Toutes les fonctions de la
// MiniLibX
// • ft_printf et tout équivalent
// que VOUS avez codé

int	main(int ac, char **av)
{
	int error;

	if (ac != 2)
		return (1);
	error = ft_map_valid(av[1]);
	printf("this is error %d", error);
	return (0);
}

	// t_data	*data;


	// data = malloc(sizeof(t_data));
	// data->mlx_ptr = mlx_init();
	// if (!data->mlx_ptr)
	// 	return(1);
	// data->win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "ZEEUUUUUUUUBI");
	// if (!data->win_ptr)
	// 	return (free(mlx_ptr), 1);
	// while (1);