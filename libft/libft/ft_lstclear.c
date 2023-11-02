/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas- <pviegas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:00:28 by pviegas-          #+#    #+#             */
/*   Updated: 2023/11/02 17:00:29 by pviegas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (*lst == NULL || del == NULL)
        return;
	t_list	*templst;
	t_list	*next;

	templst = *lst;
	next = NULL;
	while (templst != NULL)
	{
		next = templst->next;
		del(templst->content);
		free(templst);
		templst = next;
	}
	*lst = NULL;
}