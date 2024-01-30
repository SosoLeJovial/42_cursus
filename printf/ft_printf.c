/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 04:24:03 by tsofien-          #+#    #+#             */
/*   Updated: 2024/01/30 18:20:32 by tsofien-         ###   ########.fr       */
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
		return (write(1, "(null)", 6));
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
		result = ft_pointer(va_arg(args, void *)) - 1;
	else if (*format == 'd' || *format == 'i')
		result = ft_putnbr_sz(va_arg(args, int));
	else if (*format == 'u')
		result = ft_putnbr_ul(va_arg(args, long), "0123456789") - 1;
	else if (*format == 'x')
		result = ft_putnbr_ul(va_arg(args, long), "0123456789abcdef") - 1;
	else if (*format == 'X')
		result = ft_putnbr_ul(va_arg(args, long), "0123456789ABCDEF") - 1;
	else if (*format == '%')
		result = ft_putchar_sz('%');
	else
		return (-1);
	if (result < 0)
		return (-1);
	else
		return (result);
}

int main(void)
{
    int i = 42;
    char str[4] = "skr";
    unsigned int ud = -670;

    printf("R    %d\n", printf("\t%%\t %i %s\t%u %x %X %p\n", i, str, ud, ud, ud, str));
    printf("M    %d\n", ft_printf("\t%%\t %i %s\t%u %x %X %p\n", i, str, ud, ud, ud, str));
	// printf("R    %d\n", printf("%p\n", str));
	// printf("M    %d\n", ft_printf("%p\n", str));
    return (0);
}
