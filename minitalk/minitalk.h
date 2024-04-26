/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:26:28 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/25 17:20:23 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include "lib/libft/libft.h"
# include "lib/libft/printf/ft_printf.h"

typedef struct s_msg
{
	size_t			len;
	char			*msg;
	unsigned char	byte;

}	t_msg;
int	parser_pid(char *str);

#endif