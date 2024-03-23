/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <cfeliz-r@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:10:26 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/03/23 11:44:40 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_number_size(int number)
{
	unsigned int	length;

	length = 0;
	if (number <= 0)
		length = 1;
	else
		length = 0;
	while (number != 0)
	{
		number /= 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	unsigned int	length;
	char			*str;
	unsigned long	number;

	length = ft_number_size(n);
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (!str)
		return (NULL);
	str[length] = '\0';
	number = 0;
	if (n < 0)
		number = -(long)n;
	else
		number = n;
	while (length > 0)
	{
		str[--length] = (number % 10) + '0';
		number /= 10;
	}
	if (n < 0 && length == 0)
		str[0] = '-';
	return (str);
}
