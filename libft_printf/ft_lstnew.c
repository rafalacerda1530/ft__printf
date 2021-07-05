/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig <rarodrig@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 20:19:23 by rarodrig          #+#    #+#             */
/*   Updated: 2021/06/05 20:19:23 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*n_content;

	n_content = (t_list *)malloc(sizeof(t_list));
	if (n_content == NULL)
		return (NULL);
	n_content->content = content;
	n_content->next = NULL;
	return (n_content);
}
