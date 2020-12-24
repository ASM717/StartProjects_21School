/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <amuriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 17:21:19 by amuriel           #+#    #+#             */
/*   Updated: 2020/12/23 17:25:04 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			ft_zero_null(t_struct *check)
{
	check->zero = 0;
	check->minus = 1;
}

void			ft_acc_dec_else(const char *str, t_struct *check)
{
	if (check->sign)
		check->width--;
	if (ft_strlen(str) < check->width)
		ft_print_space(str, check);
	if (check->sign)
		check->width++;
	if (check->sign)
		ft_print_sign(check);
	ft_printing_dec(str, check);
}

static int		ft_length(unsigned int num)
{
	size_t length;

	length = 0;
	while (num >= 10)
	{
		num /= 10;
		length++;
	}
	return (length + 1);
}

char			*ft_itoa_new(long long int n, t_struct *check)
{
	size_t	i;

	i = 0;
	check->nbr = n;
	check->nbr = n < 0 ? check->nbr * -1 : check->nbr;
	check->length = ft_length(check->nbr);
	if (!(check->str = (char *)malloc(sizeof(char) * (check->length + 1))))
		return (NULL);
	if (n < 0)
		check->sign = 1;
	i = check->length - 1;
	while (check->nbr != 0)
	{
		*(check->str + i) = check->nbr % 10 + 48;
		i--;
		check->nbr /= 10;
	}
	if (n == 0 && check->accuracy != 0)
		check->str[0] = '0';
	if (check->accuracy == 0 && n == 0)
		check->length = 0;
	else if (ft_strlen(check->str) == 0 && check->type)
		check->str[0] = '0';
	*(check->str + check->length) = '\0';
	return (check->str);
}
