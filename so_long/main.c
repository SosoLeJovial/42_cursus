/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:38:54 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/16 23:44:51 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int ac, char **av)
{
	t_data_map		*map;
	t_data			*data;
	int 			error;

	error = 0;
	data = NULL;
	if (ac != 2 || !ft_strnstr(av[1], ".ber", ft_strlen(av[1])))
		return (display_error(2, "Invalid input! make help\n"),0);
	map = init_struct_map(ft_map_valid(av[1], &error), ft_line_map(av[1]));
	if (!map)
		return (0);
	if(!error)
		count_necessary_elements(map, map->size_map, &error);
	data = init_data(data, map);
	if (!data)
		free_mlx(data);
	start_game(data);
	free_all(data);
	return (0);
}
