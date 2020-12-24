/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <amuriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 17:29:29 by amuriel           #+#    #+#             */
/*   Updated: 2020/12/23 17:23:49 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_acc_dec_zero_p(const char *str, t_struct *check)
{
	ft_printing_dec_p(str, check);
	if (ft_strlen(str) < check->width)
		ft_print_zero_p(str, check);
	if (check->zero == 1)
		ft_printing_dec(str, check);
}

void	ft_printing_dec_p(const char *str, t_struct *check)
{
	write(1, "0x", 2);
	check->count += 2;
	if (ft_strlen(str) < check->accuracy)
		ft_print_zero_acc_p(str, check);
	if (check->zero == 0)
		ft_printing_dec(str, check);
	if (check->zero == 1 && ft_strlen(str) > check->width && ft_strlen(str)
	>= check->accuracy)
		ft_printing_dec(str, check);
}

void	ft_acc_dec_minus_p(const char *str, t_struct *check)
{
	ft_printing_dec_p(str, check);
	if (ft_strlen(str) < check->width)
		ft_print_space_p(str, check);
}

void	ft_acc_dec_else_p(const char *str, t_struct *check)
{
	if (ft_strlen(str) < check->width)
		ft_print_space_p(str, check);
	ft_printing_dec_p(str, check);
}

void	ft_print_space_p(const char *str, t_struct *check)
{
	int i;
	int j;
	int f;

	j = 0;
	f = ft_strlen(str);
	if (f > check->accuracy)
		i = ft_strlen(str);
	else
		i = check->accuracy;
	if (check->width > i)
		check->width = check->width;
	else
		check->width = i;
	while (j < ((check->width - 2) - i))
	{
		write(1, " ", 1);
		check->count++;
		j++;
	}
}
