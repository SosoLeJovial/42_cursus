/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 03:25:06 by tsofien-          #+#    #+#             */
/*   Updated: 2024/01/30 18:29:04 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

// int	ft_putnbr_ul(unsigned long n, char *base)
// {
// 	char		    s[65];
//     unsigned long   base_len;
// 	short		    i;

//     base_len = (unsigned long) ft_strlen(base);
// 	i = 64;
//     if (n == 0)
// 		s[i--] = base[0];
// 	while (n)
// 	{
// 		s[i--] = base[n % base_len];
// 		n /= base_len;
// 	}
// 	return (write(1, s + i, 65 - i));
// }

// int	ft_putnbr_sz(int n)
// {
// 	const char	sign = (n < 0);
// 	char		s[12];
// 	short		i;

//     s[11] = '\0';
// 	i = 11;
// 	s[i] = '0';
// 	while (n)
// 	{
// 		s[i--] = n % 10 + '0';
// 		n /= 10;
// 	}
// 	if (sign)
// 		s[i--] = '-';
// 	return (write(1, s + i, 12 - i));
// }

// putnbr ul in recursive
int	ft_putnbr_ul(unsigned long n, char *base)
{
	unsigned long	base_len;

	base_len = (unsigned long) ft_strlen(base);
	if (n >= base_len)
		ft_putnbr_ul(n / base_len, base);
	return (ft_putchar_sz(base[n % base_len]));
}
// putnbr sz in recursive
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
