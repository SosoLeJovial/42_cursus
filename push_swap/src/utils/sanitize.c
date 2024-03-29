/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanitize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:58:30 by tsofien-          #+#    #+#             */
/*   Updated: 2024/03/27 18:01:07 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

int	ft_check_args(int argc, char **argv, char ***list_args)
{
	if (argc == 2)
	{
		if (ft_checker_digit(argv) != 0)
			return (1);
		*list_args = ft_split(argv[1], 32);
		if (!*list_args)
			return (1);
	}
	if (argc > 2)
	{
		if (check_argv_terminator(argv) != 0)
			return (1);
		if (ft_checker_digit(argv) != 0)
			return (1);
		*list_args = argv;
		return (-1);
	}
	return (0);
}

char	**ft_sanitize_args(int argc, char **argv, int *check_error)
{
	int		i;
	long	content;
	char	**list_args;

	content = 0;
	list_args = NULL;
	i = 0;
	*check_error = ft_check_args(argc, argv, &list_args);
	if (*check_error == 1)
		return (list_args);
	if (*check_error == -1)
	{
		i += 1;
		*check_error += 1;
	}
	while (list_args[i])
	{
		content = ft_atoi(list_args[i++]);
		if (content == 4000000000)
		{
			*check_error += 1;
			break ;
		}
	}
	return (list_args);
}

void	*ft_free_args(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	if (tab)
		free(tab);
	return (NULL);
}

long	ft_atoi(const char *str)
{
	int		i;
	int		s;
	long	res;

	i = 0;
	s = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || \
		str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		if ((res > 2147483648 && s == -1) || (res > 2147483647 && s == 1))
			return (4000000000);
		i++;
	}
	return (res * s);
}

int	check_argv_terminator(char **av)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) && \
			(av[i][j] != '-' && ft_isdigit(av[i][j + 1])))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
