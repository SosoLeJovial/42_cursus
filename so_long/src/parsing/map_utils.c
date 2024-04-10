/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:37:05 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/10 20:32:28 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void checker_path(int *error, char *path, int size)
{
	t_data_map		*duplicate;
	size_t 			i;

	duplicate = init_struct_map(ft_map_valid(path, error));
	if (!duplicate)
		*error = 1;
	duplicate->size_map = size;
	expand_virus(duplicate, error);
	if (*error != 0)
	{
		i = 0;
		while (i < duplicate->size_map)
			printf("%s", duplicate->map[i++]);
	}
	ft_freemap(duplicate->map, duplicate->size_map);
	free(duplicate);
}

void	expand_virus(t_data_map *maps, int *error)
{
	int 	virus;
	int 	count_elements;
	size_t	i;

	virus = 1;
	while (virus != 0 || count_elements != 0)
	{
		i = 0;
		virus = 0;
			// Contamine la map, check dans ligne s'il y a un virus
			contamination(&maps, &virus, &i);
			if (maps->player_count == 0 && maps->exit_count == 0 && maps->consumable_count == 0)
				count_elements = 0;
			i++;
	}
	if (maps->player_count != 0 || maps->exit_count != 0 || maps->consumable_count != 0)
		*error = 1;
	if (virus != 0)
		*error = 1;
}

void	contamination(t_data_map **s, int *virus, int *l)
{
	int	j;
	int i;

	i = *l;
	j = 0;
	while (s->maps[i][j])
	{
		if (s->maps[i][j] == 'V')
			// contamine N, S, O, E si != 1
		else
		{
			if (s->maps[i][j] == 'P')
			{
				s->player_count--;
				s->maps[i][j] = 'V';
			}
			if (s->maps[i][j] == 'E')
			{
				s->exit_count--;
				s->maps[i][j] = 'V';
			}
		}
		j++;
	}
}

void propagation_NSOE(t_data_map **s, int i, int j)
{
	if (s->maps[i - 1][j] != '1' && s->maps[i - 1][j] != 'V')
	{
		check_case(&s, s->maps[i - 1][j]);
		s->maps[i - 1][j] = 'V';
	}
	if (s->maps[i + 1][j] != '1' && s->maps[i + 1][j] != 'V')
	{
		check_case(&s, s->maps[i + 1][j]);
		s->maps[i + 1][j] = 'V';
	}
	if (s->maps[i][j - 1] != '1' && s->maps[i][j - 1] != 'V')
	{
		check_case(&s, s->maps[i][j - 1]);
		s->maps[i][j - 1] = 'V';
	}
	if (s->maps[i][j + 1] != '1' && s->maps[i][j + 1] != 'V')
	{
		check_case(&s, s->maps[i][j + 1]);
		s->maps[i][j + 1] = 'V';
	}
}


static void check_case(t_data_map ***maps, char c)
{
	if (c == 'P')
		(*maps)->player_count--;
	if (c == 'E')
		(*maps)->exit_count--;
	if (c == 'C')
		(*maps)->consumable_count--;
}