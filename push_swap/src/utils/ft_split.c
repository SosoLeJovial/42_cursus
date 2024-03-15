/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:26:31 by tsofien-          #+#    #+#             */
/*   Updated: 2024/03/12 16:45:57 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

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
