/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:28:00 by tsofien-          #+#    #+#             */
/*   Updated: 2024/05/21 01:21:16 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] && s[i] != c)
		{
			i++;
		}
		count++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (count);
}

static size_t	ft_word_lenght(char const *s, char c, size_t index)
{
	size_t	i;

	i = 0;
	while (s[index] && s[index++] != c)
		i++;
	return (i);
}

int	ft_tab_init(char ***tab, char const *s, char c)
{
	if (!s)
		return (1);
	*tab = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!(*tab))
		return (1);
	return (0);
}

static void	*ft_freetab(char **tab, size_t i)
{
	while (i > 0)
		free(tab[--i]);
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;
	size_t	k;

	if (ft_tab_init(&tab, s, c))
		return (NULL);
	i = -1;
	k = 0;
	while (s[++i] && k < ft_count_words(s, c))
	{
		if (s[i] != c)
		{
			tab[k] = malloc(sizeof(char) * (ft_word_lenght(s, c, i) + 1));
			if (!(tab[k]))
				return (ft_freetab(tab, k));
			j = 0;
			while (s[i] && s[i] != c)
				tab[k][j++] = s[i++];
			tab[k++][j] = '\0';
		}
	}
	tab[k] = 0;
	return (tab);
}

int main(void)
{
	char *s = "eh    oh   la ";
	int	i = 0;
	char c = ' ';
	char **result;

	result = ft_split(s, c);
	while(result[i])
	{
		printf("%s\n", result[i]);
		free(result[i++]);
	}
	free(result[i]);
	free(result);
	return (0);
}

static size_t	index_start(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] == c)
		i++;
	return (i);
}

static size_t	index_end(char const *s, char c)
{
	size_t	i;

	i = ft_strlen(s);
	while (s[i] == c)
		i--;
	return (i);
}

static int	len_s(size_t start, size_t end, char const *s)
{
	size_t	len_s;
	size_t	len_total;

	len_s = (size_t) ft_strlen(s);
	len_total = len_s - start - (len_s - end);
	return (len_total);
}
