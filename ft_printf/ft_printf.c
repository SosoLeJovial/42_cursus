/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 04:24:03 by tsofien-          #+#    #+#             */
/*   Updated: 2024/01/23 03:53:24 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_printf(char *format, ...)
{
	int			*count;
	int			printed;
	va_list		args;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			printed = ft_check_percent(format, count, args);
			if (printed > 0)
				count += printed;
			else
				return (0);
			format++;
		}
		else
			count += ft_putchar_sz(*format);
		format++;
	}
	va_end(args);
	return (*count);
}

int	ft_pointer(char *format, int *ct, va_list args)
{
	if (va_arg(args, void *) != 0)
	{
		ft_putstr_sz("0x");
		*ct += ft_putnbr_sz(*format, ft_base(*format));
	}
	return (*ct);
}

int	ft_check_percent(char *format, int *ct, va_list args)
{
	format++;
	if (*format == 'c')
		ct += ft_putchar_sz(va_arg(args, int));
	else if (*format == 's')
		ct += ft_putstr_sz(va_arg(args, char *));
	else if (*format == 'p')
		ct += ft_pointer(format, ct, va_arg(args, void *));
	else if (*format == 'd' || *format == 'i' || *format == 'u')
		ct += ft_putnbr_sz(va_arg(args, int), ft_base(*format));
	else if (*format == 'x' || *format == 'X' )
		ct += ft_putnbr_sz(va_arg(args, unsigned int), ft_base(*format));
	else if (*format == '%')
		ct += ft_putchar_sz('%');
	else
		return (0);
	return (*ct);
}

int	ft_putchar_sz(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr_sz(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (write(1, str, i));
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// %d %i %u (base 10) %x %X  (base 16)
char	*ft_base(char format)
{
	char	*base;

	if (format == 'x')
		return (base = "0123456789abcdef");
	if (format == 'X')
		return (base = "0123456789ABCDEF");
	if (format == 'p')
		return (base = "0123456789abcdef");
	else
		return (base = "0123456789");
}

int	ft_putnbr_sz(int nbr, char *base)
{
	int		count;
	int		base_len;

	count = 0;
	base_len = ft_strlen(base);

	if (nbr < 0)
	{
		ft_putchar_sz('-');
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

int main(void)
{
	printf("return value : %d\n", ft_printf("%s", "coucou\n"));
	return (0);
}
