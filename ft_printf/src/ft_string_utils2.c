/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <amuriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 16:29:49 by amuriel           #+#    #+#             */
/*   Updated: 2020/12/23 17:16:28 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_acc_inc_else_width(t_struct *check)
{
	int k;

	k = 0;
	while (k < ((check->width)))
	{
		write(1, " ", 1);
		check->count++;
		k++;
	}
}

void	ft_acc_inc_else_width_len(const char *str, t_struct *check)
{
	int k;

	k = 0;
	while (k < ((check->width - ft_strlen(str))))
	{
		write(1, " ", 1);
		check->count++;
		k++;
	}
}
