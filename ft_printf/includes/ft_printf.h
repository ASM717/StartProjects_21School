/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <amuriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 13:12:19 by amuriel           #+#    #+#             */
/*   Updated: 2020/12/23 17:30:24 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define CONVERSIONS "cpsdiuxX%"
# define S_BASE_X "0123456789abcdef"
# define S_BASE_XX "0123456789ABCDEF"

typedef struct		s_struct
{
	va_list			ap;
	int				width;
	int				accuracy;
	int				minus;
	int				zero;
	int				dot;
	int				count;
	int				i;
	int				flag;
	int				sign;
	char			type;
	char			*str;
	size_t			length;
	long long int	nbr;
	char			*str_b;
	size_t			length_b;
	unsigned long	nbr_b;
	char			*s_base_x;
	size_t			i_base;
}					t_struct;

int					ft_printf(const char *fmt, ...);
void				ft_zero_struct(t_struct *check);
void				ft_zero_null(t_struct *check);
void				ft_check_flag(const char *fmt, t_struct *check);
void				ft_check_width(const char *fmt, t_struct *check);
void				ft_check_accuracy(const char *fmt, t_struct *check);
void				ft_conclusion_type(const char *fmt, t_struct *check);
void				ft_conclusion_char(char c, t_struct *check);
void				ft_conclusion_string(t_struct *check);
void				ft_conclusion_int(t_struct *check);
void				ft_conclusion_unsigned(t_struct *check);
void				ft_conclusion_pointer(t_struct *check);
void				ft_conclusion_hex(t_struct *check);

int					ft_strchr_new(int c, const char *str);
int					ft_atoi_new(const char *fmt, t_struct *check);
char				*ft_itoa_new(long long int n, t_struct *check);
char				*ft_itoa_base(unsigned long n, t_struct *check);
void				ft_char_minus_zero(int i, t_struct *check);
void				ft_write_space(int n);
void				ft_write_zero(int n);

void				ft_printing_inc(const char *str, t_struct *check);
void				ft_printing_dec(const char *str, t_struct *check);
void				ft_accuracy_dec_minus(const char *str, t_struct *check);
void				ft_accuracy_dec_else(const char *str, t_struct *check);
void				ft_accuracy_inc_zero(t_struct *check);
void				ft_accuracy_inc_minus(const char *str, t_struct *check);
void				ft_accuracy_inc_else(const char *str, t_struct *check);
void				ft_acc_inc_else_width(t_struct *check);
void				ft_acc_inc_else_width_len(const char *str, t_struct *check);
void				ft_signed(t_struct *check);
void				ft_print_sign(t_struct *check);
void				ft_print_space(const char *str, t_struct *check);
void				ft_print_zero_acc(const char *str, t_struct *check);
void				ft_print_zero(const char *str, t_struct *check);
void				ft_acc_inc_minus(const char *str, t_struct *check);
void				ft_acc_inc_else(const char *str, t_struct *check);
void				ft_acc_dec_zero(const char *str, t_struct *check);
void				ft_acc_dec_minus(const char *str, t_struct *check);
void				ft_acc_dec_else(const char *str, t_struct *check);
void				ft_acc_inc_else_p(const char *str, t_struct *check);
void				ft_acc_inc_minus_p(const char *str, t_struct *check);
void				ft_acc_dec_else_p(const char *str, t_struct *check);
void				ft_acc_dec_minus_p(const char *str, t_struct *check);
void				ft_acc_dec_zero_p(const char *str, t_struct *check);
void				ft_print_space_p(const char *str, t_struct *check);
void				ft_printing_dec_p(const char *str, t_struct *check);
void				ft_print_zero_acc_p(const char *str, t_struct *check);
void				ft_print_zero_p(const char *str, t_struct *check);

#endif
