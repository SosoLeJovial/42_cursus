/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 04:24:03 by tsofien-          #+#    #+#             */
/*   Updated: 2024/01/28 05:11:14 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char *format, ...)
{
	int			count;
	int			printed;
	va_list		args;

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
	if (!ptr)
		return (write(1, "(nil)", 5));
	else
	{
		ft_putstr_sz("0x");
		ct += 2;
		ct += ft_putnbr_hex((unsigned long) ptr);
	}
	return (ct);
}

int	ft_check_percent(char *format, va_list args)
{
	int	result;

	result = 0;
	if (*format == 'c')
		result = ft_putchar_sz(va_arg(args, int));
	else if (*format == 's')
		result = putstr_checker(va_arg(args, char *));
	else if (*format == 'p')
		result = ft_pointer(va_arg(args, void *));
	else if (*format == 'd' || *format == 'i' || *format == 'u')
		result = ft_putnbr_sz(va_arg(args, int), ft_base(*format));
	else if (*format == 'x' || *format == 'X')
		result = ft_putnbr_sz(va_arg(args, unsigned int), ft_base(*format));
	else if (*format == '%')
		result = ft_putchar_sz('%');
	else
		return (-1);
	if (result < 0)
		return (-1);
	else
		return (result);
}

int	putstr_checker(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	else
		return (ft_putstr_sz(str));
}

int	ft_putnbr_sz(int nbr, char *base)
{
	int	count;
	int	base_len;

	count = 0;
	base_len = ft_strlen(base);
	if (nbr == -2147483648)
	{
		count += ft_putchar_sz('2');
		nbr = 147483648;
	}
	if (nbr < 0)
	{
		count += ft_putchar_sz('-');
		nbr = -nbr;
	}
	if (nbr >= base_len)
	{
		count += ft_putnbr_sz(nbr / base_len, base);
		count += ft_putnbr_sz(nbr % base_len, base);
	}
	else
		count += ft_putchar_sz(base[nbr]);
	return (count);
}

// int main(void)
// {
// 	printf("%d\n" ,printf("%%"));
// 	printf("%d\n" ,ft_printf("%%"));
// 	return (0);
// }
