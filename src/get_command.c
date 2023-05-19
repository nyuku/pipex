/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 19:21:37 by angnguye          #+#    #+#             */
/*   Updated: 2023/05/19 00:02:31 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	get_path(char **envp, t_pipex *pipex)
{
	int	i;
	int len;

	len = ft_strlen("PATH=");
	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", len) == 0)//tant que pas pareil
		{
			pipex->path_str = ft_substr(envp[i], len, ft_strlen(envp[i]) - len);
			return (1);
		}
		i++;
	}
	write(2, "aie aie aie", 11);
	return(0);
}

char *get_command(t_pipex *pipex, char *command)//!! a free dans la fonction receptacle
{
	//pipex->path_variables contient 7 variables qu'on doit vérifier
	char *temp;
	char *cmd_path_absolut;//pas en structure....ca va changer car on test
	int i;

	i = 0;
	pipex->cmd = ft_split(command, ' ');//obtenir la commande nu
	while(pipex->path_variables[i] != NULL)//tant que access valide pas, on teste tout les paths
	{
		temp = ft_strjoin(pipex->path_variables[i], "/");//ajouter /
		cmd_path_absolut = ft_strjoin(temp, pipex->cmd[0]); //ajoute la commande
		free(temp);
		if (access(cmd_path_absolut, X_OK) == 0)
			return(cmd_path_absolut);
		free(cmd_path_absolut);//car pas trouver, on recommence
		i++;//on passe a la ligne de commande suivante
	}
	return(NULL);
}