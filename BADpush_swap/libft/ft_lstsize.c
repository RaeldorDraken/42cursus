/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:10:10 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/01/26 12:14:06 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*aux;

	if (lst == NULL)
		return (0);
	count = 1;
	aux = lst;
	while (aux->next != NULL)
	{
		count++;
		aux = aux->next;
	}
	return (count);
}
