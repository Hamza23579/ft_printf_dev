/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <hghandi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 19:57:32 by mel-jadi          #+#    #+#             */
/*   Updated: 2019/08/09 17:22:43 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		size;
	char		*s;
	int			i;
	int			j;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return ((char *)s2);
	if (s2 == NULL)
		return ((char *)s1);
	size = ft_strlen(s1) + ft_strlen(s2);
	s = (char *)malloc(size + 1);
	if (s == NULL)
		exit(1);
	i = 0;
	j = -1;
	while (s1[++j])
		s[i++] = s1[j];
	j = -1;
	while (s2[++j])
		s[i++] = s2[j];
	s[i] = '\0';
	return (s);
}
