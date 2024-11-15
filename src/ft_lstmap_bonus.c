/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:47:04 by fpikkov           #+#    #+#             */
/*   Updated: 2024/05/04 15:33:53 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_clearlist(t_list **lst, void **cont, void (*del)(void *))
{
	if (*cont != NULL)
		del(*cont);
	if (*lst != NULL)
		ft_lstclear(lst, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*tail;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	content = f(lst->content);
	head = ft_lstnew(content);
	if (head == NULL)
		return (ft_clearlist(&head, &content, del));
	tail = head;
	lst = lst->next;
	while (lst != NULL)
	{
		content = f(lst->content);
		tail->next = ft_lstnew(content);
		if (tail->next == NULL)
			return (ft_clearlist(&head, &content, del));
		tail = tail->next;
		lst = lst->next;
	}
	return (head);
}
