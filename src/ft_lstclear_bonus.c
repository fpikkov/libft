/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:20:12 by fpikkov           #+#    #+#             */
/*   Updated: 2024/05/02 14:56:44 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	struct s_list	*first;
	struct s_list	*second;

	first = *lst;
	second = first;
	while (second != NULL)
	{
		second = first->next;
		del(first->content);
		free(first);
		first = second;
	}
	*lst = NULL;
}
