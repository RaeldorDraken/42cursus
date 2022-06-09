#include<stdio.h>

size_t  ft_pstrnum(const char *s, char c)
{
	size_t	len;
	size_t	numb;
	int		quotes;

	len = 0;
	numb = 0;
	quotes = 0;
	while (s[len])
	{
		if (s[len] == '\'' || s[len] == '\"')
		{
			if (quotes <= 0)
				numb ++;
			quotes ++;
		}
		while (s[len] == c || s[len] == '\'' || s[len] == '\"')
		{	
			if (s[len] == '\'' || s[len] == '\"')
			{
				if (quotes <= 0)
					numb ++;
				quotes ++;
			}
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
	char	*str = "this string has only words";

	printf("%s : %zu\n", str, ft_pstrnum(str, ' '));
	str = "This string has some more words";
	printf("%s : %zu\n", str, ft_pstrnum(str, ' '));
	str = "This string has \'quotes in it\' fuck";
	printf("%s : %zu\n", str, ft_pstrnum(str, ' '));
	str = "This string has double \'\"quotes in it\"\'";
	printf("%s : %zu\n", str, ft_pstrnum(str, ' '));
	return (0);
}
