/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <hghandi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 16:53:11 by hghandi           #+#    #+#             */
/*   Updated: 2019/08/09 16:53:15 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*remove_h_l(t_holder *hold)
{
	int		k;
	char	*temp;

	k = 0;
	while (hold->dieze[k] != '\0')
	{
		if (hold->dieze[k] == 'h')
		{
			temp = ft_strsub(hold->dieze, 0, k);
			hold->dieze = ft_strsub(hold->dieze, k + 1,
				ft_strlen(hold->dieze) - k);
			hold->dieze = ft_strjoin(temp, hold->dieze);
		}
		if (hold->dieze[k] == 'l')
		{
			temp = ft_strsub(hold->dieze, 0, k);
			hold->dieze = ft_strsub(hold->dieze, k + 1,
				ft_strlen(hold->dieze) - k);
			hold->dieze = ft_strjoin(temp, hold->dieze);
		}
		k++;
	}
	return (hold->dieze);
}

void	remove_space(char *str)
{
	int		k;
	char	*temp;

	k = 0;
	if (str[k] == ' ')
	{
		temp = ft_strsub(str, 0, k);
		str = ft_strsub(str, k + 1, ft_strlen(str) - k);
		str = ft_strjoin(temp, str);
	}
}

int		writer_percent(t_holder *hold, int i)
{
	int		j;
	char	other_c;
	int		cpt;

	j = i + 1;
	cpt = 0;
	while ((hold->dieze[j] == ' ' || hold->dieze[j] == '-' ||
		ft_isdigit(hold->dieze[j])) &&
		hold->dieze[j] != '\0')
	{
		cpt++;
		j++;
	}
	hold->conver_opts = ft_strsub(hold->dieze, i, cpt + 2);
	remove_space(hold->conver_opts);
	if (ft_strlen(hold->conver_opts) != 1)
	{
		other_c = hold->conver_opts[ft_strlen(hold->conver_opts) - 1];
		hold->conver_opts[ft_strlen(hold->conver_opts) - 1] = 'c';
		hold->count += ft_printf(hold->conver_opts, other_c);
	}
	return (j + 1);
}

int		print_percent(t_holder *hold)
{
	int		i;
	char	*dieze1;

	i = 0;
	hold->percent = 1;
	hold->dieze = remove_h_l(hold);
	while (hold->dieze[i] != '\0')
	{
		if (hold->dieze[i] == '%')
			i = writer_percent(hold, i);
		else
		{
			if (hold->dieze[i] != '%')
			{
				write(1, &(hold->dieze[i]), 1);
				hold->count++;
				i++;
			}
		}
	}
	return (hold->count);
}
