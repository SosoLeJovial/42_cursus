/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 03:25:06 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/22 14:36:21 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_putnbr_ul(unsigned int n, char *base)
{
	unsigned long	base_len;
	int				count;

	count = 0;
	base_len = (unsigned long) ftp_strlen(base);
	if (n >= base_len)
		count += ft_putnbr_ul(n / base_len, base);
	count += ft_putchar_sz(base[n % base_len]);
	return (count);
}

int	ft_putnbr_pointer(unsigned long n, char *base)
{
	unsigned long	base_len;
	int				count;

	count = 0;
	base_len = (unsigned long) ftp_strlen(base);
	if (n >= base_len)
		count += ft_putnbr_pointer(n / base_len, base);
	count += ft_putchar_sz(base[n % base_len]);
	return (count);
}

int	ft_putnbr_sz(int n)
{
	const char	sign = (n < 0);
	int			count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_putstr_sz("-2147483648");
		return (count);
	}
	if (sign)
	{
		count += ft_putchar_sz('-');
		n *= -1;
	}
	if (n >= 10)
		count += ft_putnbr_sz(n / 10);
	count += ft_putchar_sz(n % 10 + '0');
	return (count);
}
