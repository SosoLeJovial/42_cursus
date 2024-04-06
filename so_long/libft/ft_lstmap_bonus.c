/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:28:38 by tsofien-          #+#    #+#             */
/*   Updated: 2023/11/27 23:28:19 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*tmp;

	first = (t_list *)malloc(sizeof(t_list));
	if (!first || !lst || !f || !del)
		return (NULL);
	first->content = f(lst->content);
	tmp = first;
	while (lst->next)
	{
		tmp->next = (t_list *)malloc(sizeof(t_list));
		if (!tmp->next)
			return (ft_lstclear(&first, del), NULL);
		tmp = tmp->next;
		lst = lst->next;
		tmp->content = f(lst->content);
	}
	tmp->next = NULL;
	return (first);
}
