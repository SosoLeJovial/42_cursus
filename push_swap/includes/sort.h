/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:27:11 by tsofien-          #+#    #+#             */
/*   Updated: 2024/03/24 19:24:36 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "./stack.h"
# include "./operations.h"
# include <stdio.h>

void    which_sort(size_t stack_length, t_pile **stack_a, t_pile **stack_b);
void	sort_two(t_pile **stack);
void	sort_three(t_pile **stack);
void	sort_five(t_pile **stack_a, t_pile **stack_b);
void	which_index(t_pile *tmp, t_pile **a, t_pile **b);
void	push_small_b(t_pile **a, t_pile **b);
int		find_smallest(t_pile **stack);
#endif