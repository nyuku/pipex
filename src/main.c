/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:08:52 by angnguye          #+#    #+#             */
/*   Updated: 2023/05/04 18:58:24 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	print_message(char *str)
{
	ft_printf(str);
	return (0);
}

int	main(int argc, char **argv)
{
	t_pipex	pipex;

	if (argc != 5)
	{
		return (print_message("Not the right number of arguments"));
	}
	else
	{
		ft_printf("plop");
		pipex.pipe_in = open(argv[1], O_RDONLY);
		pipex.pipe_out = open(argv[4], O_WRONLY);
		
	}
}
