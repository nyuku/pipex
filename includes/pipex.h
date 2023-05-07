/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:48:07 by angnguye          #+#    #+#             */
/*   Updated: 2023/05/06 20:12:35 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include "ft_printf.h"
# include "libft.h"

# define ERROR_FD_IN "Error to open the first file"
# define ERROR_FD_OUT "Error to open the second file"
# define ERROR_FD_PIPE "Error in return of pipe()"

typedef struct	s_pid
{
	unsigned int child_1;
	unsigned int child_2;
}				t_pid;

typedef struct s_pipex
{
	s_pid 	pid;
	int	fd_in;
	int	fd_out;
	int **fd_pipe;
	char *path_str;
	char **path_cmd;
}				t_pipex;

#endif
