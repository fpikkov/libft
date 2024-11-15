/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:39:07 by fpikkov           #+#    #+#             */
/*   Updated: 2024/05/02 13:18:08 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	struct s_list	*current;
	int				size;

	current = lst;
	size = 0;
	while (current != NULL)
	{
		++size;
		current = current->next;
	}
	return (size);
}
