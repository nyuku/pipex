/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:48:07 by angnguye          #+#    #+#             */
/*   Updated: 2023/05/19 00:20:16 by angnguye         ###   ########.fr       */
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
* 	Structures
\*◇───────────────────────────────────────────────────────────────◇*/

typedef struct	s_pid
{
	unsigned int child_1;
	unsigned int child_2;
}				t_pid;

typedef struct s_pipex
{
	struct s_pid 	pid;
	int		fd_in;
	int		fd_out;
	int		**fd_pipe;
	char	**pipe_fd;
	char	*path_str;
	char	**path_variables;
	char	**cmd;
	char	*cmd_path_absolut;
	char	**envp;
	char	**cmd_args;
	char 	*cmmmmmd;

}				t_pipex;

/*◇───────────────────────────────────────────────────────────────◇*\
* 	Prototypes funtions
\*◇───────────────────────────────────────────────────────────────◇*/
//--------pipex_utils.c------//

int	print_message(char *str);
int error_fd(int fd, int stdin_out);
void pregnancy(t_pipex *pipex, char **av);
void free_alles(t_pipex *pipex);

//--------get_command.c------//
int	get_path(char **str, t_pipex *pipex);
char *get_command(t_pipex *pipex, char *command);

//--------pipex_utils_bis.c------//
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t count, size_t size);
static int	count_word(char const *s, char c);
static int	len_word(char const *s, char c, int i);
static char	*malloc_word(char const *s, char c, int index);
int ft_strlen(const char *str);
void	*ft_memset(void *p, int c, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
