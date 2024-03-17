/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:19:05 by tsofien-          #+#    #+#             */
/*   Updated: 2024/03/17 21:30:29 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stdlib.h>
# include <stdio.h>

int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);
int		ft_isint(int number);
int		ft_sanitize(int number);
int		ft_check_args(int argc, char **argv, char ***list_args);
int		ft_sanitize_args(int argc, char **argv, char **list_args);
char	**ft_split(char const *s, char c);
void	ft_free_args(char **tab);
#endif