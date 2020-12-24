/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <amuriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 11:01:34 by amuriel           #+#    #+#             */
/*   Updated: 2020/12/21 14:13:51 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_write_space(int i)
{
	while (i > 0)
	{
		write(1, " ", 1);
		i--;
	}
}

void	ft_write_zero(int i)
{
	while (i > 0)
	{
		write(1, "0", 1);
		i--;
	}
}

void	ft_char_minus_zero(int i, t_struct *check)
{
	if (check->zero != 0)
		ft_write_zero(i);
	else if (check->zero == 0)
		ft_write_space(i);
}

int		ft_atoi_new(const char *fmt, t_struct *check)
{
	long long	result;

	result = 0;
	while (ft_isdigit(fmt[check->i]))
	{
		result = result * 10 + (fmt[check->i] - 48);
		check->i++;
	}
	return (result);
}

int		ft_strchr_new(int c, const char *str)
{
	int i;

	i = 0;
	while (*(str + i))
	{
		if (*(str + i) == (char)c)
			return (1);
		i++;
	}
	return (0);
}
