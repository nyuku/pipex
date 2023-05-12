/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:48:07 by angnguye          #+#    #+#             */
/*   Updated: 2023/05/13 00:56:24 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include "ft_printf.h"
# include <stdlib.h>
# include <stddef.h>

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

//--------pipex_utils_bis.c------//
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t count, size_t size);
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
	char	**pipe_fd;
	char	*path_str;
	char	**path_variables;
	char	*cmd;
	char	*cmd_path_absolut;
}				t_pipex;

#endif
