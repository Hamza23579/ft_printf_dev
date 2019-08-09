/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <hghandi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 15:12:49 by mel-jadi          #+#    #+#             */
/*   Updated: 2019/08/09 17:21:38 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	int		i;

	i = 0;
	ft_strlowcase(str);
	while (str[i] != '\0')
	{
		if (i == 0 && str[i] <= 122 && str[i] >= 97)
			str[i] -= 32;
		if (str[i] == ' ' || str[i] == '-' || str[i] == '+' ||
				str[i] == '\t' || str[i] == '\n')
		{
			if (str[i + 1] <= 122 && str[i + 1] > 96)
				str[i + 1] -= 32;
		}
		i++;
	}
	return (str);
}
