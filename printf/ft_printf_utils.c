/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:31:57 by tsofien-          #+#    #+#             */
/*   Updated: 2024/01/29 19:47:04 by tsofien-         ###   ########.fr       */
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


