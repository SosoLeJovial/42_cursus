/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 22:32:07 by tsofien-          #+#    #+#             */
/*   Updated: 2024/01/29 03:31:53 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_pointer(void *ptr, char format);
int		ft_putnbr_ul(unsigned long nbr, char *base);
int		ft_putnbr_test(unsigned long nbr, char *base);
int		ft_check_percent(const char *format, va_list args);
int		ft_strlen(const char *str);
int		ft_putchar_sz(int c);
int		ft_putstr_sz(const char *str);
int		putstr_checker(const char *str);
int		ft_putnbr_sz(int nbr, char *base);
char	*ft_base(char format);
#endif