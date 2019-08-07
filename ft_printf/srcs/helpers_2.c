/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <hghandi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:58:51 by hghandi           #+#    #+#             */
/*   Updated: 2019/08/06 14:58:54 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	extract_number(t_holder *hold)
{
	if (ft_strstr(hold->conver_opts, "ll"))
		hold->number = va_arg(hold->args, long long int);
	else if (ft_strstr(hold->conver_opts, "l"))
		hold->number = va_arg(hold->args, long int);
	else if (ft_strstr(hold->conver_opts, "hh"))
		hold->number = (char)va_arg(hold->args, int);
	else if (ft_strstr(hold->conver_opts, "h"))
		hold->number = (short)va_arg(hold->args, int);
	else
		hold->number = va_arg(hold->args, int);
	hold->string = ft_strjoin(hold->string, ft_itoa(hold->number));
	hold->size_str = ft_strlen(hold->string);
	if (hold->number < 0)
		hold->string = ft_strsub(hold->string, 1, hold->size_str - 1);
	hold->size_str = ft_strlen(hold->string);
}

void	print_space(t_holder *hold)
{
	int i;

	i = 0;
	while (i < hold->width - hold->printble)
	{
		write(1, " ", 1);
		hold->count++;
		i++;
	}
	hold->is_printed = 1;
}

void	print_zeros(t_holder *hold)
{
	int i;

	i = 0;
	while (i < hold->width - hold->printble)
	{
		write(1, "0", 1);
		hold->count++;
		i++;
	}
}

void	printable(t_holder *hold)
{
	if (contains(hold->options_, '+') != -1 && hold->number >= 0)
		hold->printble++;
	else if (hold->number < 0 && contains(hold->conver_opts, 'o') == -1 &&
		contains(hold->conver_opts, 'u') == -1 &&
		contains(hold->conver_opts, 'x') == -1 &&
		contains(hold->conver_opts, 'X') == -1)
		hold->printble++;
	else if ((contains(hold->conver_opts, 'x') != -1 ||
		contains(hold->conver_opts, 'X') != -1) &&
		contains(hold->options_, '#') != -1 && hold->number != 0)
		hold->printble += 2;
	else
	{
		if (contains(hold->options_, ' ') != -1 && !hold->is_printed)
			hold->printble++;
	}
}
