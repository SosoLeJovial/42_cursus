/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:26:32 by tsofien-          #+#    #+#             */
/*   Updated: 2024/05/01 11:44:02 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

/*
	🔥 Etapes pour speedrun ce vieux projet: 🔥
	
	-> utiliser PID
	-> Comprendre les signaux et les outils proposes par la library signal.h (blc)
	-> Echanger un msg en byte envoye bit par bit |= 😉

	💀 Erreur a eviter 💀
	-> ne pas utiliser sleep / pause ou usleep (useless + caca ++)
*/
void receive_signal(int signal, siginfo_t *info  ,void *context)
{
	static t_msg data = {0, 0, NULL, 0};

	data.byte <<= 1;
	if (signal == SIGUSR2)
		data.byte |= 1;
	data.bit_count++;
	if (data.bit_count == 8)
	{
		data.bit_count = 0;
		if (data.byte == '\0')
		{
			// ecris le message
			// free
			kill(SIGUSR2);
			data.byte = 0;
			data.len = 0;
		}
	}
	(void)context;
	(void)info;
}

int	main(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(acct));
	sa.sa_sigaction = receive_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	printf("Server pid: %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		;
	free(&sa);
	return (0);
}
