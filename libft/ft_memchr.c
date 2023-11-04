/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:44:33 by tsofien-          #+#    #+#             */
/*   Updated: 2023/11/04 18:45:11 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    *ft_memchr(const void *s, int c, size_t n)
{
    unsigned char *str;

    str = (unsigned char *)s;
    while (n--)
    {
        if (*str == (unsigned char)c)
            return (str);
        str++;
    }
    return (0);
}