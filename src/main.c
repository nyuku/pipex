/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:08:52 by angnguye          #+#    #+#             */
/*   Updated: 2023/05/06 20:21:49 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	get_path(char **str, t_pipex *pipex)
{
	int	i;

	i = 0;
	char *path = "PATH=";

	while (strncmp(*str, path, 5) != 0)
	{
		str++;
		i++;
	}
	pipex->path_str = str[i];
	return (0);
}

int	print_message(char *str)
{
	ft_printf(str);
	return (0);
}

int error_fd(int fd, int stdin_out)
{
	if (fd < 0)
	{
		if (stdin_out == 0)
			ft_printf(ERROR_FD_IN);
		if (stdin_out == 1)
			ft_print_unsigned(ERROR_FD_OUT);
		if (stdin_out == 2)
			ft_print_unsigned(ERROR_FD_PIPE);

	}
	else
		return(0);
}

void pregnancy(t_pipex *pipex)
{
	pipex->pid.child_1 = fork();
	if (pipex->pid.child_1 == 0)
		lance le process
	if (pipex->pid.child_2 == 0)
		lance le 2eme process 
	else
		ft_printf("error fork\n");


}

char **get_command(t_pipex *pipex)
{

}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int pipe_fd[2];

	if (argc != 5)
	{
		return (print_message("Not the right number of arguments"));
	}
	else
	{
		pipex.fd_in = open(argv[1], O_RDONLY);
		pipex.fd_out = open(argv[4], O_WRONLY);
		error_fd(pipex.fd_in, 0);
		error_fd(pipex.fd_out, 1);
		error_fd(pipe(pipe_fd), 2);
		get_path(*envp, &pipex);
		pipex.path_cmd = ft_split(pipex.path_str, ':');
		choper les commandes?
		pregnancy(&pipex);
		waipid(pipex.pid.child_1, NULL, 0);
		waipid(pipex.pid.child_2, NULL, 0);
		free les tuyau? et les tableaux

	}

	return (0);
}
