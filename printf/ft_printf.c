/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 04:24:03 by tsofien-          #+#    #+#             */
/*   Updated: 2024/01/24 16:27:20 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_printf(char *format, ...)
{
	int			count[1];
	int			printed;
	va_list		args;

	va_start(args, format);
	*count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			printed = 0;
			printed = *ft_check_percent(format, count, args);
			if (printed < 0)
				return (0);
			format++;
		}
		else
			*count += ft_putchar_sz(*format);
		format++;
	}
	va_end(args);
	return (*count);
}

int	*ft_pointer(char *format, int *ct, va_list args)
{
	printf("%s", "test");
	if (va_arg(args, void *) != 0)
	{
		ft_putstr_sz("0x");
		*ct += ft_putnbr_sz(*format, ft_base(*format));
	}
	return (ct);
}

int	*ft_check_percent(char *format, int *ct, va_list args)
{
	int		result;

	format++;
	result = 1;
	if (*format == 'c')
		result = ft_putchar_sz(va_arg(args, int));
	else if (*format == 's')
		result = ft_putstr_sz(va_arg(args, char *));
	else if (*format == 'p')
		result = *ft_pointer(format, ct, va_arg(args, void *));
	else if (*format == 'd' || *format == 'i' || *format == 'u')
		result = ft_putnbr_sz(va_arg(args, int), ft_base(*format));
	else if (*format == 'x' || *format == 'X' )
		result = ft_putnbr_sz(va_arg(args, unsigned int), ft_base(*format));
	else if (*format == '%')
		result = ft_putchar_sz('%');
	else
		return (0);
	if (result <= 0)
		*ct *= -1;
	else
		*ct += result;
	return (ct);
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
// int main(void)
// {
// 	printf("%d", ft_printf("%% %% %%\n"));
// 	return (0);
// }
