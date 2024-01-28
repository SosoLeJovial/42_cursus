/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:31:57 by tsofien-          #+#    #+#             */
/*   Updated: 2024/01/27 05:12:50 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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

int	ft_putnbr_hex(unsigned long nbr)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (nbr >= 16)
	{
		count += ft_putnbr_hex(nbr / 16);
		count += ft_putchar_sz(base[nbr % 16]);
	}
	else
		count += ft_putchar_sz(base[nbr]);
	return (count);
}
