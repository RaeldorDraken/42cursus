/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mslib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:06:39 by eros-gir          #+#    #+#             */
/*   Updated: 2023/04/12 13:05:08 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSLIB_H
# define MSLIB_H

# include<stdio.h>
# include<readline/readline.h>
# include<readline/history.h>
# include<fcntl.h>
# include<sys/wait.h>
# include<sys/stat.h>
# include<sys/ioctl.h>
# include<signal.h>
# include<dirent.h>
# include<termios.h>
# include<curses.h>
# include<term.h>

# include"../libft/libft.h"

typedef struct s_vars
{
	char	*prompt;
	char	*inpli;
	char	**inpcomm;
	char	**accomm;
	int		inplen;
	int		sigbool;
}	t_vars;

size_t	msh_maxvalue(size_t first, size_t second);
size_t	msh_strnum(const char *s, char c);

int		msh_check_quotes(t_vars *vars, char c, int i);
int		msh_getting_commands(t_vars *vars);

char	**msh_split(char c, t_vars *vars, size_t n, int i);
char	**msh_setsplit(int *quote, size_t *strn, t_vars *vars, char c);

void	msh_acptd_comm(t_vars *vars);
void	msh_free_commands(t_vars *vars);

#endif