/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conclusion_unsigned.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <amuriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 17:24:38 by amuriel           #+#    #+#             */
/*   Updated: 2020/12/23 14:28:50 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_conclusion_unsigned(t_struct *check)
{
	long long	int		nbr;
	const		char	*str;

	nbr = va_arg(check->ap, unsigned int);
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
