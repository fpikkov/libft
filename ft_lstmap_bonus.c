/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:47:04 by fpikkov           #+#    #+#             */
/*   Updated: 2024/05/02 18:18:08 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	struct s_list	*head;
	struct s_list	*tail;

	if (!lst || !f)
		return (NULL);
	head = NULL;
	tail = NULL;
	while (lst != NULL)
	{
		ft_lstadd_back(&head, ft_lstnew(f(lst->content)));
		if (tail == NULL)
		{
			ft_lstclear(&head, *del);
			return (NULL);
		}
		tail = tail->next;
		lst = lst->next;
	}
	tail = NULL;
	return (head);
}
