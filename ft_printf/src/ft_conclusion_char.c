/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conclusion_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <amuriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 17:12:26 by amuriel           #+#    #+#             */
/*   Updated: 2020/12/21 14:24:32 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_conclusion_char(char c, t_struct *check)
{
	int	i;

	i = 0;
	if (c == 'c')
		c = va_arg(check->ap, int);
	if (check->width != 0 && check->minus == 0)
	{
		i = check->width - 1;
		ft_char_minus_zero(i, check);
		write(1, &c, 1);
		check->count = check->count + i;
	}
	else if (check->width && check->minus == 1)
	{
		i = check->width - 1;
		write(1, &c, 1);
		ft_write_space(i);
		check->count = check->count + i;
	}
	else
		write(1, &c, 1);
	check->count++;
}
