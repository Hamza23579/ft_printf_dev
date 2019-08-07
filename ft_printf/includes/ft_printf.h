/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <hghandi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 22:37:52 by hghandi           #+#    #+#             */
/*   Updated: 2019/08/05 21:42:19 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FLAGS "cspdiouxXf%"
# define OPTIONS "-+#0 "
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include "../srcs/libft/libft.h"

typedef struct		s_holder
{
	char			*format;
	char			*conver_opts;
	char			*options_;
	int				width;
	int				end_of_width;
	int				precision;
	int				count;
	int				size_str;
	int				printble;
	char			*string;
	char			c;
	long long int	number;
	void			*address;
	int				sign;
	int				is_printed;
	va_list			args;

}					t_holder;

int					ft_printf(char *format, ...);
int					parse(t_holder *hold);
void				writer_c(t_holder *hold);
void				writer_s(t_holder *hold);
void				writer_p(t_holder *hold);
void				writer_d(t_holder *hold);
void				writer_s2(t_holder *hold);
int					contains(char *str, char c);
int					check_opt(char c);
void				ft_analyse(char *conver_opt, t_holder *hold);
void				ft_initializer(t_holder *hold);
char				*ft_itoa_base(unsigned long long int value, int base);
void				extract_number(t_holder *hold);
void				print_space(t_holder *hold);
void				print_zeros(t_holder *hold);
void				print_sign(t_holder *hold);
void				printable(t_holder *hold);
void				extract_number_o_u_x_x(t_holder *hold);

#endif
