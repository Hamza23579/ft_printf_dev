/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <hghandi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:04:13 by mel-jadi          #+#    #+#             */
/*   Updated: 2019/08/09 17:23:14 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, int nb)
{
	int		i;
	int		size;
	int		count;

	size = -1;
	i = 0;
	count = 0;
	while (dest[i])
	{
		size++;
		i++;
	}
	i = 0;
	while (src[i] && count < nb)
	{
		dest[size + i + 1] = src[i];
		i++;
		count++;
	}
	dest[size + i + 1] = '\0';
	return (dest);
}
