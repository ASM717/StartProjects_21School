/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <amuriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 18:15:19 by amuriel           #+#    #+#             */
/*   Updated: 2020/12/23 17:28:17 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_default_struct(t_struct *check)
{
	check->width = 0;
	check->accuracy = -1;
	check->minus = 0;
	check->zero = 0;
	check->dot = 0;
	check->i = 0;
	check->flag = 0;
	check->sign = 0;
	check->type = 0;
	check->count = 0;
}

static void	ft_check_dot_minus(const char *fmt, t_struct *check)
{
	check->dot = 1;
	check->accuracy = 0;
	check->i++;
	if (fmt[check->i] == '-')
	{
		check->minus = 1;
		check->width = ft_atoi_new(fmt, check);
		check->dot = 0;
	}
}

static void	ft_parsing(const char *fmt, t_struct *check)
{
	check->i++;
	check->dot = 0;
	while (fmt[check->i] && ft_strchr_new(fmt[check->i], CONVERSIONS) == 0)
	{
		if (fmt[check->i] == '0' || fmt[check->i] == '-')
		{
			if (fmt[check->i - 1] == '%')
				ft_check_flag(fmt, check);
			if (fmt[check->i] == '0' && fmt[check->i + 1] == '-')
				ft_zero_null(check);
			check->i++;
		}
		else if (check->dot == 0 && (ft_isdigit(fmt[check->i]) || fmt[check->i]
				== '*'))
			ft_check_width(fmt, check);
		else if (fmt[check->i] == '.')
			ft_check_dot_minus(fmt, check);
		else if (check->dot && (ft_isdigit(fmt[check->i]) || fmt[check->i] ==
		'*'))
			ft_check_accuracy(fmt, check);
		else
			check->i++;
	}
}

static void	ft_output(const char *fmt, t_struct *check)
{
	while (fmt[check->i])
	{
		if (check->flag == 0 && fmt[check->i] == '%' && fmt[check->i + 1])
		{
			check->flag = 1;
			ft_parsing(fmt, check);
		}
		else if (check->flag == 1 && ft_strchr_new(fmt[check->i], CONVERSIONS))
		{
			ft_conclusion_type(fmt, check);
			check->i++;
			check->flag = 0;
		}
		else
		{
			write(1, &fmt[check->i], 1);
			check->count++;
			check->i++;
		}
	}
}

int			ft_printf(const char *fmt, ...)
{
	t_struct	*check;
	int			count;

	count = 0;
	if (!fmt || !(check = (t_struct *)malloc(sizeof(t_struct))))
		return (0);
	ft_default_struct(check);
	va_start(check->ap, fmt);
	ft_output(fmt, check);
	count = check->count;
	va_end(check->ap);
	free(check);
	return (count);
}
