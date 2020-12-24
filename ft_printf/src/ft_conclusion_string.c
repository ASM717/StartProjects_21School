/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conclusion_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <amuriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 17:14:15 by amuriel           #+#    #+#             */
/*   Updated: 2020/12/23 14:28:11 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printing_inc(const char *str, t_struct *check)
{
	int i;
	int q;

	i = 0;
	q = 0;
	if (check->accuracy < 0 || check->accuracy >= ft_strlen(str))
		q = ft_strlen(str);
	else if (check->accuracy >= 0 && check->accuracy < ft_strlen(str))
		q = check->accuracy;
	while (i < q)
	{
		write(1, &str[i], 1);
		check->count++;
		i++;
	}
}

void	ft_printing_dec(const char *str, t_struct *check)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		check->count++;
		i++;
	}
}

void	ft_accuracy_inc(const char *str, t_struct *check)
{
	if (check->zero)
	{
		ft_accuracy_inc_zero(check);
		ft_printing_inc(str, check);
	}
	else if (check->minus)
	{
		ft_printing_inc(str, check);
		ft_accuracy_inc_minus(str, check);
	}
	else
	{
		ft_accuracy_inc_else(str, check);
		ft_printing_inc(str, check);
	}
}

void	ft_accuracy_dec(const char *str, t_struct *check)
{
	if (check->zero)
	{
		if (check->width < ft_strlen(str))
			ft_printing_dec(str, check);
		else
		{
			while (check->width-- - ft_strlen(str))
				write(1, "0", 1);
			ft_printing_dec(str, check);
		}
	}
	else if (check->minus)
	{
		ft_printing_dec(str, check);
		ft_accuracy_dec_minus(str, check);
	}
	else
	{
		ft_accuracy_dec_else(str, check);
		ft_printing_dec(str, check);
	}
}

void	ft_conclusion_string(t_struct *check)
{
	const char	*str;
	int			i;

	i = 0;
	str = va_arg(check->ap, char *);
	if (!str)
		str = "(null)";
	if (check->accuracy < 0)
		ft_accuracy_dec(str, check);
	else if (check->accuracy > 0)
		ft_accuracy_inc(str, check);
	else
	{
		while (i < check->width)
		{
			if (check->zero)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			check->count++;
			i++;
		}
	}
}
