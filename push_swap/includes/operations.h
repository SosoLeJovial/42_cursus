/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:28:06 by tsofien-          #+#    #+#             */
/*   Updated: 2024/03/26 00:30:27 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H
# include "stack.h"

void	which_push(char c, t_pile **stack_a, t_pile **stack_b);
void	which_rotate(char c, t_pile **stack_a, t_pile **stack_b);
void	which_swap(char c, t_pile **stack_a, t_pile **stack_b);
void	which_reverse_rotate(char c, t_pile **stack_a, t_pile **stack_b);
void	push(t_pile **src, t_pile **dst);
void	rotate(t_pile **stack);
void	swap(t_pile **stack);
void	reverse_rotate(t_pile **stack);
#endif