/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 00:07:43 by vduchi            #+#    #+#             */
/*   Updated: 2022/06/05 18:09:48 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 1
/*
char	*ft_strupd(char *chars, char *car)
{
	int		i;
//	char	*str;
//	char	*tmp;

	i = 0;
	if (!chars)
		return (NULL);
	car = ft_strchr(chars, '\n');
	if (!car)
	{
		free(chars);
		chars = NULL;
		return (NULL);
	}
	else
	{
		chars = ft_realloc(chars, (int)(ft_strchr(chars, *car) - chars + 1), (unsigned int)(ft_strchr(chars, '\0') - car));
		return (chars);
	}
//	str = (char *)malloc(sizeof(char) * (int)(car - chars + 2));
//	str[0] = '\0';
//	printf("calc: %d\n", (int)(car - chars + 2));
//	while (i < (int)(car - chars))
//	{
//		str[i] = chars[i];
//		i++;
//	}
//	printf("I is %d, and char is %c\n", i, str[i - 1]);
//	str[i] = '\0';
//	i = 0;
	if (car != (ft_strchr(chars, '\0') - 1))
	{
//		printf("Before: %s\n", chars);
//		printf("First is: %d, Second is %d\n", (int)(ft_strchr(chars, *car) - chars), (unsigned int)(ft_strchr(chars, '\0') - car));
//		chars = ft_realloc(chars, (int)(ft_strchr(chars, *car) - chars + 1), (unsigned int)(ft_strchr(chars, '\0') - car));
//		printf("After: %s\n", chars);
	}
	else
	{
		free(chars);
		chars = NULL;
	}
	return (chars);
}

char	*ft_read_bytes(int fd, char *chars)
{
	char	*buff;
	int		num_bites;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	buff[0] = '\0';
	while (!ft_strchr(chars, '\n'))
	{
		num_bites = read(fd, buff, BUFFER_SIZE);
		if (num_bites <= 0)
		{
//			printf("Here!\n");
//			free(buff);
//			buff = NULL;
//			return (NULL);
			break ;
		}
		buff[num_bites] = '\0';
		printf("Buff: %s\n", buff);
		chars = ft_strjoin(chars, buff);
//		printf("CHARS: %s\n", chars);
//		printf("1: %p\n", buff);
	}
	free(buff);
	buff = NULL;
//	printf("2: %p\n", buff);
	return (chars);
}

char	*ft_get_line(const char *chars, char *car)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 0;
	tmp = (char *)chars;
	car = ft_strchr(chars, '\n');
	if (!car)
		car = ft_strchr(chars, '\0')  - 1;
	printf("Calc: %d\n", (int)(car - chars + 2));
	str = (char *)malloc(sizeof(char) * (int)(car - chars + 2));
	if (!str)
		return (NULL);
//	printf("Calc is: %d\n", (int)(car - chars + 2));
	while (tmp != car)
	{
		str[i] = *tmp;
		i++;
		tmp++;
//		printf("Chars: %c\n", chars[i]);
	}
	str[i] = *(++tmp);
	str[i + 1] = '\0';
//	printf("Str: %s\n", str);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*car;
	char		*str;
	static char	*chars;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	chars = NULL;
	car = (char *)malloc(sizeof(char) * 1);
	chars = ft_read_bytes(fd, chars);
//	printf("%p, %p\n", car, chars);
	if (!chars)
	{
		free(car);
		free(chars);
		car = NULL;
		chars = NULL;
		return (NULL);
	}
	else
	{
		str = ft_get_line(chars, car);
		chars = ft_strupd(chars, car);
		if (!chars)
		{
			free(chars);
			chars = NULL;
		}
	}
	free(car);
	car = NULL;
	if (!str)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	return (str);
}


int	main(void)
{
	int		fd;
	char	*str;

	fd = open("file.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("String is: %s", str);
	free(str);
	str = get_next_line(fd);
	printf("String 2 is: %s", str);
	free(str);
	str = get_next_line(fd);
	printf("String 3 is: %s", str);
	free(str);
	str = get_next_line(fd);
	printf("String 4 is: %s", str);
	
	return (0);
}
*/

char	*ft_read_file(char *chars, int fd)
{
	int		n_b;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	buf[0] = '\0';
	while (!(ft_strchr(chars, '\n')))
	{
		n_b = read(fd, buf, BUFFER_SIZE);
		if (n_b <= 0)
		
	}
	return (chars);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*chars;

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
	str = ft_get_next_line(chars);
	chars = ft_update_chars(chars);
	return (str);
}

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("file.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("String is: %s", str);
	free(str);
	str = get_next_line(fd);
	printf("String 2 is: %s", str);
	free(str);
	str = get_next_line(fd);
	printf("String 3 is: %s", str);
	free(str);
	str = get_next_line(fd);
	printf("String 4 is: %s", str);
	return (0);
}
