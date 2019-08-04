/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jadi <md.eljadi@outlook.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 14:08:59 by mel-jadi          #+#    #+#             */
/*   Updated: 2018/10/15 22:56:23 by mel-jadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int                ft_count_digits(long long int nb)
{
    int                        total;
    unsigned long long int    nbr;

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

long long int    check_negative(long long int *n, long long int digitscount)
{
    digitscount++;
    *n *= -1;
    return (digitscount);
}

char            *ft_itoa(long long int n)
{
    char                    *number;
    int                        i;
    unsigned long long int    nbr;
    long long int            digitscount;

    digitscount = ft_count_digits(n);
    if (n < 0)
        digitscount = check_negative(&n, digitscount);
    if (!(number = (char *)malloc(sizeof(char) * (digitscount + 1))))
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
