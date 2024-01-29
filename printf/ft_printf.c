/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 04:24:03 by tsofien-          #+#    #+#             */
/*   Updated: 2024/01/29 21:39:06 by tsofien-         ###   ########.fr       */
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

int	ft_pointer(void *ptr)
{
	int	ct;

	ct = 0;
	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	else
	{
		ft_putstr_sz("0x");
		ct += 2;
		ct += ft_putnbr_ul((unsigned long) ptr, "0123456789abcdef");
	}
	return (ct);
}

int	ft_check_percent(const char *format, va_list args)
{
	int	result;

	result = 0;
	if (*format == 'c')
		result = ft_putchar_sz(va_arg(args, int));
	else if (*format == 's')
		result = putstr_checker(va_arg(args, char *));
	else if (*format == 'p')
		result = ft_pointer(va_arg(args, void *));
	else if (*format == 'd' || *format == 'i')
		result = ft_putnbr_sz(va_arg(args, int));
	else if (*format == 'u')
		result = ft_putnbr_ul(va_arg(args, long), "0123456789");
	else if (*format == 'x')
		result = ft_putnbr_ul(va_arg(args, long), "0123456789abcdef");
	else if (*format == 'X')
		result = ft_putnbr_ul(va_arg(args, long), "0123456789ABCDEF");
	else if (*format == '%')
		result = ft_putchar_sz('%');
	else
		return (-1);
	if (result < 0)
		return (-1);
	else
		return (result);
}

int	putstr_checker(const char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	else
		return (ft_putstr_sz(str));
}

int	ft_putnbr_sz(int n)
{
	const char	sign = (n < 0);
	char		s[12] = {0};
	short		i;

	i = 11;
	s[i] = '0';
	while (n)
	{
		s[i--] = n % 10 + '0';
		n /= 10;
	}
	if (sign)
		s[i--] = '-';
	return (write(1, s + i, 12 - i));
}

