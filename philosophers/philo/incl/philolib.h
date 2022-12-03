/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philolib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:59:12 by eros-gir          #+#    #+#             */
/*   Updated: 2022/12/03 12:49:29 by eros-gir         ###   ########.fr       */
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

struct s_args;

typedef struct s_philo
{
	int				l_fork;
	int				r_fork;
	long int		phil_id;
	long int		t_death;
	long int		eat_count;
	struct s_args	args;
	pthread_t		thread_id;
}	t_philo;

typedef struct s_args
{
	long int	nbr_phil;
	long int	t_to_die;
	long int	t_to_eat;
	long int	t_to_slp;
	long int	nb_t_eat;
	long int	s_timer;
	long int	timer;
}	t_args;

void		ft_print_phil(long int time, long int philnum, char action);
int			ft_isdigit(int c);
long int	ft_atol(char *input);
long int	ft_get_time(void);
long int	ft_set_delta_time(t_args *args);

#endif
