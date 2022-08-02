/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:13:06 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/05/09 14:52:51 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

char	*to_str(int c)
{
	char	*str;

	str = malloc(sizeof(int) + 1);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

char	*join(char *s1, char *s2)
{
	char	*str;

	if (s1 == NULL)
		return (s2);
	if (s2 == NULL)
		return (s1);
	str = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (str);
}

char	*sdup(char *str)
{
	if (str == NULL)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(str);
	return (str);
}

char	*sub(char *str, unsigned int start, size_t len)
{
	char	*aux;

	aux = str;
	str = ft_substr(str, start, len);
	free(aux);
	return (str);
}

char	**p_split(char *s, char c)
{
	char	**words;

	if (!s)
		return (NULL);
	words = ft_split(s, c);
	free(s);
	return (words);
}
