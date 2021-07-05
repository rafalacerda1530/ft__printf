/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig <rarodrig@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 11:50:07 by rarodrig          #+#    #+#             */
/*   Updated: 2021/06/08 11:50:07 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*new_element;

	if (lst == NULL)
		return (NULL);
	new_element = ft_lstnew((*f)(lst->content));
	if (new_element == NULL)
	{
		free(new_element);
		return (NULL);
	}
	newlst = new_element;
	lst = lst->next;
	while (lst)
	{
		new_element->next = ft_lstnew((*f)(lst->content));
		if (new_element == NULL)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		new_element = new_element->next;
		lst = lst->next;
	}
	return (newlst);
}
