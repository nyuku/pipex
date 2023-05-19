/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 00:48:57 by angnguye          #+#    #+#             */
/*   Updated: 2023/05/19 00:20:02 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	slen;

	i = 0;
	slen = ft_strlen(s);
	if (!s)
		return (0);
	if (len > slen)
		len = slen;
	str = malloc (sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (i < len && start < slen)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}


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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((s1[i] && s2[i]) && (s1[i] == s2[i]))
			i++;
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	char	*str1;
	char	*str2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str1 = (char *)s1;
	str2 = (char *)s2;
	if (str1 == 0 || str2 == 0)
		return (NULL);
	ptr = malloc (sizeof(char) *(ft_strlen(str1) + ft_strlen(str2)+1));
	if (!ptr)
		return (0);
	while (str1[i])
	{
		ptr[i] = str1[i];
		i++;
	}
	while (str2[j])
		ptr[i++] = str2[j++];
	ptr[i] = '\0';
	return (ptr);
}

static int	count_word(char const *s, char c)
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

static int	len_word(char const *s, char c, int i)
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

static char	*malloc_word(char const *s, char c, int index)
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

int ft_strlen(const char *str)
{
		int i = 0;
    while(str[i] != '\0')
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
