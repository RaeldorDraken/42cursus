/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mslib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:06:39 by eros-gir          #+#    #+#             */
/*   Updated: 2023/02/21 11:08:14 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSLIB_H
# define MSLIB_H

# include<stdio.h>
# include<readline/readline.h>
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
	int		inputlen;
}	t_vars;

#endif