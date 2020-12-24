/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <amuriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 17:20:07 by amuriel           #+#    #+#             */
/*   Updated: 2020/12/21 10:51:31 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_signed(t_struct *check)
{
	if (check->sign)
		check->width--;
}

void	ft_print_sign(t_struct *check)
{
	write(1, "-", 1);
	check->count++;
	check->width--;
}

void	ft_print_zero_acc(const char *str, t_struct *check)
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

void	ft_print_space(const char *str, t_struct *check)
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
	while (j < (check->width - i))
	{
		write(1, " ", 1);
		check->count++;
		j++;
	}
}

void	ft_print_zero(const char *str, t_struct *check)
{
	int i;
	int j;

	j = 0;
	if (ft_strlen(str) < check->accuracy)
		i = ft_strlen(str);
	else
		i = check->accuracy;
	i = i > ft_strlen(str) ? i : ft_strlen(str);
	while (j < (check->width - i) && check->minus == 0)
	{
		write(1, "0", 1);
		check->count++;
		j++;
	}
}
