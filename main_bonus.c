/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 22:25:04 by vduchi            #+#    #+#             */
/*   Updated: 2022/06/07 11:06:43 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd1 = open("alternate_line_nl_no_nl.txt", O_RDONLY);
	int		fd2 = open("multiple_line_no_nl.txt", O_RDONLY);
	int		fd3 = open("41_no_nl.txt", O_RDONLY);
	int		fd4 = open("multiple_nlx5.txt", O_RDONLY);
	char	*str;

	printf("FD1: %d, FD2: %d, FD3: %d, FD4: %d\n", fd1, fd2, fd3, fd4);
	str = get_next_line(fd1);
	printf("FD1 String 1 is: %s\n", str);
	free(str);
	str = get_next_line(fd2);
	printf("FD2 String 1 is: %s\n", str);
//	free(str);
//	str = get_next_line(fd3);
//	printf("FD3 String 1 is: %s\n", str);
//	free(str);
//	str = get_next_line(fd4);
//	printf("FD4 String 1 is: %s\n", str);
//	free(str);
//	str = get_next_line(fd3);
//	printf("FD3 String 2 is: %s\n", str);
	free(str);
	str = get_next_line(fd2);
	printf("FD2 String 2 is: %s\n", str);
	free(str);
	str = get_next_line(fd1);
	printf("FD1 String 2 is: %s\n", str);
//	free(str);
//	str = get_next_line(fd4);
//	printf("FD4 String 2 is: %s\n", str);
	free(str);
	str = get_next_line(fd1);
	printf("FD1 String 3 is: %s\n", str);
//	free(str);
//	str = get_next_line(fd4);
//	printf("FD4 String 3 is: %s\n", str);
//	free(str);
//	str = get_next_line(fd4);
//	printf("FD4 String 4 is: %s\n", str);
	free(str);
	str = get_next_line(fd2);
	printf("FD2 String 3 is: %s\n", str);
//	free(str);
//	str = get_next_line(fd3);
//	printf("FD3 String 3 is: %s\n", str);
//	free(str);
//	str = get_next_line(fd3);
//	printf("FD3 String 4 is: %s\n", str);
	free(str);
	str = get_next_line(fd1);
	printf("FD1 String 4 is: %s\n", str);
	free(str);
	str = get_next_line(fd2);
	printf("FD2 String 4 is: %s\n", str);
//	free(str);
//	str = get_next_line(fd4);
//	printf("FD4 String 5 is: %s\n", str);
	free(str);
	str = get_next_line(fd1);
	printf("FD1 String 5 is: %s\n", str);
	free(str);
	str = get_next_line(fd2);
	printf("FD2 String 5 is: %s\n", str);
//	free(str);
//	str = get_next_line(fd3);
//	printf("FD3 String 5 is: %s\n", str);
	free(str);
	str = get_next_line(fd1);
	printf("FD1 String 6 is: %s\n", str);
	free(str);
	str = get_next_line(fd2);
	printf("FD2 String 6 is: %s\n", str);
//	free(str);
//	str = get_next_line(fd3);
//	printf("FD3 String 6 is: %s\n", str);
//	free(str);
//	str = get_next_line(fd4);
//	printf("FD4 String 6 is: %s\n", str);
	free(str);
	str = get_next_line(fd1);
	printf("FD1 String 7 is: %s\n", str);
	free(str);
	str = get_next_line(fd1);
	printf("FD1 String 8 is: %s\n", str);
	free(str);
	str = get_next_line(fd1);
	printf("FD1 String 9 is: %s\n", str);
	return (0);
}
