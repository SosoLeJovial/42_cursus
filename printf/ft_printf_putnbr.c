/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 03:25:06 by tsofien-          #+#    #+#             */
/*   Updated: 2024/01/29 22:19:01 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_putnbr_ul(unsigned long n, char *base)
{
	char		    s[65] = {0};
    unsigned long   base_len;
	short		    i;

    base_len = (unsigned long) ft_strlen(base);
	i = 64;
    if (n == 0)
	    s[i--] = base[0];
	while (n)
	{
		s[i--] = base[n % base_len];
		n /= base_len;
	}
	return (write(1, s + i, 65 - i));
}

// int main(void)
// {
//     int i = 42;
//     char str[4] = "skr";
//     unsigned int ud = -670;

//      printf("R    %d\n", printf("\t%%\t %i %s\t%u %x %X %p\n", i, str, ud, ud, ud, str));
//      printf("M    %d\n", ft_printf("\t%%\t %i %s\t%u %x %X %p\n", i, str, ud, ud, ud, str));
//      return (0);
//  }