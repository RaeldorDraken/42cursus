/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:33:48 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/04/15 16:39:00 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	v_free(char **v)
{
	int	i;

	i = 0;
	while (v && v[i])
	{
		free(v[i]);
		i++;
	}
	free(v);
}
