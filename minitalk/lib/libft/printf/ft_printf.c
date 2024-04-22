/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 04:24:03 by tsofien-          #+#    #+#             */
/*   Updated: 2024/01/30 23:30:57 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int			count;
	int			printed;
	va_list		args;

	if (!format)
		return (0);
	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			printed = 0;
			printed = ft_check_percent(++format, args);
			if (printed < 0)
				return (-1);
			else
				count += printed;
		}
		else
			count += ft_putchar_sz(*format);
		format++;
	}
	va_end(args);
	return (count);
}

int	ft_check_percent(const char *format, va_list args)
{
	if (*format == 'c')
		return (ft_putchar_sz(va_arg(args, int)));
	else if (*format == 's')
		return (putstr_checker(va_arg(args, char *)));
	else if (*format == 'p')
		return (ft_pointer(va_arg(args, void *)));
	else if (*format == 'd' || *format == 'i')
		return (ft_putnbr_sz(va_arg(args, int)));
	else if (*format == 'u')
		return (ft_putnbr_ul(va_arg(args, unsigned int), "0123456789"));
	else if (*format == 'x')
		return (ft_putnbr_ul(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (*format == 'X')
		return (ft_putnbr_ul(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (*format == '%')
		return (ft_putchar_sz('%'));
	return (-1);
}
