/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:10:43 by tsofien-          #+#    #+#             */
/*   Updated: 2023/11/04 18:24:24 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    *ft_memset(void *b, int c, size_t len)
{
    unsigned char *str;

    str = (unsigned char *)b;
    while (len--)
        *str++ = (unsigned char)c;
    return (b);
}