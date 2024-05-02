/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:48:36 by fpikkov           #+#    #+#             */
/*   Updated: 2024/05/02 13:27:25 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int				size;
	struct s_list	*last;

	size = ft_lstsize(lst);
	last = lst;
	while (size > 1)
	{
		last = last->next;
		size--;
	}
	return (last);
}
