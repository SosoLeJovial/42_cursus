/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:38:54 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/12 23:40:03 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"
// #include "./libmlx/mlx.h"
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
	t_data_map		*map;
	int 			error;

	error = 0;
	if (ac != 2 || !ft_strnstr(av[1], ".ber", ft_strlen(av[1])))
	{
		write(2, "Invalid input! make help\n", 25);
		return (0);
	}
	map = init_struct_map(ft_map_valid(av[1], &error), ft_line_map(av[1]));
	if (!map)
	{
		write(2, "Map is invalid\n", 15);
		return (free(map), 0);
	}
	count_necessary_elements(map, ft_line_map(av[1]), &error);
	if (error != 0)
		write(2, "Error\n", 6);
	if (checker_path(av[1], ft_line_map(av[1])))
		write(2, "Error\n", 6);
	ft_freemap(map->map, ft_line_map(av[1]));
	free(map);
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