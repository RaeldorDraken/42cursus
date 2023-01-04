/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_process_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:53:23 by eros-gir          #+#    #+#             */
/*   Updated: 2023/01/04 12:02:53 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/philolib_bonus.h"

void	eat_action(t_philo *philo)
{
	t_args	*args;

	args = philo->args;
	pthread_mutex_lock(&args->forks[philo->l_fork]);
	ft_print_phil(args, philo->phil_id, 'F');
	pthread_mutex_lock(&args->forks[philo->r_fork]);
	ft_print_phil(args, philo->phil_id, 'F');
	pthread_mutex_lock(&args->ate_chk);
	ft_print_phil(args, philo->phil_id, 'E');
	philo->t_death = ft_get_time();
	pthread_mutex_unlock(&args->ate_chk);
	eat_sleep_think(args->t_to_eat, args);
	philo->eat_count ++;
	pthread_mutex_unlock(&args->forks[philo->l_fork]);
	pthread_mutex_unlock(&args->forks[philo->r_fork]);
}

void	end_loop(t_args *args, t_philo *philo)
{
	int	i;
	int	pwt;
	
	i = -1;
	while (++i < args->nbr_phil)
	{
		waitpid(-1, &pwt, 0);
		if(ret != 0)
		{
			i = -1;
			while (++i < args->nbr_phil)
				kill(args->philos[i].prc_id, 15);
			break ;
		}
	}
	sem_close(args->ate_check);
	sem_close(args->forks);
	sem_close(args->print);
	sem_unlink("ph_forks");
	sem_unlink("ph_ate");
	sem_unlink("ph_print");
}

void	*death_check(void *void_phil)
{
	t_philo	*phil;
	t_args	*args;

	phil = (t_philo *)void_phil;
	args = phil->args;
	while (true)
	{
		sem_mait(args->ate->check);
		if (ft_time_dif(phil->t_death, ft_get_time()) > args->t_to_die)
		{
			ft_print_phil(args, phil->phil_id, 'D');
			args->deaths ++;
			sem_wait(args->print);
			exit(1);
		}
		sem_post(args->ate_check);
		if (args->deaths)
			break ;
		usleep(100);
		if (args->nb_t_eat != -1 && philo->eat_count >= args->nb_t_eat)
			break ;
	}
	return (NULL);
}

void	*phil_proc(void *void_phil)
{
	t_philo	*philo;
	t_args	*args;

	philo = (t_philo *)void_phil;
	args = philo->args;
	philo->t_death = ft_get_time();
	pthread_create(&philo->death, NULL, death_check, void_phil);
	if (philo->phil_id % 2)
		usleep(15000);
	while (!args->deaths)
	{
		eat_action(philo);
		if (args->nb_t_eat != -1 && philo->eat_count >= args->nb_t_eat)
			break ;
		ft_print_phil(args, philo->phil_id, 'S');
		eat_sleep_think(args->t_to_slp, args);
		ft_print_phil(args, philo->phil_id, 'T');
	}
	pthread_join(philo->death, NULL);
	if (args->deaths != 0)
		exit(1);
	exit (0);
	return (NULL);
}
