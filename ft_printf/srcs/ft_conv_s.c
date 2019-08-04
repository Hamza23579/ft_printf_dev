/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 16:46:33 by hghandi           #+#    #+#             */
/*   Updated: 2019/07/30 16:46:34 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	writer_s2(t_holder *hold)
{
	int		j;

	j = 0;
	if (ft_atoi(hold->width) > hold->printble)
	{
		while (j < ft_atoi(hold->width) - hold->printble)
		{
			write(1, " ", 1);
			hold->count++;
			j++;
		}
	}
}

void	writer_s(t_holder *hold)
{
	if ((hold->string = va_arg(hold->args, char *)) == NULL)
		hold->string = ft_strjoin(hold->string, "(null)");
	hold->size_str = ft_strlen(hold->string);
	if (contains(hold->conver_opts, '.') == -1)
		hold->printble = hold->size_str;
	else
		if (ft_atoi(hold->precision) > hold->size_str)
			hold->printble = hold->size_str;
		else if (ft_atoi(hold->precision) == 0)
			hold->printble = 0;
		else
			hold->printble = ft_atoi(hold->precision);
	if (contains(hold->options_, '-') != -1)
	{
		write(1, hold->string, hold->printble);
		writer_s2(hold);
		hold->count += hold->printble;
	}
	else
	{
		writer_s2(hold);
		write(1, hold->string, hold->printble);
		hold->count += hold->printble;
	}
}
