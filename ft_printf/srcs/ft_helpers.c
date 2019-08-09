/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <hghandi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:59:54 by hghandi           #+#    #+#             */
/*   Updated: 2019/08/06 14:59:56 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_initializer(t_holder *hold)
{
	hold->options_ = "";
	hold->width = 0;
	hold->precision = -1;
	hold->string = "";
	hold->end_of_width = 0;
	hold->printble = 0;
	hold->sign = 0;
	hold->is_printed = 0;
	hold->percent = 0;
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

void	ft_analyse_precision(char *conver_opt, t_holder *hold)
{
	char	*precision;
	int		j;

	j = 0;
	precision = "";
	ft_initializer(hold);
	if ((j = contains(conver_opt, '.') + 1) != 0)
		while (ft_isdigit(conver_opt[j]))
			precision = ft_strjoin(precision, ft_strsub(conver_opt, j++, 1));
	hold->precision = (ft_strcmp(precision, "") == 0 &&
		contains(conver_opt, '.') == -1) ? -1 : ft_atoi(precision);
}

void	ft_analyse(char *conver_opt, t_holder *hold)
{
	int		i;
	char	*width;

	i = 0;
	width = "";
	ft_analyse_precision(conver_opt, hold);
	while (conver_opt[i] != '\0')
	{
		if (contains(OPTIONS, conver_opt[i]) != -1)
			hold->options_ = ft_strjoin(hold->options_,
				ft_strsub(conver_opt, i, 1));
		if (conver_opt[i] == '.')
			hold->end_of_width = -1;
		if (conver_opt[i - 1] != '.')
		{
			if (ft_isdigit(conver_opt[i]) && hold->end_of_width != -1)
			{
				if (!ft_isdigit(conver_opt[i + 1]))
					hold->end_of_width = -1;
				width = ft_strjoin(width, ft_strsub(conver_opt, i, 1));
			}
		}
		i++;
	}
	hold->width = ft_atoi(width);
}
