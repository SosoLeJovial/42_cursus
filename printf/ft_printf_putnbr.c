/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 03:25:06 by tsofien-          #+#    #+#             */
/*   Updated: 2024/01/29 04:42:27 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_putnbr_test(unsigned long nbr, char *base)
{
	int					count;
	unsigned long		base_len;

	count = 0;
	base_len = (unsigned long)ft_strlen(base);
	if (nbr < base_len)
		count += ft_putchar_sz(base[nbr]);
	if (nbr >= base_len)
	{
		count += ft_putnbr_test(nbr / base_len, base);
	    count += ft_putnbr_test(nbr % base_len, base);
	}
	return (count);
}

int	ft_putnbr_ul(unsigned long nbr, char *base)
{
	int					count;
	unsigned long		base_len;

	count = 0;
	base_len = (unsigned long)ft_strlen(base);
	if (nbr < base_len)
		count += ft_putchar_sz(base[nbr]);
	if (nbr >= base_len)
	{
		count += ft_putnbr_ul(nbr / base_len, base);
	    count += ft_putnbr_ul(nbr % base_len, base);
	}
	return (count);
}
// int main(void)
//  {
//     int i = 42;
//     char str[4] = "skr";
//     unsigned ud = -670;

//      printf("R    %d\n", printf("\t%%\t %i %s\t%u %x %X %p\n", i, str, ud, ud, ud, str));
//      printf("M    %d\n", ft_printf("\t%%\t %i %s\t%u %x %X %p\n", i, str, ud, ud, ud, str));
//      return (0);
//  }