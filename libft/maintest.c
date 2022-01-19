/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:51:09 by eros-gir          #+#    #+#             */
/*   Updated: 2022/01/14 15:43:31 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdio.h>
#include<string.h>

int	main(int count, char **v)
{
	char	c;
	char	*s;
//	char	*s2;
	char	**sr;
	int	i;

	if (count != 2)
		return (1);
	s = v[1];
//	s2 =v[3];
	c = v[2][0];
	i = 0;
	sr = ft_split(s, c);
	while (sr[i])
	{
		printf("result: %s\n", sr[i]);
		i++;
	}
}
