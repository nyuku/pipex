/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:08:52 by angnguye          #+#    #+#             */
/*   Updated: 2023/05/12 01:50:43 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void child_one(char * command,t_pipex *pipex)
{
	char *cmd; // a free car va stocker une pointeur sur str qui est malloc
	char *cmd_naked;
	cmd_naked = ft_split(command, ' ');
	cmd = get_command(command);
	if (!cmd)//secu
	{
		free tout;
		ft_printf("command not found\n");
		exit(127);//uel autre code
	}
	execve(cmd, cmd_naked, envp);
	free(cmd_naked);
	free(cmd);
	exit(1);
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
		pipex.path_variables = ft_split(pipex.path_str, ':');//!malloc
		if(!pipex.path_variables)
			free_tableau_split(-1);
		pregnancy(&pipex, argv[2],argv[3]);
		waipid(pipex.pid.child_1, NULL, 0);
		waipid(pipex.pid.child_2, NULL, 0);
		free_alles(&pipex);
	}
	return (0);
}
