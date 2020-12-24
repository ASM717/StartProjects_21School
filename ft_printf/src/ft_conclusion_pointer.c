/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conclusion_pointer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <amuriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 17:28:06 by amuriel           #+#    #+#             */
/*   Updated: 2020/12/23 17:22:54 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_zero_p(const char *str, t_struct *check)
{
	int i;
	int j;

	j = 0;
	if (ft_strlen(str) < check->accuracy)
		i = ft_strlen(str);
	else
		i = check->accuracy;
	i = i > ft_strlen(str) ? i : ft_strlen(str);
	while ((j < ((check->width - 2) - i)) && check->minus == 0)
	{
		write(1, "0", 1);
		check->count++;
		j++;
	}
}

void	ft_print_zero_acc_p(const char *str, t_struct *check)
{
	int i;

	i = 0;
	while (i < check->accuracy - ft_strlen(str))
	{
		write(1, "0", 1);
		check->count++;
		i++;
	}
}

void	ft_acc_inc_else_p(const char *str, t_struct *check)
{
	if (ft_strlen(str) < check->width)
		ft_print_space_p(str, check);
	ft_printing_dec_p(str, check);
}

void	ft_acc_inc_minus_p(const char *str, t_struct *check)
{
	if (ft_strlen(str) < check->accuracy)
		ft_print_zero_acc(str, check);
	ft_printing_dec_p(str, check);
	if (ft_strlen(str) < check->width)
		ft_print_space_p(str, check);
}

void	ft_conclusion_pointer(t_struct *check)
{
	long long int	nbr;
	const char		*str;

	nbr = va_arg(check->ap, unsigned long);
	str = (const char *)ft_itoa_base(nbr, check);
	if (check->accuracy > 0)
	{
		if (check->minus)
			ft_acc_inc_minus_p(str, check);
		else
			ft_acc_inc_else_p(str, check);
	}
	else
	{
		if (check->zero && !check->minus)
			ft_acc_dec_zero_p(str, check);
		else if (check->minus)
			ft_acc_dec_minus_p(str, check);
		else
			ft_acc_dec_else_p(str, check);
	}
	free((char*)str);
}
