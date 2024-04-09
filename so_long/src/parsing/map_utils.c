/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:37:05 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/09 20:21:44 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void checker_path(int *error, char *path, int size)
{
	t_data_map		*duplicate;

	duplicate = init_struct_map(ft_map_valid(path, &error));
	if (!duplicate)
		return (*error += 1, NULL);
	
}

void	expand_virus(t_data_map *maps, int *error)
{
	int 	virus;
	int 	count_elements;
	char 	**s;

	virus = 1;
	count_elements = 1;
	s = maps->map;
	while (virus != 0 || count_elements != 0)
	{
		contamination(&s, &virus, &count_elements, size);
	}
}

void contamination(char ***s, int *virus, int *count_elements, int size)
{
	int	i;
	int	j;

	i = -1;
	while(++i < size)
	{
		j = -1;
		while (*s[i][++j])
		{
			if (*s[i][j] == 'P' || 'V')
			{
				if (*s[i][j] == 'P')
					*virus = 0;
				if (*s[i][j] == 'V')
					*count_elements = 0;
				if (i > 0 && *s[i - 1][j] == '0')
					*s[i - 1][j] = 'V';
				if (i < size - 1 && *s[i + 1][j] == '0')
					*s[i + 1][j] = 'V';
				if (j > 0 && *s[i][j - 1] == '0')
					*s[i][j - 1] = 'V';
				if (j < size - 1 && *s[i][j + 1] == '0')
					*s[i][j + 1] = 'V';
			}
		}
	}
}

