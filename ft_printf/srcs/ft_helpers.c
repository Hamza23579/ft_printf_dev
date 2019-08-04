/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 16:47:38 by hghandi           #+#    #+#             */
/*   Updated: 2019/07/30 16:47:40 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		check_opt(char c)
{
	if (contains(flags, c) != -1)
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

void	ft_initializer(t_holder *hold)
{
	hold->options_ = "";
	hold->width = "0";
	hold->precision = "-1";
	hold->string = "";
	hold->end_of_width = 0;
	hold->printble = 0;
	hold->sign = 0;
}

char	*ft_itoa_base(unsigned long long int value, int base)
{
	const	char	*hex = "0123456789abcdef";
	int				modulo;
	char			*str;

	str = "";
	if (value == 0)
	{
		str = ft_strjoin(str, "0");
		return (str);
	}
	while (value > 0)
	{
		modulo = value % base;
		str = ft_strjoin(str, ft_strsub(hex, modulo, 1));
		value /= base;
	}
	str = ft_strrev(str);
	return (str);
}

void	ft_analyse(char *conver_opt, t_holder *hold)
{
	int		i;
	int		j;

	i = 0;
	ft_initializer(hold);
	if ((j = contains(conver_opt, '.') + 1) != 0)
	{
		hold->precision = "";
		while (ft_isdigit(conver_opt[j]))
					hold->precision = ft_strjoin(hold->precision, ft_strsub(conver_opt, j++, 1));
	}
	while (conver_opt[i] != '\0')
	{
		if (contains(options, conver_opt[i]) != -1)
			hold->options_ = ft_strjoin(hold->options_, ft_strsub(conver_opt, i, 1));
		if (conver_opt[i] == '.')
			hold->end_of_width = -1;
		if (conver_opt[i - 1] != '.')
		{
			if (ft_isdigit(conver_opt[i]) && hold->end_of_width != -1)
			{
				if (!ft_isdigit(conver_opt[i + 1]))
					hold->end_of_width = -1;
				hold->width = ft_strjoin(hold->width, ft_strsub(conver_opt, i, 1));
			}
		}
		i++;
	}
}
