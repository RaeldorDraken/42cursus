/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pslib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:31:36 by eros-gir          #+#    #+#             */
/*   Updated: 2022/11/01 12:48:34 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSLIB_H
# define PSLIB_H

# include"../libft/libft.h"

typedef struct s_stks
{
	long int	*a;
	long int	*b;
	long int	*chunk;
	int			*ga;
	int			*gb;
	int			size_a;
	int			size_b;
	int			steps;
	int			hold_top;
	int			hold_bot;
}	t_stks;

void		ft_pa(t_stks *lists);
void		ft_pb(t_stks *lists);
void		ft_rra(t_stks *lists);
void		ft_rrb(t_stks *lists);
void		ft_rrr(t_stks *lists);
void		ft_ra(t_stks *lists);
void		ft_rb(t_stks *lists);
void		ft_rr(t_stks *lists);
void		ft_sa(t_stks *lists);
void		ft_sb(t_stks *lists);
void		ft_ss(t_stks *lists);
void		ft_set_game_list(t_stks *lists);

int			ft_check_list_a(t_stks *lists, int type);
int			ft_check_list_b(t_stks *lists, int type);
int			ft_check_chunk(t_stks *lists);
int			ft_ra_nbr_moves(t_stks *lists);
int			ft_rra_nbr_moves(t_stks *lists);
int			ft_sort_b(t_stks *lists, long int target, long int hold);

long int	ft_look_for_nbr(t_stks *lists, int type);
long int	ft_check_nearest(t_stks *lists, long int hold, long int t, int i);

void		ft_test_check_result(t_stks *lists);
void		ft_check_cases(t_stks *lists);
void		ft_case_three(t_stks *lists);
void		ft_case_five(t_stks *lists);
void		ft_case_algorithmic(t_stks *lists);
void		ft_basic_al(t_stks *lists);
void		ft_set_hold_top(t_stks *lists, int size);
void		ft_set_hold_bottom(t_stks *lists, int size);
#endif
