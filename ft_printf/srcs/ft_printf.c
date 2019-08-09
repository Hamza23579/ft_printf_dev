/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <hghandi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:00:00 by hghandi           #+#    #+#             */
/*   Updated: 2019/08/06 15:15:26 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	csp_(t_holder *hold)
{
	if (contains(hold->conver_opts, 'c') != -1)
		writer_c(hold);
	if (contains(hold->conver_opts, 's') != -1)
		writer_s(hold);
	if (contains(hold->conver_opts, 'p') != -1)
		writer_p(hold);
}

int		writer(t_holder *hold, int i)
{
	int		j;

	j = i + 1;
	while (!check_opt(hold->format[j]) && hold->format[j] != '\0')
		j++;
	hold->conver_opts = ft_strsub(hold->format, i + 1, j - i);
	ft_analyse(hold->conver_opts, hold);
	csp_(hold);
	if (contains(hold->conver_opts, 'd') != -1 ||
		contains(hold->conver_opts, 'i') != -1 ||
		contains(hold->conver_opts, 'o') != -1 ||
		contains(hold->conver_opts, 'u') != -1 ||
		contains(hold->conver_opts, 'x') != -1 ||
		contains(hold->conver_opts, 'X') != -1)
		writer_d(hold);
	else if (contains(hold->conver_opts, '%') != -1)
	{
		hold->dieze = ft_strsub(hold->format, i, ft_strlen(hold->format) - i);
		print_percent(hold);
	}
	return (j + 1);
}

int		parse(t_holder *hold)
{
	int		i;

	i = 0;
	hold->count = 0;
	while (hold->format[i] != '\0' && hold->percent != 1)
	{
		if (hold->format[i] == '%')
			i = writer(hold, i);
		else
		{
			if (hold->format[i] != '%')
			{
				write(1, &(hold->format[i]), 1);
				hold->count++;
				i++;
			}
		}
	}
	return (hold->count);
}

int		ft_printf(char *format, ...)
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
	// char *str;

	i = ft_printf("% |% h|% hZ\n");
		// ft_printf("%|%%|%%%|%%%%");
	j =    printf("\n% |% h|% hZ");
	// ft_putstr("this is what happened : h| = ");
	// str = ft_strtrim_c("h|", 'h');
	// ft_putstr(str);
	// ft_printf("\n|%d|\n", -12);
	// ft_printf("\n%#X\n", 1000);
	   // printf("\n%#X\n", 1000);
	// printf("dyalna => %i dyalhom => %i \n", i, j);
	// printf("%d\n", ft_atoi(".45"));
	// printf("dyalna => %d dyalhom => %d \n", i, j);
	// printf("%-+023d\n", 15);

	return (0);
}
