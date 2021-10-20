/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:25:31 by bnaji             #+#    #+#             */
/*   Updated: 2021/10/20 18:21:25 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_me(char *strget, int fd, int *len)
{
	strget = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	*len = read(fd, strget, BUFFER_SIZE);
	strget[*len] = 0;
	return (strget);
}

char	*free_me(char *str)
{
	free (str);
	str = NULL;
	return (str);
}

char	*allocate_me_plz(char *buffer)
{
	buffer = (char *)malloc(sizeof(char));
	*buffer = 0;
	return (buffer);
}

char	*return_strline(char *buffer, char **strline, int len)
{
	char	*tmp;
	char	*n;

	n = ft_strchr(buffer, '\n');
	if (n)
	{
		*strline = ft_substr(buffer, 0, n - buffer + 1);
		tmp = ft_substr(buffer, n - buffer + 1, ft_strlen(n + 1));
		buffer = free_me(buffer);
		buffer = ft_strdup(tmp);
		tmp = free_me(tmp);
		return (buffer);
	}
	else
	{
		if (len < BUFFER_SIZE)
		{
			*strline = ft_strdup(buffer);
			buffer = free_me(buffer);
		}
		return (buffer);
	}
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*strline;
	int			len;
	char		*strget;

	strline = NULL;
	if (fd < 0 || fd > 255)
		return (NULL);
	while (!strline)
	{
		strget = read_me(strget, fd, &len);
		if (!buffer)
			buffer = allocate_me_plz(buffer);
		if (!*strget && !*buffer)
		{
			buffer = free_me(buffer);
			strget = free_me(strget);
			break ;
		}
		buffer = ft_strjoin(buffer, strget);
		strget = free_me(strget);
		buffer = return_strline(buffer, &strline, len);
	}
	return (strline);
}
