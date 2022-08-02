/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:09:34 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/05/03 14:49:52 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

char	*read_op(int c, char *ops_str);

int	checker(int argc, char *argv[], char **ops)
{
	t_stack		**s;
	void		*memory;
	int			i;

	memory = malloc(get_mem_size(argc));
	if (!memory)
		v_free(ops);
	if (!memory)
		exit(0);
	s = init_stacks(memory, argc, argv);
	i = 0;
	while (ops && ops[i])
	{
		make_op(s, ops[i]);
		i++;
	}
	if (sorted(s[0]) && s[1]->size == 0)
	{
		s_free (s);
		return (1);
	}
	s_free (s);
	return (0);
}

int	make_op(t_stack **s, char *op)
{
	if (!ft_strncmp(op, "sa", ft_strlen(op)))
		sa(s);
	else if (!ft_strncmp(op, "rra", ft_strlen(op)))
		rra(s);
	else if (!ft_strncmp(op, "rrb", ft_strlen(op)))
		rrb(s);
	else if (!ft_strncmp(op, "rrr", ft_strlen(op)))
		rrr(s);
	else if (!ft_strncmp(op, "sb", ft_strlen(op)))
		sb(s);
	else if (!ft_strncmp(op, "ss", ft_strlen(op)))
		ss(s);
	else if (!ft_strncmp(op, "ra", ft_strlen(op)))
		ra(s);
	else if (!ft_strncmp(op, "rb", ft_strlen(op)))
		rb(s);
	else if (!ft_strncmp(op, "rr", ft_strlen(op)))
		rr(s);
	else if (!ft_strncmp(op, "pa", ft_strlen(op)))
		pa(s);
	else if (!ft_strncmp(op, "pb", ft_strlen(op)))
		pb(s);
	else
		return (0);
	return (1);
}

char	**read_ops(void)
{
	char	c;
	char	*ops_str;

	ops_str = NULL;
	while (1)
	{
		if (read(0, &c, 1) == 0)
			break ;
		ops_str = read_op(c, ops_str);
	}
	if (!ops_str)
		return (NULL);
	if (ops_str[ft_strlen(ops_str) - 1] != '\n')
	{
		ft_putchar_fd('\n', 1);
		free(ops_str);
		return (NULL);
	}
	return (p_split(ops_str, '\n'));
}

int	chek_op(char *op)
{
	int	i;

	i = 0;
	if (!op || ft_strlen(op) < 2 || !ft_strncmp(op, "Error", ft_strlen(op)))
	{
		ft_putstr_fd("Error\n", 2);
		if (op)
			free(op);
		return (1);
	}
	if (!make_op(NULL, op))
	{
		ft_putstr_fd("Error\n", 2);
		free(op);
		return (1);
	}
	return (0);
}

char	*read_op(int c, char *ops_str)
{
	static char	*op = NULL;

	if (c == '\n')
	{
		if (chek_op(op))
		{
			op = NULL;
			if (ops_str)
				free(ops_str);
			exit(0);
		}
		free(op);
		ops_str = join(ops_str, to_str(c));
		op = NULL;
	}
	else
	{
		op = join(op, to_str(c));
		ops_str = join(ops_str, to_str(c));
	}
	return (ops_str);
}
