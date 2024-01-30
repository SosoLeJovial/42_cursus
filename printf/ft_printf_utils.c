/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:31:57 by tsofien-          #+#    #+#             */
/*   Updated: 2024/01/30 23:20:29 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_strlen(const char *str)
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

int	ft_putstr_sz(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (write(1, str, i));
}

int	putstr_checker(const char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	else
		return (ft_putstr_sz(str));
}

int	ft_pointer(void *ptr)
{
	int	ct;

	ct = 0;
	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	else
	{
		ft_putstr_sz("0x");
		ct += 2;
		ct += ft_putnbr_pointer((unsigned long) ptr, "0123456789abcdef");
	}
	return (ct);
}
