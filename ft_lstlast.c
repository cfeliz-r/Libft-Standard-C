/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:54:56 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/07/24 18:30:53 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_env	*ft_lstlast(t_list_env *lst)
{
	while (lst)
	{
		if (lst->next != NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
