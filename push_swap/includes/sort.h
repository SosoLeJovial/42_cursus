/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:27:11 by tsofien-          #+#    #+#             */
/*   Updated: 2024/03/24 01:03:43 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "./stack.h"

void    which_sort(size_t stack_length, t_pile **stack_a, t_pile **stack_b);
void	sort_two(t_pile **stack);
void	sort_three(t_pile **stack);
#endif