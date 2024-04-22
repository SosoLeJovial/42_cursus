/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:26:34 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/22 15:01:02 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

/* Main */
int	main(int ac, char **av)
{
	if (ac != 2 || !parser_pid(av[1]))
		return (0);
	printf("Server pid: %d\n", ft_atoi(av[1]));
	printf("Hello Client !\n");
	printf("Client pid: %d\n", getpid());
}

/* Parser */
int	parser_pid(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}
