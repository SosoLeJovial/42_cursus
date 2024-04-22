/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 22:32:07 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/22 13:51:34 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ftp_strlen(const char *str);
int		ftp_putchar_sz(int c);
int		ftp_putstr_sz(const char *str);
int		putstr_checker(const char *str);
int		ft_check_percent(const char *format, va_list args);
int		ft_pointer(void *ptr);
int		ft_putnbr_ul(unsigned int n, char *base);
int		ft_putnbr_pointer(unsigned long n, char *base);
int		ft_putnbr_sz(int nbr);
#endif