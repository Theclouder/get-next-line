/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 00:07:43 by vduchi            #+#    #+#             */
/*   Updated: 2022/06/06 21:03:20 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	int		c;
	int		n_b;
	char	*buf;

	c = 0;
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
	static char	*chars;

	check = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!chars)
	{
		chars = (char *)malloc(sizeof(char) * 1);
		if (!chars)
			return (NULL);
		chars[0] = '\0';
	}
	chars = ft_read_file(chars, fd);
	str = ft_get_next_line(chars, &check);
	if (!str)
	{
		free(chars);
		return (NULL);
	}
	chars = ft_update_chars(chars, &check);
	if (!chars)
		free(chars);
	return (str);
}
/*
int	main(void)
{
	int		fd;
	char	*str;

	fd = open("2_file.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("String is: %s ->", str);
	free(str);
	str = get_next_line(fd);
	printf("String 2 is: %s ->", str);
	free(str);
	str = get_next_line(fd);
	printf("String 3 is: %s ->", str);
	free(str);
	str = get_next_line(fd);
	printf("String 4 is: %s ->", str);
	free(str);
	str = get_next_line(fd);
	printf("String 5 is: %s ->", str);
	return (0);
}
*/
