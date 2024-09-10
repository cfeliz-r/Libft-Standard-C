/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <cfeliz-r@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:21:51 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/24 14:54:17 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero1(void *dest, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = 0;
		i++;
	}
}

size_t	ft_strlen1(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr1(char *str, int c)
{
	while (*str != '\0' && (char)c != *str)
	{
		str++;
	}
	if (*str == (char)c)
	{
		return ((char *)str);
	}
	else
		return (0);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	char	*aux;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	aux = (char *)malloc(ft_strlen1(s1) + ft_strlen1(s2) + 1);
	if (!aux)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
		while (s1[j] != '\0')
			aux[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		aux[i++] = s2[j++];
	aux[i] = '\0';
	free(s1);
	return (aux);
}
