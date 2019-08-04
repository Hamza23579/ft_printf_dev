/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 14:12:49 by hghandi           #+#    #+#             */
/*   Updated: 2019/08/01 14:12:50 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	writer_p(t_holder *hold)
{
	hold->string = ft_strjoin(hold->string, "0x");
	if ((hold->address = va_arg(hold->args, void *)) == NULL)
		hold->string = ft_strjoin(hold->string, "0");
	else
		hold->string = ft_strjoin(hold->string, ft_itoa_base((unsigned long long)hold->address, 16));
	hold->printble = ft_strlen(hold->string);
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
