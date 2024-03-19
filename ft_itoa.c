/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <cfeliz-r@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:10:26 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/03/19 10:17:05 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int ft_number_size(int number)
{
    unsigned int length = (number <= 0) ? 1 : 0;
    while (number != 0)
    {
        number /= 10;
        length++;
    }
    return length;
}

char *ft_itoa(int n)
{
    unsigned int length = ft_number_size(n);
    char *str = (char *)malloc(sizeof(char) * (length + 1));
    if (!str)
        return (NULL);

    str[length] = '\0';
    unsigned long number = (n < 0) ? -(long)n : n;
    while (length > 0)
    {
        str[--length] = (number % 10) + '0';
        number /= 10;
    }
    if (n < 0)
        str[0] = '-';

    return str;
}

