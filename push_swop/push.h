/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:22:35 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/05/09 17:30:03 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H
# include "libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int		*values;
	int		size;
	char	*debug;
	char	*result;
}	t_stack;

//push
void		push_swap(int argc, char *argv[]);
t_stack		**init_stacks(void *memory, int argc, char *argv[]);
int			get_mem_size(int argc);
void		s_free(t_stack **s);
void		rebuilt(t_stack **s);
//check_imputs
int			check_input(int argc, char *argv[]);
//p_ops
t_stack		**pa(t_stack **s);
t_stack		**pb(t_stack **s);
//s_ops
t_stack		**sa(t_stack **s);
t_stack		**sb(t_stack **s);
t_stack		**ss(t_stack **s);
//r_ops
t_stack		**ra(t_stack **s);
t_stack		**rb(t_stack **s);
t_stack		**rr(t_stack **s);
//rr_ops
t_stack		**rra(t_stack **s);
t_stack		**rrb(t_stack **s);
t_stack		**rrr(t_stack **s);
//check_ops
int			check_rotable(t_stack **s);
int			check_swapable(t_stack **s);
int			sorted(t_stack *a);
int			sorted_b(t_stack *a);
//logical
void		logical(t_stack **s);
void		logical_1a(t_stack **s);
void		logical_2a(t_stack **s);
void		logical_2b(t_stack **s);
void		push_part(t_stack **s, int n, int part);
//logical_utils
int			get_max(t_stack *x);
int			get_min(t_stack *x);
int			get_next_min(t_stack *x, int min);
int			get_next_max(t_stack *x, int max);
int			get_pos(t_stack *s, int nbr);
//logical_utils2
int			exist_less_than(t_stack **s, int nbr);
//save_ops
int			save_swap(t_stack **s);
int			save_rotate(t_stack **s);
void		save_push(t_stack **s);
//s_utils
char		*to_str(int c);
char		*join(char *s1, char *s2);
char		*sdup(char *str);
char		*sub(char *str, unsigned int start, size_t len);
char		**p_split(char *s, char c);
//v_utils
void		v_free(char **v);
//debug
void		print(char *op, t_stack **s);
void		ds(char *str);
void		di(int i);
//checker
void		s_free(t_stack **s);
int			checker(int argc, char *argv[], char **ops);
int			make_op(t_stack **s, char *ops_str);
char		**read_ops(void);
int			chek_op(char *op);
// u_atoi
long int	u_atoi(const char *str);
// i_utils
int			check_int(char *num);
#endif
