/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 22:32:07 by tsofien-          #+#    #+#             */
/*   Updated: 2024/01/23 03:48:42 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H


# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(char *format, ...);
int		ft_pointer(char *format, int *ct, va_list args);
int		ft_check_percent(char *format, int *count, va_list args);
int		ft_strlen(char *str);
int		ft_putchar_sz(int c);
int		ft_putstr_sz(char *str);
int		ft_putnbr_sz(int nbr, char *base);
char	*ft_base(char format);
#endif