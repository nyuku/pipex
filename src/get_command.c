/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 19:21:37 by angnguye          #+#    #+#             */
/*   Updated: 2023/05/12 01:04:30 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	get_path(char **str, t_pipex *pipex)
{
	int	i;

	i = 0;
	char path[5] = "PATH=";

	while (ft_strncmp(*str, path, 5) != 0)//tant que pas pareil
	{
		str++;
		i++;
	}
	if(ft_strncmp(*str, path, 5) != 0)//on a deja fait passél la boucle...
		return(-1);
	else
	{
		pipex->path_str = str[i];
		return (0);
	}
}

char *get_command(t_pipex *pipex, char *command)//!! a free dans la fonction receptacle
{
	//pipex->path_variables contient 7 variables qu'on doit vérifier
	char *temp;
	char *cmd_path_absolut;//pas en structure....ca va changer car on test
	pipex->cmd = ft_split(command, ' ');//obtenir la commande nu
	while(pipex->path_variables != NULL)//tant que access valide pas, on teste tout les paths
	{
		temp = ft_strjoin(pipex->path_variables, '/');//ajouter /
		cmd_path_absolut = ft_strjoin(temp, pipex->cmd); //ajoute la commande
		free(tmp);
		if (access(cmd_path_absolut, X_OK) == 0)
			return(cmd_path_absolut);
		free(cmd_path_absolut);//car pas trouver, on recommence
		pipex->path_variables++;//on passe a la ligne de commande suivante
	}
	return(NULL)
}