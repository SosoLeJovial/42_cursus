/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 21:26:54 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/06 19:35:53 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <math.h>
# define WIDTH 256
# define HEIGHT 256

/**
 * Main MLX handle, carries important data in regards to the program.
 * @param mlx_ptr MLX pointer
 * @param win_ptr MLX window pointer
 * @param textures MLX image pointers
 * @param map Map pointer (contains map details - preferably kept on the stack)
 */
typedef struct data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*textures[5];
	char		**map;
}	t_data;

/*Parsing - utils*/
char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
int		ft_map_valid(const char *path);
int		ft_check_char(int fd);

#endif