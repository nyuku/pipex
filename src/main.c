/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:08:52 by angnguye          #+#    #+#             */
/*   Updated: 2023/05/13 00:14:18 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void child_one(char * command,t_pipex *pipex)
{
	close(pipex->pipe_fd[0]);//on ferme autre rentrée d'info inutile
	//entré
	dup2(pipex->pipe_fd[1], 1);// on vise deja la sortie
	close(pipex->pipe_fd[1])//on a fait une copie, on peut fermer l'original
	//
	dup2(pipex->fd_in, 0)// on liu dit ou pomper l'imfo
	close(pipex->fd_in); //on ferme l'original car plus besoin
	
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

void child_two(char * command,t_pipex *pipex)
{
	close(pipex->pipe_fd[1]) //fermer la source inutile selon la tache sinon imprime ailleurs

	dup2(pipex->pipe_fd[0], 0);//choper quelle entrée
	close(pipex->pipe_fd[0]);

	dup2(pipex->fd_out, 1);
	close(pipex->fd_out);
	
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
	int pipe_fd[2];//on devrait stocker en structure

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
		pipex.pipe_fd = pipe_fd;//on stock en static
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
