/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pstrnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:08:13 by eros-gir          #+#    #+#             */
/*   Updated: 2022/06/10 11:05:18 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

void	set_vars(size_t *len, size_t *numb, int *quotes)
{
	*len = 0;
	*numb = 0;
	*quotes = 0;
}

size_t	add_numb(int quotes)
{
	if (quotes <= 0)
		return (1);
	return (0);
}

size_t	ft_pstrnum(const char *s, char c)
{
	size_t	len;
	size_t	numb;
	int		quotes;

	set_vars(&len, &numb, &quotes);
	while (s[len])
	{
		while (s[len] == c || s[len] == '\'' || s[len] == '\"')
		{	
			if (s[len] == '\'' || s[len] == '\"')
				numb += add_numb(quotes);
			if (s[len] == '\'' || s[len] == '\"')
				quotes ++;
			len++;
		}
		if (s[len] && (s[len] != c && quotes <= 0))
			numb++;
		while (s[len] != 0 && s[len] != c)
		{
			if (s[len] == '\'' || s[len] == '\"')
				quotes --;
			len++;
		}
	}
	return (numb);
}

int	main(void)
{
	char	*str;

	str = "this string has only words";
	printf("%s : %zu\n", str, ft_pstrnum(str, ' '));
	str = "This string has some more words";
	printf("%s : %zu\n", str, ft_pstrnum(str, ' '));
	str = "This string has \'quotes in it\'";
	printf("%s : %zu\n", str, ft_pstrnum(str, ' '));
	str = "This string has double \'\"quotes in\"\' it";
	printf("%s : %zu\n", str, ft_pstrnum(str, ' '));
	str = "\'\"This string has\"\' two double \'qote quoet quote\'";
	printf("%s : %zu\n", str, ft_pstrnum(str, ' '));
	return (0);
}
