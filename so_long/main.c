/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:38:54 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/14 03:05:45 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	main(int ac, char **av)
{
	t_data_map		*map;
	t_data			data;
	int 			error;

	error = 0;
	if (ac != 2 || !ft_strnstr(av[1], ".ber", ft_strlen(av[1])))
		return (display_error(2, "Invalid input! make help\n"),0);
	map = init_struct_map(ft_map_valid(av[1], &error), ft_line_map(av[1]));
	if (!map)
		return (0);
	// MLX stfuff

	data = init_data(&data, map);
	// clean exit here
	if (map)
		ft_freemap(map->map, ft_line_map(av[1]));
	if (map)
		free(map);
	return (0);
}
