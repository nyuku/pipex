/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 00:48:57 by angnguye          #+#    #+#             */
/*   Updated: 2023/06/02 00:21:20 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	count_word(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**ptr;
	int		count_words;
	int		index;

	if (!s)
		return (0);
	count_words = count_word(s, c);
	ptr = ft_calloc((count_words + 1), sizeof(char *));
	if (!ptr)
		return (0);
	i = 0;
	index = 0;
	while (i < count_words && s[index] != '\0')
	{
		while (s[index] == c)
			index++;
		if (s[index] != '\0' && s[index] != c)
			ptr[i] = malloc_word(s, c, index);
		while (s[index] != c && s[index] != '\0')
			index++;
		i++;
		ptr[i] = 0;
	}
	return (ptr);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_memset(void *p, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)p;
	i = 0;
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (p);
}
