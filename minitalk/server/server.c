/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:26:32 by tsofien-          #+#    #+#             */
/*   Updated: 2024/05/01 23:14:19 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

/*
	🔥 Etapes pour speedrun ce vieux projet: 🔥
	
	-> utiliser PID
	-> Comprendre les signaux et les outils proposes 
		par la library signal.h (blc)
	-> Echanger un msg en byte envoye bit par bit |= 😉

	💀 Erreur a eviter 💀
	-> ne pas utiliser sleep / pause ou usleep (useless + caca ++)
*/
void	receive_signal(int signal, siginfo_t *info, void *context)
{
	static t_msg	data = {0, NULL, 0, 0};

	data.byte <<= 1;
	if (signal == SIGUSR1)
		data.byte |= 1;
	data.bit_count++;
	if (data.bit_count == 8)
	{
		data.msg = ft_realloc(data.msg, (sizeof(char) * (data.len) + 8));
		if (!data.msg)
		{
			kill(info->si_pid, SIGUSR1);
			free(data.msg);
			return ;
		}
		data.msg[data.len++] = data.byte;
		if (data.byte == '\0')
			ft_message_received(&data, info->si_pid);
		data.bit_count = 0;
	}
	kill(info->si_pid, SIGUSR1);
	(void)context;
}

void	ft_message_received(t_msg *data, int pid)
{
	write(1, data->msg, data->len);
	write(1, "\n", 1);
	free(data->msg);
	data->msg = 0;
	data->byte = 0;
	data->len = 0;
	data->bit_count = 0;
	kill(pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = receive_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Server pid: %d\n", getpid());
	while (1)
		;
	return (0);
}
