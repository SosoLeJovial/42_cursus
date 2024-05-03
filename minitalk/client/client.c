/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:26:34 by tsofien-          #+#    #+#             */
/*   Updated: 2024/05/02 00:03:40 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	g_status = 0;

void	receive_msg(int signal, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (signal == SIGUSR2)
		write(1, "message received!🤮\n", 21);
	else
		g_status = 1;
}

void	send_string(unsigned char *s, int pid)
{
	int	i;

	i = 0;
	while (s[i])
	{
		send_char(s[i], pid);
		i++;
	}
	send_char('\0', pid);
}

/* Send */
void	send_char(unsigned char c, int pid)
{
	int	i;
	int	bit;

	i = 7;
	bit = 0;
	while (i >= 0)
	{
		g_status = 0;
		bit = (c >> i) & 1;
		if (bit == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_status)
			;
		i--;
	}
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

/* Main */
int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	sa;

	if (ac != 3 || !parser_pid(av[1]) || !av[2])
		return (0);
	sa.sa_sigaction = receive_msg;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = ft_atoi(av[1]);
	send_string((unsigned char *)av[2], pid);
	return (0);
}
