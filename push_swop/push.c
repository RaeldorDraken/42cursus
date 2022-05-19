/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:15:56 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/05/03 14:50:28 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	push_swap(int argc, char *argv[])
{
	t_stack		**s;
	void		*memory;

	memory = malloc(get_mem_size(argc));
	if (!memory)
		exit(0);
	s = init_stacks(memory, argc, argv);
	rebuilt(s);
	logical(s);
	ft_putstr_fd(s[0]->result, 1);
	s_free(s);
}

t_stack	**init_stacks(void *memory, int argc, char *argv[])
{
	int		i;
	t_stack	**s;

	s = memory;
	s[0] = (void *)s + sizeof(t_stack *) * 2;
	s[1] = (void *)s[0] + sizeof(t_stack);
	s[0]->values = (void *)s[1] + sizeof(t_stack);
	s[1]->values = (void *)s[0]->values + (sizeof(int) * (argc - 1));
	s[0]->size = argc - 1;
	s[1]->size = 0;
	i = 1;
	while (i < argc)
	{
		s[0]->values[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	s[0]->result = NULL;
	s[0]->debug = NULL;
	return (s);
}

int	get_mem_size(int argc)
{
	int	mem_size;

	mem_size = sizeof(t_stack *) * 2;
	mem_size += sizeof(t_stack) * 2;
	mem_size += (sizeof(int) * (argc - 1)) * 2;
	return (mem_size);
}

void	s_free(t_stack **s)
{
	if (s[0]->debug)
		free(s[0]->debug);
	if (s[0]->result)
		free(s[0]->result);
	free(s);
}

void	rebuilt(t_stack **s)
{
	int	min;
	int	pos;
	int	i;
	int	*v;

	v = malloc(sizeof(int) * (s[0]->size));
	i = 0;
	min = get_min(s[0]);
	pos = get_pos(s[0], min);
	v[pos] = i;
	i++;
	while (i < s[0]->size)
	{
		min = get_next_min(s[0], min);
		pos = get_pos(s[0], min);
		v[pos] = i;
		i++;
	}
	i = 0;
	while (i < s[0]->size)
	{
		s[0]->values[i] = v[i];
		i++;
	}
	free(v);
}
