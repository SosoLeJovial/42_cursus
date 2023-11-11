/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:10:55 by tsofien-          #+#    #+#             */
/*   Updated: 2023/11/11 21:42:02 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*sorc;
	unsigned char	*dst;

	sorc = (unsigned char *) src;
	dst = (unsigned char *) dst;
	while (n--)
	{
		dst = sorc;
		dst++;
		sorc++;
	}
	return (dst);
}
