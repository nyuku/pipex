/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 21:42:49 by angnguye          #+#    #+#             */
/*   Updated: 2023/06/01 22:20:29 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	ptr = 0;
	ptr = (char *)(malloc(size * count));
	if (!ptr)
		return (0);
	ft_memset(ptr, 0, size * count);
	return (ptr);
}

int	len_word(char const *s, char c, int i)
{
	int	count;

	count = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		count++;
	}
	return (count);
}

char	*malloc_word(char const *s, char c, int index)
{
	int		len;
	int		i;
	char	*ptr;

	len = len_word(s, c, index);
	ptr = ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (0);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[index];
		i++;
		index++;
	}
	ptr[i] = '\0';
	return (ptr);
}
