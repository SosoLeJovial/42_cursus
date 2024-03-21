/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:30:01 by tsofien-          #+#    #+#             */
/*   Updated: 2024/03/21 11:27:27 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct pile
{
	int				value;
	size_t			index;
	struct pile		*prev;
	struct pile		*next;
}	t_pile;

int		ft_stack_init(char **list_arg, int *error);
t_pile	*ft_lstnew(int value);
int		ft_lstadd_front(t_pile **lst, t_pile *new);
int		ft_lstadd_back(t_pile **lst, t_pile *new);
void	ft_lstclear(t_pile **lst, void (*del)(int));
#endif