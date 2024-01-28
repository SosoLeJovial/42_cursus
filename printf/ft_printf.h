/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 22:32:07 by tsofien-          #+#    #+#             */
/*   Updated: 2024/01/27 05:09:44 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(char *format, ...);
int		ft_pointer(void *ptr);
int		ft_putnbr_hex(unsigned long nbr);
int		ft_check_percent(char *format, va_list args);
int		ft_strlen(char *str);
int		ft_putchar_sz(int c);
int		ft_putstr_sz(char *str);
int		putstr_checker(char *str);
int		ft_putnbr_sz(int nbr, char *base);
char	*ft_base(char format);
#endif