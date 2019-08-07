/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <hghandi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:26:27 by hghandi           #+#    #+#             */
/*   Updated: 2019/08/06 15:34:01 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pre_extract_number(t_holder *hold)
{
	if (ft_strstr(hold->conver_opts, "ll"))
		hold->number = va_arg(hold->args, unsigned long long int);
	else if (ft_strstr(hold->conver_opts, "l"))
		hold->number = va_arg(hold->args, unsigned long int);
	else if (ft_strstr(hold->conver_opts, "hh"))
		hold->number = (unsigned char)va_arg(hold->args, unsigned int);
	else if (ft_strstr(hold->conver_opts, "h"))
		hold->number = (unsigned short int)va_arg(hold->args, int);
	else
		hold->number = va_arg(hold->args, unsigned int);
}

void	extract_number_o_u_x_x(t_holder *hold)
{
	pre_extract_number(hold);
	if (contains(hold->conver_opts, 'o') != -1)
		hold->string = ft_strjoin(hold->string, ft_itoa_base(hold->number, 8));
	else if (contains(hold->conver_opts, 'x') != -1 ||
		contains(hold->conver_opts, 'X') != -1)
	{
		hold->string = ft_strjoin(hold->string, ft_itoa_base(hold->number, 16));
		if (contains(hold->conver_opts, 'X') != -1)
			hold->string = ft_struppercase(hold->string);
	}
	else
		hold->string = ft_strjoin(hold->string, ft_itoa_base(hold->number, 10));
	if ((contains(hold->options_, '#') != -1 && hold->number != 0 &&
		contains(hold->conver_opts, 'o') != -1) ||
		(contains(hold->options_, '#') != -1 && contains(hold->conver_opts, '.')
			!= -1 && hold->number == 0 &&
			contains(hold->conver_opts, 'o') != -1))
		hold->string = ft_strjoin("0", hold->string);
	hold->size_str = ft_strlen(hold->string);
}

void	write_0x(t_holder *hold)
{
	if (contains(hold->conver_opts, 'X') != -1)
		write(1, "0X", 2);
	else
		write(1, "0x", 2);
	hold->count += 2;
}

void	ft_putspace(t_holder *hold)
{
	if (contains(hold->options_, ' ') != -1)
	{
		write(1, " ", 1);
		hold->count++;
	}
}

void	print_sign(t_holder *hold)
{
	if (contains(hold->options_, '+') != -1 && hold->number >= 0 &&
		contains(hold->conver_opts, 'o') == -1)
	{
		write(1, "+", 1);
		hold->count++;
	}
	else if (hold->number < 0 && contains(hold->conver_opts, 'o') == -1 &&
		contains(hold->conver_opts, 'u') == -1 &&
		contains(hold->conver_opts, 'x') == -1 &&
		contains(hold->conver_opts, 'X') == -1)
	{
		write(1, "-", 1);
		hold->count++;
	}
	else if ((contains(hold->conver_opts, 'x') != -1 ||
		contains(hold->conver_opts, 'X') != -1) &&
		contains(hold->options_, '#') != -1 && hold->number != 0)
		write_0x(hold);
	else
	{
		ft_putspace(hold);
	}
}
