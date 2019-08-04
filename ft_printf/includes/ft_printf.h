/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 22:37:52 by hghandi           #+#    #+#             */
/*   Updated: 2019/07/28 22:37:55 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define	flags "cspdiouxXf%"
#define	options "-+#0 "
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "../srcs/libft/libft.h"


typedef struct s_holder
{
	char	*format;
	char	*conver_opts;
	char	*options_;
	char	*width;
	int		end_of_width;
	char	*precision;
	int		count;
	int		size_str;
	int		printble;
	char	*string;
	char	c;
	long long int	number;
	void	*address;
	int		sign;
	va_list	args;

}	t_holder;

int		parse(t_holder *hold);
void	writer_c(t_holder *hold);
void	writer_s(t_holder *hold);
void	writer_p(t_holder *hold);
void	writer_d(t_holder *hold);
void	writer_s2(t_holder *hold);
int		contains(char *str, char c);
int		check_opt(char c);
void	ft_analyse(char *conver_opt, t_holder *hold);
void	ft_initializer(t_holder *hold);
char	*ft_itoa_base(unsigned long long int value, int base);
