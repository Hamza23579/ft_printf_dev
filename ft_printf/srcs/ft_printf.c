/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 20:42:38 by hghandi           #+#    #+#             */
/*   Updated: 2019/08/04 20:45:12 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	writer(t_holder *hold, int i)
{

	int		j;

	j = i + 1;
	while (!check_opt(hold->format[j]))
		j++;
	hold->conver_opts = ft_strsub(hold->format, i + 1, j - i);
	ft_analyse(hold->conver_opts, hold);
	if (hold->conver_opts[ft_strlen(hold->conver_opts) - 1] == 'c')
		writer_c(hold);
	if (hold->conver_opts[ft_strlen(hold->conver_opts) - 1] == 's')
		writer_s(hold);
	if (hold->conver_opts[ft_strlen(hold->conver_opts) - 1] == 'p')
		writer_p(hold);
	if (hold->conver_opts[ft_strlen(hold->conver_opts) - 1] == 'd')
		writer_d(hold);
	return (j + 1);
}

int		parse(t_holder *hold)
{
	int		i;

	i = 0;
	hold->count = 0;
	while (hold->format[i] != '\0')
	{
		if (hold->format[i] == '%')
			i = writer(hold, i);
		else 
		if (hold->format[i] != '%')
		{
			write(1, &(hold->format[i]), 1);
			hold->count++;
			i++;
		}
	}
	return (hold->count);
}

int ft_printf(char *format, ...)
{
	t_holder	hold;
	int			lenght;

	hold.format = ft_strnew(ft_strlen(format));
	ft_strcpy(hold.format, format);
	va_start(hold.args, format);
	lenght = parse(&hold);
	va_end(hold.args);
	free(hold.format);
	return (lenght);
}

int main(void)
{
	int i;
	int j;
	// // long long int d = -68435135438435;

	i = ft_printf("\n|%-+23.5hd|%- 23.5hd|%-023.5hd|%+ 23.5hd|%+023.5hd|% 023.5hd|%-+ 023.5hd|\n", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN);
	j =    printf("\n|%-+23.5hd|%- 23.5hd|%-023.5hd|%+ 23.5hd|%+023.5hd|% 023.5hd|%-+ 023.5hd|\n", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN);
	// ft_printf("\n|%d|\n", -12);
	// printf("\n% .d\n", -5555);
	// // printf("|itoa(0) = %s|\n", ft_itoa_base(0, 16));
	printf("dyalna => %i dyalhom => %i \n", i, j);
	// printf("%d\n", ft_atoi(".45"));
	//ft_printf("\n|%-+23hd|%- 23hd|%-023hd|%+ 23hd|%+023hd|% 023hd|%-+ 023hd|\n", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN);
	  // printf("\n|%-+23hd|%- 23hd|%-023hd|%+ 23hd|%+023hd|% 023hd|%-+ 023hd|\n", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN);
	// printf("dyalna => %i dyalhom => %i \n", i, j);
	// printf("%-08i" , 1234);
	// printf("%-+023d\n", 15);

	return (0);
}
