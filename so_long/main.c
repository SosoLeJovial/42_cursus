/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:38:54 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/06 14:48:49 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"
#include "./libmlx/mlx.h"

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

int	main(void)
{
	mlx_t	*mlx_ptr;
	mlx_t	*win_ptr;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return(1);
	win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "ZEEUUUUUUUUBI");
	if (!win_ptr)
		return (free(mlx_ptr), 1);
	while (1);
	return (0);
}
