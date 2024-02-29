/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:19:05 by tsofien-          #+#    #+#             */
/*   Updated: 2024/02/29 16:06:38 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

int ft_atoi(const char *nptr);
int ft_isdigit(int c);
int ft_isint(int number);
int ft_sanitize(int number);
int ft_sanistize_args(int argc, char **argv);
#endif