/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <hghandi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 21:37:40 by mel-jadi          #+#    #+#             */
/*   Updated: 2019/08/09 17:20:18 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbr_size(long long int *n, int *test, int *str_size)
{
	int				size;
	long long int	copy;

	copy = *n;
	*test = 0;
	*str_size = 0;
	if (copy < 0)
	{
		*n *= (-1);
		copy *= (-1);
		(*test)++;
		(*str_size)++;
	}
	size = 1;
	while ((copy /= 10) != 0)
	{
		size *= 10;
		(*str_size)++;
	}
	return (size);
}
