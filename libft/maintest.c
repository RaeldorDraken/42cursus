/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:51:09 by eros-gir          #+#    #+#             */
/*   Updated: 2022/01/11 15:53:16 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdio.h>

int	main(int count, char **v)
{
	char	c;
	char	*s;
	char	*s2;

	if (count != 2)
		return (1);
	s = v[1];
	c = s[0];
//	if (ft_isalnum(c))
//		printf("YES\n");
//	else
//		printf("NO\n");
	s2 = ft_strrchr(s, '*');
	printf("%s\n", s2);
//	c = ft_tolower(c);
//	printf("a: %c", c);;
}
