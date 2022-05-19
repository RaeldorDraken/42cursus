/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:12:52 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/01/26 12:48:56 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*aux;
	t_list	*new_list;
	t_list	*new;
	int		len;

	(void)del;
	new_list = NULL;
	aux = lst;
	len = ft_lstsize(lst);
	while (len > 0)
	{
		new = ft_lstnew(f(aux->content));
		if (new == NULL)
			return (NULL);
		ft_lstadd_back(&new_list, new);
		aux = aux->next;
		len--;
	}
	return (new_list);
}
