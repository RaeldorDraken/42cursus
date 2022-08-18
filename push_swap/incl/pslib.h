/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pslib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:31:36 by eros-gir          #+#    #+#             */
/*   Updated: 2022/08/18 18:15:56 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../libft/libft.h"

typedef struct s_stks
{
	long int	*a;
	long int	*b;
	int		size_a;
	int		size_b;
}	t_stks;

void	ft_pa(t_stks *lists);
void	ft_pb(t_stks *lists);
void	ft_pp(t_stks *lists);
void	ft_rra(t_stks *lists);
void	ft_rrb(t_stks *lists);
void	ft_rrr(t_stks *lists);
void	ft_ra(t_stks *lists);
void	ft_rb(t_stks *lists);
void	ft_rr(t_stks *lists);
void	ft_sa(t_stks *lists);
void	ft_sb(t_stks *lists);
void	ft_ss(t_stks *lists);

int		ft_check_list(t_stks *lists, int type);
void	ft_test_check_result(t_stks *lists);
void	ft_check_cases(t_stks *lists);
void	ft_case_three(t_stks *lists);
void	ft_case_five(t_stks *lists);
void	ft_case_algorithmic(t_stks *lists);
