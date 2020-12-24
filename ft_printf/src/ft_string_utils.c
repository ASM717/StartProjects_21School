/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <amuriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 17:15:40 by amuriel           #+#    #+#             */
/*   Updated: 2020/12/23 17:16:37 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_accuracy_dec_minus(const char *str, t_struct *check)
{
	int k;
	int t;

	k = 0;
	t = check->width - ft_strlen(str);
	if (check->width < ft_strlen(str))
	{
		while (k < t)
		{
			write(1, " ", 1);
			check->count++;
			k++;
		}
	}
	else if (check->width > ft_strlen(str))
	{
		while (k < check->width - ft_strlen(str))
		{
			write(1, " ", 1);
			check->count++;
			k++;
		}
	}
}

void	ft_accuracy_dec_else(const char *str, t_struct *check)
{
	int j;

	j = 0;
	if (check->width > ft_strlen(str))
	{
		while (j < check->width - ft_strlen(str))
		{
			write(1, " ", 1);
			check->count++;
			j++;
		}
	}
}

void	ft_accuracy_inc_zero(t_struct *check)
{
	int i;

	i = 0;
	if (check->width > check->accuracy)
	{
		while (i < (check->width - check->accuracy))
		{
			write(1, "0", 1);
			check->count++;
			i++;
		}
	}
}

void	ft_accuracy_inc_minus(const char *str, t_struct *check)
{
	int j;
	int i;

	j = 0;
	i = 0;
	if (check->width >= check->accuracy)
	{
		i = check->accuracy > ft_strlen(str) ? ft_strlen(str) : check->accuracy;
		while (j < (check->width - i))
		{
			write(1, " ", 1);
			check->count++;
			j++;
		}
	}
	else if (check->width < check->accuracy)
	{
		i = ft_strlen(str);
		while (j < (check->width - i))
		{
			write(1, " ", 1);
			check->count++;
			j++;
		}
	}
}

void	ft_accuracy_inc_else(const char *str, t_struct *check)
{
	int k;
	int i;

	k = 0;
	i = 0;
	if (check->width >= check->accuracy)
	{
		i = check->accuracy > ft_strlen(str) ? ft_strlen(str) : check->accuracy;
		while (k < ((check->width - i)))
		{
			write(1, " ", 1);
			check->count++;
			k++;
		}
	}
	else if (check->width < check->accuracy && str[0] == '\0')
		ft_acc_inc_else_width(check);
	else if (check->width < check->accuracy && ft_strlen(str) < check->width)
		ft_acc_inc_else_width_len(str, check);
}
