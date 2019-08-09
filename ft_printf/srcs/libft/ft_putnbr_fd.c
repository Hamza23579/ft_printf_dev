/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <hghandi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 15:45:17 by mel-jadi          #+#    #+#             */
/*   Updated: 2019/08/09 17:20:47 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	int size;
	int test;

	if (nb < 0)
	{
		nb = -nb;
		ft_putchar_fd('-', fd);
	}
	if (nb == -2147483648)
	{
		ft_putchar_fd(50, fd);
		nb = 147483648;
	}
	size = 1;
	test = nb;
	while ((test /= 10) != 0)
		size *= 10;
	while (size != 0)
	{
		test = nb / size;
		nb %= size;
		size /= 10;
		ft_putchar_fd(test + 48, fd);
	}
}
