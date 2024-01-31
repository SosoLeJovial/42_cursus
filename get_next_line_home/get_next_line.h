/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:13:04 by tsofien-          #+#    #+#             */
/*   Updated: 2024/01/31 01:44:45 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15 
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
int		ft_strlen(char *len);
int		line_break(char *stock);
char	*fill_stock_eol(char *stock, size_t index);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_read_line(char *line_read, char *stock, int fd);
char	*fill_str(char *str, size_t index);
char	*fill_eol(char *str, char *target, size_t index);
#endif