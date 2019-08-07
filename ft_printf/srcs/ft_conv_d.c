/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <hghandi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:58:57 by hghandi           #+#    #+#             */
/*   Updated: 2019/08/06 14:58:58 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_hash_and_count(t_holder *hold)
{
	hold->size_str = (hold->precision == 0 && hold->number == 0)
	? 0 : hold->printble;
	if (contains(hold->options_, '#') != -1 && hold->precision == 0 &&
		hold->number == 0 && contains(hold->conver_opts, '.') != -1 &&
		contains(hold->conver_opts, 'o') != -1)
	{
		hold->size_str = 1;
		hold->printble--;
	}
	hold->count += hold->printble;
	printable(hold);
}

void	ft_precision(t_holder *hold)
{
	int i;

	i = 0;
	if (contains(hold->conver_opts, 'o') != -1 ||
		contains(hold->conver_opts, 'u') != -1 ||
		contains(hold->conver_opts, 'x') != -1 ||
		contains(hold->conver_opts, 'X') != -1)
		extract_number_o_u_x_x(hold);
	else
		extract_number(hold);
	hold->printble = hold->size_str;
	while (i < hold->precision - hold->size_str)
	{
		hold->string = ft_strjoin("0", hold->string);
		hold->printble++;
		i++;
	}
	ft_hash_and_count(hold);
}

void	print_noraml(t_holder *hold)
{
	if (contains(hold->options_, '0') != -1 &&
		contains(hold->conver_opts, '.') == -1)
	{
		print_sign(hold);
		print_zeros(hold);
		write(1, hold->string, hold->size_str);
	}
	else
	{
		if (hold->size_str == 0)
		{
			hold->width++;
			hold->count--;
		}
		print_space(hold);
		print_sign(hold);
		write(1, hold->string, hold->size_str);
	}
}

void	writer_d(t_holder *hold)
{
	ft_precision(hold);
	if (contains(hold->options_, '-') != -1)
	{
		print_sign(hold);
		if (hold->size_str == 0)
		{
			hold->width++;
			hold->count--;
		}
		write(1, hold->string, hold->size_str);
		print_space(hold);
	}
	else
		print_noraml(hold);
}
