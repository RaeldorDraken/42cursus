/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:13:05 by eros-gir          #+#    #+#             */
/*   Updated: 2022/05/03 12:27:29 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"utilslib.h"

int	ft_strchk(char *s, int c)
{
	int	l;
	int	i;
	int	result;

	l = ft_strlen(s)-1;
	i = 0;
	result = 0;
	while (i < l)
	{
		if (s[i] == c)
			result ++;
		i ++;
	}
	return (result);
}	

int	check_filename(char	*str)
{
	char	*chks;
	char	*cmps;
	int		len;

	cmps = ".ber";
	len = ft_strlen(str);
	chks = ft_substr(str, len -4, len);
	if (ft_strncmp(chks, cmps, 5))
		return (-5);
	return (0);
}

int	check_tile(char c)
{
	if (c == '1')
		return (1);
	return (0);
}
