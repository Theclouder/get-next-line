/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 22:25:04 by vduchi            #+#    #+#             */
/*   Updated: 2022/06/07 08:33:45 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("alternate_line_nl_no_nl.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("String is: %s -> ", str);
	free(str);
	str = get_next_line(fd);
	printf("String 2 is: %s -> ", str);
	free(str);
	str = get_next_line(fd);
	printf("String 3 is: %s -> ", str);
	free(str);
	str = get_next_line(fd);
	printf("String 4 is: %s -> ", str);
	free(str);
	str = get_next_line(fd);
	printf("String 5 is: %s -> ", str);
	free(str);
	str = get_next_line(fd);
	printf("String 6 is: %s -> ", str);
	free(str);
	str = get_next_line(fd);
	printf("String 7 is: %s -> ", str);
	free(str);
	str = get_next_line(fd);
	printf("String 8 is: %s -> ", str);
	free(str);
	str = get_next_line(fd);
	printf("String 9 is: %s -> ", str);
	free(str);
	str = get_next_line(fd);
	printf("String 10 is: %s", str);
	return (0);
}
