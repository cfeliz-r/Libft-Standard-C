/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:55:20 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/07/24 17:36:55 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list_env	*lst_new(void *content)
{
	t_list_env	*new;

	new = (t_list_env *)malloc(sizeof(t_list_env));
	if (!new)
		return (NULL);
	new->envp_content = content;
	new->next = NULL;
	return (new);
}

static void	lst_clear(t_list_env **lst, void (*del)(void *))
{
	if (!lst || !del || !(*lst))
		return ;
	lst_clear(&(*lst)->next, del);
	(del)((*lst)->envp_content);
	free(*lst);
	*lst = NULL;
}

static void	lstadd_back(t_list_env **lst, t_list_env *new)
{
	t_list_env	*ptr;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	ptr = *lst;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
}

t_list_env	*ft_lstmap(t_list_env *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list_env	*new_list;
	t_list_env	*new_node;
	void		*set;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		set = f(lst->envp_content);
		new_node = lst_new(set);
		if (!new_node)
		{
			del(set);
			lst_clear(&new_list, (*del));
			return (new_list);
		}
		lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
