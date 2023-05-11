/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:48:07 by angnguye          #+#    #+#             */
/*   Updated: 2023/05/12 01:50:39 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include "ft_printf.h"
# include "libft.h"

# define ERROR_FD_IN "\nError to open the first file\n"
# define ERROR_FD_OUT "\nError to open the second file\n"
# define ERROR_FD_PIPE "\nError in return of pipe()\n"
# define ERROR_FORK "\nError with fork()\n"
/*◇───────────────────────────────────────────────────────────────◇*\
* 	Prototypes funtions
\*◇───────────────────────────────────────────────────────────────◇*/
//--------pipex_utils.c------//

int	print_message(char *str);
int error_fd(int fd, int stdin_out);
void pregnancy(t_pipex *pipex);
void free_alles(t_pipex *pipex);

//--------get_command.c------//
int	get_path(char **str, t_pipex *pipex);

/*◇───────────────────────────────────────────────────────────────◇*\
* 	Structures
\*◇───────────────────────────────────────────────────────────────◇*/
typedef struct	s_pid
{
	unsigned int child_1;
	unsigned int child_2;
}				t_pid;

typedef struct s_pipex
{
	s_pid 	pid;
	int		fd_in;
	int		fd_out;
	int		**fd_pipe;
	char	*path_str;
	char	**path_variables;
	char	*cmd;
	char	*cmd_path_absolut;
}				t_pipex;

#endif
