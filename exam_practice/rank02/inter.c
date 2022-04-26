
#include<unistd.h>

int	compare(char *s, char c, int i)
{
	int l;

	l = 0;
	while (l < i)
	{
		if (s[l] == c)
			return (1);
		l ++;
	}
	return (0);
}

void	inter(char *s1, char *s2)
{
	int	l1;
	int	l2;

	l1 = 0;
	l2 = 0;
	while (s1[l1])
	{
		if (!compare(s1, s1[l1], l1))
		{
			while(s2[l2])
			{
				if (s1[l1] == s2[l2])
					write(1, &s1[l1], 1);
				l2 ++;
			}
		}
		l2 = 0;
		l1 ++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
		inter(av[1], av[2]);
	write(1, "\n", 1);
	return (0);

}
