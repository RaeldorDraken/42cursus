/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:51:09 by eros-gir          #+#    #+#             */
/*   Updated: 2022/01/13 14:21:12 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdio.h>
#include<string.h>

int	main(int count, char **v)
{
	char	*c;
	char	*s;
	char	*s2;
	int		i;

	if (count != 3)
		return (1);
	s = v[1];
	s2 =v[3];
	c = v[2];
	i = c[0] + 512;
//	if (ft_isalnum(c))
//		printf("YES\n");
//	else
//		printf("NO\n");
	s2 = ft_strchr(s, i);
//	printf("s1 = %s\n s2 = %s\n", s, s2);
//	printf("%zu\n", ft_strlcat(s, s2, i));
	printf("result: %s\n", s2);
//	c = ft_tolower(c);
//	printf("a: %c", c);;
}
