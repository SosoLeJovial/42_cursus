/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 23:47:07 by tsofien-          #+#    #+#             */
/*   Updated: 2024/03/23 02:06:08 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"   

t_pile	*ft_lstnew(int value)
{
	t_pile	*lst;

	lst = malloc(sizeof(t_pile));
	if (!lst)
		return (NULL);
	lst->prev = NULL;
	lst->value = value;
	lst->next = NULL;
	return (lst);
}

int	ft_lstadd_front(t_pile **lst, t_pile *new)
{
	if (lst)
	{
		new->next = *lst;
		*lst = new;
		return (0);
	}
	else
		return (-1);
}

int	ft_lstadd_back(t_pile **lst, t_pile *new)
{
	t_pile	*tmp;

	if (!lst)
		return (-1);
	if (!*lst)
	{
		*lst = new;
		return (-1);
	}
	if (new)
	{
		tmp = (*lst);
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = new;
		new->prev = tmp;
		return (0);
	}
	return (-1);
}

void	ft_lstclear(t_pile **lst, void (*del)(int))
{
	t_pile	*tmp;

	if (lst && del)
	{
		while ((*lst))
		{
			tmp = (*lst)->next;
			del((*lst)->value);
			free((*lst));
			*lst = tmp;
		}
	}
}