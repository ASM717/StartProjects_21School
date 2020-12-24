/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conclusion_integer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <amuriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 17:17:09 by amuriel           #+#    #+#             */
/*   Updated: 2020/12/22 16:06:29 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_acc_inc_minus(const char *str, t_struct *check)
{
	if (check->sign)
		ft_print_sign(check);
	if (ft_strlen(str) < check->accuracy)
		ft_print_zero_acc(str, check);
	ft_printing_dec(str, check);
	if (ft_strlen(str) < check->width)
		ft_print_space(str, check);
}

void	ft_acc_inc_else(const char *str, t_struct *check)
{
	ft_signed(check);
	if (ft_strlen(str) < check->width)
		ft_print_space(str, check);
	ft_signed(check);
	if (check->sign)
		ft_print_sign(check);
	if (ft_strlen(str) < check->accuracy)
		ft_print_zero_acc(str, check);
	ft_printing_dec(str, check);
}

void	ft_acc_dec_zero(const char *str, t_struct *check)
{
	if (check->sign)
		ft_print_sign(check);
	if (ft_strlen(str) < check->width)
		ft_print_zero(str, check);
	ft_printing_dec(str, check);
}

void	ft_acc_dec_minus(const char *str, t_struct *check)
{
	if (check->sign)
		ft_print_sign(check);
	ft_printing_dec(str, check);
	if (ft_strlen(str) < check->width)
		ft_print_space(str, check);
}

void	ft_conclusion_int(t_struct *check)
{
	int			nbr;
	const char	*str;

	nbr = va_arg(check->ap, int);
	str = (const char *)ft_itoa_new(nbr, check);
	if (check->accuracy > 0)
	{
		if (check->minus)
			ft_acc_inc_minus(str, check);
		else
			ft_acc_inc_else(str, check);
	}
	else
	{
		if (check->zero && !check->minus)
			ft_acc_dec_zero(str, check);
		else if (check->minus)
			ft_acc_dec_minus(str, check);
		else
			ft_acc_dec_else(str, check);
	}
	free((char*)str);
}
