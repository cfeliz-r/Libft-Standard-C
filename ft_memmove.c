/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <cfeliz-r@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:49:01 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/03/19 10:18:32 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = (char *)dst;
	s = (const char *)src;
	if (dst == src || len == 0)
		return (dst);
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		d += len;
		s += len;
		while (len--)
		{
			d--;
			s--;
			*d = *s;
		}
	}
	return (dst);
}
/*
int main()
{
    char str1[] = "Hello,World!";
    char str2[7];

    ft_memmove(str2, str1, 6);

    printf("str2: %s\n", str2);

    return 0;
}
*/
