/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:26:32 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/22 15:44:43 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void receive_signal(int signal, siginfo_t *info  ,void *context)
{
	static t_msg	msg;
	unsigned char 	bytes;
	static char		*msg;
	static int 		i = 0;

	bytes <<= 1;
	if (signal == SIGUSR2)
		bytes |= 1;
	i++;
	if (i == 8)
	{
		i = 0;
		// tu as mis tous les caracters
		if (bytes == '\0')
		{
			//ecris le message
			//free
			//kill(sigusr2)
			bytes = 0;
			len = 0;
		}
	}
	void(context);
	void(info);
	printf("prout\n");
}

/*
	🔥 Etapes pour speedrun ce vieux projet: 🔥
	
	-> utiliser PID
	-> Comprendre les signaux et les outils proposes par la library signal.h (blc)
	-> Echanger un msg en byte envoye bit par bit |= 😉

	💀 Erreur a eviter 💀
	-> ne pas utiliser sleep / pause ou usleep (useless + caca ++)
*/

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = receive_signal();
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_printf("Server pid: %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		;
	return (0);
}
