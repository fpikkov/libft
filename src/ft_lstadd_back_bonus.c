/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:29:55 by fpikkov           #+#    #+#             */
/*   Updated: 2024/05/02 14:06:21 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	struct s_list	*last;

	last = *lst;
	if (last == NULL)
		*lst = new;
	else
	{
		last = ft_lstlast(last);
		last->next = new;
	}
}
