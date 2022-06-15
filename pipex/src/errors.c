/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:42:07 by eros-gir          #+#    #+#             */
/*   Updated: 2022/06/15 12:32:37 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipexlib.h"

void	error_terminate(char *e, t_pipex *pobj)
{
	perror(e);
	close_fds(pobj);
	exit(EXIT_FAILURE);
}

void	argerror(int ac)
{
	char	*arg;

	arg = ft_itoa(ac - 1);
	ft_putstr_fd("ERROR: wrong number of arguments. \n", 2);
	ft_putstr_fd("expected: 4 got: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("\n", 2);
	free(arg);
	exit(EXIT_FAILURE);
}

void	cmd_error(char **cmd)
{
	write(2, cmd[0], ft_strlen(cmd[0]));
	write(2, ": command not found\n", 20);
	exit(EXIT_FAILURE);
}
