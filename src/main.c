/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:08:52 by angnguye          #+#    #+#             */
/*   Updated: 2023/06/02 00:30:44 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	open_files(char **argv, t_pipex *pipex)
{
	pipex->fd_in = open(argv[1], O_RDONLY);
	if (pipex->fd_in < 0)
	{
		perror("Error\n The file1 can't be open\n");
		exit (1);
	}
	pipex->fd_out = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex->fd_out < 0)
	{
		perror("Error\n The file2 can't be use\n");
		exit (1);
	}
}

void	check_pid_process( t_pipex pipex, int pid, int child, char **argv)
{
	if (pid < 0)
	{
		perror("Fork it! It doesn't work\n");
		exit(1);
	}
	else if (pid == 0 && child == 1)
	{
		child_one(argv[2], pipex);
		exit(0);
	}
	else if (pid == 0 && child == 2)
	{
		child_two(argv[3], pipex);
		exit(0);
	}
}

void	get_path(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->envp[i] != NULL)
	{
		if (ft_strncmp(pipex->envp[i], "PATH=", 5) == 0)
		{
			pipex->path_str = ft_substr(pipex->envp[i], \
			5, ft_strlen(pipex->envp[i]) - 5);
			break ;
		}
		i++;
	}
}

char	*get_command(char *cmd, t_pipex pipex)
{
	char	*temp;

	pipex.cheni.i = 0;
	pipex.cheni.cmd_path_absolut = NULL;
	get_path(&pipex);
	pipex.path_slices = ft_split(pipex.path_str, ':');
	if (!pipex.path_slices)
		free(pipex.path_slices);
	pipex.cheni.i = 0;
	while (pipex.path_slices[pipex.cheni.i] != NULL)
	{
		temp = ft_strjoin(pipex.path_slices[pipex.cheni.i], "/");
		pipex.cheni.cmd_path_absolut = ft_strjoin(temp, cmd);
		free(temp);
		if (access(pipex.cheni.cmd_path_absolut, X_OK) == 0)
			return (pipex.cheni.cmd_path_absolut);
		free(pipex.cheni.cmd_path_absolut);
		pipex.cheni.i++;
	}
	return (NULL);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	pipex.envp = envp;
	if (argc != 5)
	{
		ft_putstr_fd("Not the right number of arguments\n", 2);
		exit(1);
	}
	if (envp[0] == NULL)
		return (0);
	if (!argv[2] || !argv[3])
	{
		ft_putstr_fd("Problem with the commands\n", 2);
		exit(1);
	}
	open_files(argv, &pipex);
	process_child(argv, pipex);
	return (0);
}
