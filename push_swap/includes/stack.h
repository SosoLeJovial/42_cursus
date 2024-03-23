/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:30:01 by tsofien-          #+#    #+#             */
/*   Updated: 2024/03/23 02:16:34 by tsofien-         ###   ########.fr       */
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
	size_t			rank;
	struct pile		*prev;
	struct pile		*next;
}	t_pile;

int		ft_stack_init(char **list_arg, int *error, t_pile **stack_a, char **argv);
int		ft_isduplicate(t_pile *stack, int *error);
void	add_index(t_pile **stack);
void	rank(t_pile **stack);
void	rank_stack(t_pile **stack);
int		push_swap(t_pile *stack_a, t_pile *stack_b, int *error, char **list_args, char **argv);
t_pile	*ft_lstnew(int value);
int		ft_lstadd_front(t_pile **lst, t_pile *new);
int		ft_lstadd_back(t_pile **lst, t_pile *new);
void	ft_lstclear(t_pile **lst, void (*del)(int));
#endif