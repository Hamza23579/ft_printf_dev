/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <hghandi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 13:27:17 by hghandi           #+#    #+#             */
/*   Updated: 2019/08/07 13:27:19 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_count_digits(long long int nb)
{
	long long int			total;
	unsigned long long int	nbr;

	total = 0;
	if (nb < 0)
		nb *= -1;
	nbr = (unsigned long long int)nb;
	while (nbr >= 10)
	{
		nbr /= 10;
		total++;
	}
	total++;
	return (total);
}

long long int	ft_abs_l(long long int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

char			*ft_itoa(long long int n)
{
	char					*number;
	int						i;
	unsigned long long int	nbr;
	int						digitscount;

	digitscount = ft_count_digits(n);
	if (n < 0)
		digitscount++;
	n = ft_abs_l(n);
	number = (char *)malloc(sizeof(char) * (digitscount + 1));
	if (number == NULL)
		return (NULL);
	number[0] = '-';
	nbr = (unsigned long long int)n;
	i = digitscount;
	number[i--] = '\0';
	while (nbr >= 10)
	{
		number[i--] = '0' + (nbr % 10);
		nbr /= 10;
	}
	number[i] = '0' + nbr;
	return (number);
}
