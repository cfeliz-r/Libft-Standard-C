/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <cfeliz-r@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:22:01 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/03/21 00:28:34 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
char	*ft_strchr(const char *s, int i)
{
	while (*s)
	{
		if (*s == i)
			return ((char *)s);
		s++;
	}
	if (i == '\0')
		return ((char *)s);
	return (0);
}*/
char	*ft_strchr(const char *s, int c)
{
	char	a;

	a = c; //se iguala la variable al valor de sus parametro de entrada
	while (*s) //mientras el puntero a la cadena exista
	{
		if (*s == a) //mientras el puntero a la cadena a buscar sea igual a caracter a buscar
		{
			return ((char *) s); // devuelvo un char puntero a la coincidencia.
		}
		s++; //contador para poder recorer el string
	}
	if (a == '\0') //mietntras el caracter sea igual a NULL
		return ((char *) s); // devuelvo un char puntero a la coincidencia
	return (0);
}
