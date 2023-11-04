/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:38:58 by tsofien-          #+#    #+#             */
/*   Updated: 2023/11/04 18:40:20 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
        i++;
    if (i == n)
        return (0);
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}