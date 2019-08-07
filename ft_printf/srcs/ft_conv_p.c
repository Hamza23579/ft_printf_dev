/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <hghandi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:59:21 by hghandi           #+#    #+#             */
/*   Updated: 2019/08/06 14:59:35 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		check_opt(char c)
{
	if (contains(FLAGS, c) != -1)
		return (1);
	return (0);
}

int		contains(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	writer_p(t_holder *hold)
{
	hold->string = ft_strjoin(hold->string, "0x");
	if ((hold->address = va_arg(hold->args, void *)) == NULL)
		hold->string = ft_strjoin(hold->string, "0");
	else
		hold->string = ft_strjoin(hold->string,
			ft_itoa_base((unsigned long long)hold->address, 16));
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
