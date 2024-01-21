/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 04:24:03 by tsofien-          #+#    #+#             */
/*   Updated: 2024/01/21 04:14:34 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int	ft_printf(const char *format, ...)
{
	int			count;
	va_list		args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			 
		}
		else
			ft_putchar_sz(format);
		count++;
		format++;
	}
	va_end(args);
	return (count);
}

int ft_check_percent(char format, )

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
	else
		return (base = "0123456789");
}


int	ft_putnbr_base(int nbr, char *base)
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
		count += ft_putnbr_base(nbr / base_len, base);
		count += ft_putnbr_base(nbr % base_len, base);
	}
	else
		count += ft_putchar_sz(base[nbr]);
	return (count);
}

int	main(void)
{
	ft_putnbr_base(230, "lapin");
	return (0);
}
