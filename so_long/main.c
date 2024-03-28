/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:38:54 by tsofien-          #+#    #+#             */
/*   Updated: 2024/03/28 16:39:09 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"



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
	int	i;

	i = 1
	if (ac < 2)
		return (0);
	while (i < ac)
		printf("%s\n", av[i++]);
	return (0);
}