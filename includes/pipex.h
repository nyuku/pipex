/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:48:07 by angnguye          #+#    #+#             */
/*   Updated: 2023/06/02 00:31:16 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include "ft_printf.h"
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>

# define ERROR_FD_IN "\nError to open the first file\n"
# define ERROR_FD_OUT "\nError to open the second file\n"
# define ERROR_FD_PIPE "\nError in return of pipe()\n"
# define ERROR_FORK "\nError with fork()\n"
/*◇───────────────────────────────────────────────────────────────◇*\
* 	Structures
\*◇───────────────────────────────────────────────────────────────◇*/

typedef struct s_cheni
{
	int		i;
	char	*cmd_path_absolut;
}				t_cheni;

typedef struct s_pipex
{
	t_cheni	cheni;
	char	**envp;
	int		fd_in;
	int		fd_out;
	int		pipe_fd[2];
	char	*path_str;
	char	**path_slices;

}				t_pipex;

/*◇───────────────────────────────────────────────────────────────◇*\
* 	Prototypes funtions
\*◇───────────────────────────────────────────────────────────────◇*/
void	get_path(t_pipex *pipex);
//--------new_utils.c------//
void	ft_putstr_fd(char *s, int fd);
void	open_files(char **argv, t_pipex *pipex);
void	process_child(char **argv, t_pipex pipex);
void	child_one(char *argv, t_pipex pipex);
void	child_two(char *argv, t_pipex pipex);
void	get_path(t_pipex *pipex);
char	*get_command(char *cmd, t_pipex pipex);

// void free_alles(t_pipex *pipex);

// //--------get_command.c------//
// int	get_path(char **envp, t_pipex *pipex);
// char *get_command(t_pipex *pipex, char *arg);

//--------pipex_utils_bis.c------//
void	check_pid_process( t_pipex pipex, int pid, int child, char **argv);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t count, size_t size);
int		count_word(char const *s, char c);
int		len_word(char const *s, char c, int i);
char	*malloc_word(char const *s, char c, int index);
int		ft_strlen(const char *str);
void	*ft_memset(void *p, int c, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
