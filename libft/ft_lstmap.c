/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 19:17:04 by cveeta            #+#    #+#             */
/*   Updated: 2020/11/06 19:36:56 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_lst;
	t_list	*head;

	if (!lst || !(n_lst = ft_lstnew(f(lst->content))))
		return (NULL);
	head = n_lst;
	while (lst->next)
	{
		lst = lst->next;
		n_lst->next = ft_lstnew(f(lst->content));
		if (!n_lst->next)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		n_lst = n_lst->next;
	}
	return (head);
}
