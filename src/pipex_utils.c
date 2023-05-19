/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 19:15:29 by angnguye          #+#    #+#             */
/*   Updated: 2023/05/19 00:23:22 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"


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
			//stop
		if (stdin_out == 1)
			ft_print_unsigned(ERROR_FD_OUT);
			//stop
		if (stdin_out == 2)
			ft_print_unsigned(ERROR_FD_PIPE);
			//fstop
		if (stdin_out == 3)
			ft_print_unsigned(ERROR_FORK);

	}
	else
		return(0);
}

void pregnancy(t_pipex *pipex, char **argv)
{
	pipex->pid.child_1 = fork();
	if (error_fd(pipex->pid.child_1, 3) == 0)
		child_one(av,pipex);
	pipex->pid.child_2 = fork();
	if (error_fd(pipex->pid.child_2, 3) == 0)
		child_one(av,pipex);
	if(pipex->pid.child_1 < 0 || pipex->pid.child_2 < 0)
		exit(0);
		// free le tout();

}

void free_split(t_pipex *pipex)
{

}
void free_alles(t_pipex *pipex)
{
	int	i;

	i = 0;
	close (pipex->fd_in);
	close (pipex->fd_out);
	//free les lignes
	while(pipex->path_variables[i] != NULL)//tant que c'est plein
		free(pipex->path_variables[i++]);//a revoir l'ecriture
	free(pipex->path_variables); // free le pointeur du tableau	
}