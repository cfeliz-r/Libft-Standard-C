/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <cfeliz-r@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:03:56 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/03/23 12:09:35 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*str;

	i = ft_strlen(s);
	str = (char *)malloc(sizeof(*str) * (i + 1));
	if (str == NULL)
		return (NULL);
	while (i >= 0)
	{
		str[i] = s[i];
		i--;
	}
	return (str);
}
