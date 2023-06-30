/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 00:11:02 by angnguye          #+#    #+#             */
/*   Updated: 2023/06/02 00:12:03 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	process_child(char **argv, t_pipex pipex)
{
	pid_t	pid;

	pipe(pipex.pipe_fd);
	pid = fork();
	check_pid_process(pipex, pid, 1, argv);
	pid = fork();
	check_pid_process(pipex, pid, 2, argv);
	close(pipex.pipe_fd[0]);
	close(pipex.pipe_fd[1]);
	while (wait(NULL) == -1)
		continue ;
}

void	child_one(char *argv, t_pipex pipex)
{
	char	**tab_cmd;
	char	*cmd_path;

	tab_cmd = ft_split(argv, ' ');
	dup2(pipex.fd_in, 0);
	dup2(pipex.pipe_fd[1], 1);
	close(pipex.pipe_fd[0]);
	close(pipex.pipe_fd[1]);
	cmd_path = get_command(tab_cmd[0], pipex);
	if (cmd_path)
	{
		execve (cmd_path, tab_cmd, pipex.envp);
		exit(0);
	}
	perror("ERROR!\n can't do first command\n");
	exit(1);
}

void	child_two(char *argv, t_pipex pipex)
{
	char	**tab_cmd;
	char	*cmd_path;

	tab_cmd = ft_split(argv, ' ');
	dup2(pipex.fd_out, 1);
	dup2(pipex.pipe_fd[0], 0);
	close(pipex.pipe_fd[1]);
	close(pipex.pipe_fd[0]);
	cmd_path = get_command(tab_cmd[0], pipex);
	if (cmd_path)
	{
		execve (cmd_path, tab_cmd, pipex.envp);
		exit(0);
	}
	perror("ERROR!\n can't do 2nd command\n");
	exit(1);
}
