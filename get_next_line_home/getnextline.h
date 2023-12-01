/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:13:04 by tsofien-          #+#    #+#             */
/*   Updated: 2023/12/01 09:45:09 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 30
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

// typedef struct t_lst
// {
// 	int				fd;
// 	char			buffer[BUFFER_SIZE];
// 	char			*str;
// 	struct t_lst	*next;
// }	t_lst;

size_t	ft_strlen(char *buffer);
size_t	ft_line_break(char *buffer, size_t index);
char	*get_next_line(int fd);

#endif