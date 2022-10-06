/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfidan <sfidan@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:47:30 by sfidan            #+#    #+#             */
/*   Updated: 2022/08/30 13:47:32 by sfidan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;

	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res || !s1 || !s2)
		return (0);
	i = 0;
	while (*s1)
		res[i++] = *s1++;
	while (*s2)
		res[i++] = *s2++;
	res[i] = 0;
	return (res);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*res;
	size_t	i;

	res = malloc(size * count);
	if (!res)
		return (0);
	i = 0;
	while (i < size * count)
		res[i++] = 0;
	return (res);
}

size_t	ft_strlen(const char *s)
{
	if (!*s)
		return (0);
	return (1 + ft_strlen(s + 1));
}

size_t	ft_char_loc(char *s, char c, int b)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	if (b && !s[i])
		return (0);
	return (i);
}
