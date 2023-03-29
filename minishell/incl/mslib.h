/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mslib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:06:39 by eros-gir          #+#    #+#             */
/*   Updated: 2023/03/29 12:07:59 by eros-gir         ###   ########.fr       */
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
	char	*inputline;
	char	**inputcomm;
	int		inputlen;
	int		sigbool;
	int		s_quotes;
	int		d_quotes;
}	t_vars;

size_t	msh_maxvalue(size_t first, size_t second);
size_t	msh_strnum(const char *s, char c);

void	msh_count_quotes(t_vars *vars);

int		msh_check_quotes(t_vars *vars, char c);

char	**msh_split(char c, t_vars *vars, size_t n);

#endif