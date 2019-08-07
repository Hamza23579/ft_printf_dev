/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <hghandi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:59:10 by hghandi           #+#    #+#             */
/*   Updated: 2019/08/06 14:59:41 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	writer_c2(t_holder *hold, int indicator)
{
	int		j;

	j = 0;
	if (indicator == 1)
	{
		while (j < ft_atoi(hold->conver_opts) * (-1) - 1)
		{
			write(1, " ", 1);
			hold->count++;
			j += 1;
		}
	}
	else
	{
		while (j < ft_atoi(hold->conver_opts) - 1)
		{
			write(1, " ", 1);
			hold->count++;
			j += 1;
		}
	}
}

void	writer_c(t_holder *hold)
{
	int		c;
	int		indicator;

	indicator = 0;
	c = va_arg(hold->args, int);
	if (contains(hold->options_, '-') != -1)
	{
		indicator = 1;
		write(1, &c, 1);
		hold->count++;
		writer_c2(hold, indicator);
	}
	else
	{
		writer_c2(hold, indicator);
		write(1, &c, 1);
		hold->count++;
	}
}
