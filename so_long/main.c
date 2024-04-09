/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:38:54 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/09 16:33:12 by tsofien-         ###   ########.fr       */
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
	char	*path;
	t_data_map		*map;
	int line_map;
	int error;
	int i;

	error = 0;
	if (ac != 2)
		return (1);
	path = av[1];
	line_map = ft_line_map(path);
	map = init_struct_map(ft_map_valid(path, &error));
	count_necessary_elements(map, line_map, &error);
	printf("player : %ld\n", map->player_count);
	printf("exit :%ld\n", map->exit_count);
	printf("consumable_count :%ld\n", map->consumable_count);
	if (error != 0)
		write(1, "error\n", 6);
	if (map->map)
	{
		i = -1;
		while (++i < line_map)
			printf("%s", map->map[i]);
		ft_freemap(map->map, line_map);
	}
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