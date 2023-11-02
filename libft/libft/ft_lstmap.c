/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas- <pviegas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:00:49 by pviegas-          #+#    #+#             */
/*   Updated: 2023/11/02 17:00:50 by pviegas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	if (!f || !del)
		return (NULL);
	t_list	*newlst;
	t_list	*templst;

	newlst = NULL;
	templst = NULL;
	while (lst != NULL)
	{
		templst = ft_lstnew(f(lst->content));
		if (templst == NULL)
		{
			//if (del)
			//	del(templst->content);
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, templst);
		lst = lst->next;
	}
	return (newlst);
}