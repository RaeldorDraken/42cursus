/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipexlib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:46:43 by eros-gir          #+#    #+#             */
/*   Updated: 2022/05/24 12:14:48 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEXLIB_H
# define PIPEXLIB_H

# include<unistd.h>
# include<fcntl.h>
# include<stdlib.h>
# include<sys/wait.h>
# include<stdio.h>
# include"../libft/libft.h"

typedef struct s_pipex {
	int		infile;
	int		outfile;
	char	**command1;
	char	**command2;
	int		end[2];
}	t_pipex;

void	argerror(int ac);
#endif
