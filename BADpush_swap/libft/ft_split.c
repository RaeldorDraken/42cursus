/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:30:01 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/01/26 12:24:08 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words_counter(char const *s, char c);

static char	*get_i_word(char const *s, char c, int n);

static char	**null_matrix(void);

static char	**full_matrix(char const *s);

char	**ft_split(char const *s, char c)
{
	int		words;
	int		i;
	char	**matrix;

	if (s == NULL || *s == 0)
		return (null_matrix());
	if (c == 0)
		return (full_matrix(s));
	words = words_counter(s, c);
	if (words == 0)
	{
		matrix = (char **) malloc(sizeof(char *));
		matrix[0] = NULL;
		return (matrix);
	}
	matrix = (char **) ft_calloc(sizeof(char *), (words)+1);
	if (matrix == NULL)
		return (NULL);
	i = 0;
	while (i < words)
	{
		matrix[i] = get_i_word(s, c, i);
		i++;
	}
	return (matrix);
}

static int	words_counter(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i] != '\0' && s[i] == c)
			i++;
	if (s[i] == '\0' )
		words++;
	else
	{
		if (s[i] != '\0' )
			words++;
		while (s[i])
		{
			if (s[i] == c)
				words++;
			while (s[i] != '\0' && s[i] == c)
				i++;
			i++;
		}
		if (s[ft_strlen(s) - 1] == c)
				words--;
	}
	return (words);
}

static char	*get_i_word(char const *s, char c, int n)
{
	int				i;
	unsigned int	start;
	size_t			end;

	i = -1;
	start = 0;
	end = 0 ;
	while (i < n)
	{
		start = end;
		while (s[end] != '\0' && s[start] == c)
			start++;
		end = start;
		while (s[end] != '\0' && s[end] != c)
			end++;
		i++;
	}
	if (start == end)
		return (NULL);
	return (ft_substr(s, start, end - start));
}

static char	**null_matrix(void)
{
	char	**matrix;

	matrix = (char **) ft_calloc(sizeof(char *), 1);
	if (matrix == NULL)
		return (NULL);
	matrix[0] = NULL;
	return (matrix);
}

static char	**full_matrix(char const *s)
{
	char	**matrix;

	matrix = (char **) malloc(sizeof(char *) * 2);
	if (matrix == NULL)
		return (NULL);
	matrix[0] = ft_substr(s, 0, ft_strlen(s));
	matrix[1] = NULL;
	return (matrix);
}
