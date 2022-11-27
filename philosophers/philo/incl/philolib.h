/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philolib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:59:12 by eros-gir          #+#    #+#             */
/*   Updated: 2022/11/27 16:43:51 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOLIB_H
# define PHILOLIB_H

# include<stdio.h>
# include<string.h>
# include<stdlib.h>
# include<unistd.h>
# include<sys/time.h>
# include<pthread.h>

typedef struct s_args
{
	long int	nbr_phil;
	long int	t_to_die;
	long int	t_to_eat;
	long int	t_to_slp;
	long int	nb_t_eat;
}	t_args;

int			ft_isdigit(int c);
long int	ft_atol(char *input);

#endif
