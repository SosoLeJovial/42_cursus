/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:19:05 by tsofien-          #+#    #+#             */
/*   Updated: 2024/03/23 01:35:35 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stdlib.h>

long	ft_atoi(const char *nptr);
int		ft_isdigit(int c);
int		ft_isint(long number);
int		ft_check_args(int argc, char **argv, char ***list_args);
char	**ft_sanitize_args(int argc, char **argv, int *error);
char	**ft_split(char const *s, char c);
int		ft_checker_digit(char **argv);
void	*ft_free_args(char **tab);
int		strcontaindigit(char *str);
int		strcontainonedigit(char *nptr);
#endif