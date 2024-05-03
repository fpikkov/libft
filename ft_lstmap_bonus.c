/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:47:04 by fpikkov           #+#    #+#             */
/*   Updated: 2024/05/03 18:00:07 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_clearlist(t_list *lst, void (*del)(void *))
{
	ft_lstclear(&lst, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	struct s_list	*head;
	struct s_list	*tail;

	if (!lst || !f || !del)
		return (NULL);
	head = ft_lstnew(f(lst->content));
	if (head == NULL)
		return (ft_clearlist(head, del));
	tail = head;
	lst = lst->next;
	while (lst != NULL)
	{
		tail->next = ft_lstnew(f(lst->content));
		if (tail->next == NULL)
			return (ft_clearlist(head, del));
		tail = tail->next;
		lst = lst->next;
	}
	return (head);
}
