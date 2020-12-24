/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <amuriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 13:11:53 by amuriel           #+#    #+#             */
/*   Updated: 2020/12/22 11:24:26 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_zero_struct(t_struct *check)
{
	check->width = 0;
	check->accuracy = -1;
	check->minus = 0;
	check->zero = 0;
	check->dot = 0;
	check->flag = 0;
	check->sign = 0;
	check->type = 0;
}

void	ft_check_flag(const char *fmt, t_struct *check)
{
	if (fmt[check->i] == '-')
		check->minus = 1;
	else if (fmt[check->i] == '0')
		check->zero = 1;
}

void	ft_check_width(const char *fmt, t_struct *check)
{
	if (fmt[check->i] == '*')
	{
		check->width = va_arg(check->ap, int);
		check->i++;
		if (check->width < 0)
		{
			check->width = check->width * -1;
			check->minus = 1;
		}
	}
	else
		check->width = ft_atoi_new(fmt, check);
}

void	ft_check_accuracy(const char *fmt, t_struct *check)
{
	int i;

	if (fmt[check->i] == '*')
	{
		i = check->i;
		check->accuracy = va_arg(check->ap, int);
		check->i++;
	}
	else
		check->accuracy = ft_atoi_new(fmt, check);
	if (check->minus != 0 && fmt[i - 1] == 0)
	{
		check->width = check->accuracy;
		check->accuracy = 0;
	}
	if (check->accuracy >= 0)
		check->zero = 0;
}

void	ft_conclusion_type(const char *fmt, t_struct *check)
{
	if (fmt[check->i] == 'c' || fmt[check->i] == '%')
		ft_conclusion_char(fmt[check->i], check);
	else if (fmt[check->i] == 's')
		ft_conclusion_string(check);
	else if (fmt[check->i] == 'i' || fmt[check->i] == 'd')
		ft_conclusion_int(check);
	else if (fmt[check->i] == 'u')
	{
		check->type = 'u';
		ft_conclusion_unsigned(check);
	}
	else if (fmt[check->i] == 'p')
	{
		check->type = 'x';
		ft_conclusion_pointer(check);
	}
	else if (fmt[check->i] == 'x' || fmt[check->i] == 'X')
	{
		check->type = fmt[check->i] == 'x' ? 'x' : 'X';
		ft_conclusion_hex(check);
	}
	ft_zero_struct(check);
}
