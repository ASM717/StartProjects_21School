/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <amuriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 12:58:07 by amuriel           #+#    #+#             */
/*   Updated: 2020/12/23 17:19:38 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_length_base(unsigned long num)
{
	size_t length;

	length = 0;
	while (num >= 16)
	{
		num /= 16;
		length++;
	}
	return (length + 1);
}

char			*ft_itoa_base(unsigned long n, t_struct *check)
{
	check->i_base = 0;
	check->nbr_b = n;
	check->s_base_x = check->type == 'x' ? S_BASE_X : S_BASE_XX;
	check->nbr_b = n < 0 ? check->nbr_b * -1 : check->nbr_b;
	check->length_b = ft_length_base(check->nbr_b);
	if (!(check->str_b = (char *)malloc(sizeof(char) * (check->length_b + 1))))
		return (NULL);
	if (n < 0)
		check->sign = 1;
	check->i_base = check->length_b;
	while (check->nbr_b != 0 && check->i_base--)
	{
		*(check->str_b + check->i_base) = check->s_base_x[check->nbr_b % 16];
		check->nbr_b /= 16;
	}
	if (ft_strlen(check->str_b) == 0 && check->type && check->accuracy != 0)
		check->str_b[0] = '0';
	if (n == 0 && check->accuracy != 0)
		check->str_b[0] = '0';
	if (check->accuracy == 0 && n == 0)
		check->length_b = 0;
	else if (ft_strlen(check->str_b) == 0 && check->type)
		check->str_b[0] = '0';
	*(check->str_b + check->length_b) = '\0';
	return (check->str_b);
}
