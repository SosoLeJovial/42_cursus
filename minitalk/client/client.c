/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:26:34 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/29 21:01:30 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

/* Send */
void	send_char(unsigned char c, int pid)
{
	int	i;
	int	bit;

	i = 8;
	while ()
}

/* Main */
int	main(int ac, char **av)
{
	int					pid;
	// struct sigaction	sa;

	if (ac != 3 || !parser_pid(av[1]) || !av[2])
		return (0);
	pid = ft_atoi(av[1]);
	printf("Server pid: %d\n", pid);
	if (av[2][0] == '1')
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
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
