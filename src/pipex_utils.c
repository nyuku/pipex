/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 19:15:29 by angnguye          #+#    #+#             */
/*   Updated: 2023/06/01 21:41:02 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	error_fd(int fd, int stdin_out)
{
	if (fd < 0)
	{
		if (stdin_out == 0)
			ft_printf(ERROR_FD_IN);
		if (stdin_out == 1)
			ft_print_unsigned(ERROR_FD_OUT);
		if (stdin_out == 2)
			ft_print_unsigned(ERROR_FD_PIPE);
		if (stdin_out == 3)
			ft_print_unsigned(ERROR_FORK);
	}
	return (fd);
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
