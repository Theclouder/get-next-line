/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 00:07:43 by vduchi            #+#    #+#             */
/*   Updated: 2022/11/28 20:47:06 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_update_chars(char *chars, int *check)
{
	int		len;
	int		start;

	len = -1;
	start = 0;
	if (!chars || !*check)
	{
		free(chars);
		chars = NULL;
		return (NULL);
	}
	else
	{
		while (chars[++len] != '\0')
		{
			if (chars[len] == '\n' && start == 0)
				start = len + 1;
		}
		if (start == 0)
			return (NULL);
		chars = ft_realloc(chars, start, len - start);
	}
	return (chars);
}

static char	*ft_get_next_line(char *chars, int *check)
{
	int		i;
	int		len;
	char	*str;

	i = -1;
	len = 0;
	if (!chars)
		return (NULL);
	while (chars[++i] != '\0')
	{
		if (chars[i] == '\n')
		{
			*check = *check + 1;
			break ;
		}
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + *check + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < (len + *check))
		str[i] = chars[i];
	str[i] = '\0';
	return (str);
}

static char	*ft_read_file(char *chars, int fd)
{
	int		n_b;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	buf[0] = '\0';
	while (!ft_strchr(buf, '\n'))
	{
		n_b = read(fd, buf, BUFFER_SIZE);
		if (n_b <= 0 && chars[0] != '\0')
			break ;
		else if (n_b <= 0 && buf[0] == '\0')
		{
			free(buf);
			free(chars);
			chars = NULL;
			return (NULL);
		}
		buf[n_b] = '\0';
		chars = ft_strjoin(chars, buf);
	}
	free(buf);
	return (chars);
}

char	*get_next_line(int fd)
{
	int			check;
	char		*str;
	static char	*chars[1024];

	check = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!chars[fd])
	{
		chars[fd] = ft_strdup("");
		if (!chars[fd])
			return (NULL);
	}
	chars[fd] = ft_read_file(chars[fd], fd);
	str = ft_get_next_line(chars[fd], &check);
	if (!str)
	{
		free(chars[fd]);
		return (NULL);
	}
	chars[fd] = ft_update_chars(chars[fd], &check);
	if (!chars[fd])
		free(chars[fd]);
	return (str);
}
