/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:30:01 by tsofien-          #+#    #+#             */
/*   Updated: 2024/02/23 00:32:07 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct pile
{
	struct pile		*prev;
	int				value;
	size_t			index;
	struct pile		*next;
}	t_pile;

t_pile	*ft_lstnew(int value);
void	ft_lstadd_front(t_pile **lst, t_pile *new);
void	ft_lstadd_back(t_pile **lst, t_pile *new);
#endif