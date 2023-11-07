/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:23:19 by tsofien-          #+#    #+#             */
/*   Updated: 2023/11/04 19:24:29 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strnstr(const char *big, const char *little, size_t len)
{
    size_t i;
    size_t j;

    i = 0;
    if (!little[i])
        return ((char *)big);
    while (big[i] && i < len)
    {
        j = 0;
        while (big[i + j] == little[j] && i + j < len)
        {
            if (!little[j + 1])
                return ((char *)big + i);
            j++;
        }
        i++;
    }
    return (0);
}