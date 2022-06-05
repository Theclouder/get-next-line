/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:15:48 by vduchi            #+#    #+#             */
/*   Updated: 2022/06/05 17:06:33 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	if ((char)c == '\0')
	{
		while (*s != '\0')
			s++;
		return ((char *)s);
	}
	else
	{
		while (*s != '\0')
		{
			if (*s == (char)c)
				return ((char *)s++);
			s++;
		}
		return (NULL);
	}
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		count;
	char	*str;

	i = 0;
	j = 0;
	count = -1;
	if (s1)
	{
		while (s1[i] != '\0')
			i++;
	}
	while (s2[j] != '\0')
		j++;
	str = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!str)
		return (NULL);
	while (++count < (i + j))
	{
		if (count < i)
			str[count] = s1[count];
		else
			str[count] = s2[count - i];
	}
	str[count] = '\0';
	return (str);
}

char	*ft_realloc(char *str, int addr, unsigned int len)
{
	int		i;
	char	*tmp;

	i = 0;
	printf("Realloc-> addr: %d, car at addr: %c, len %d, car at len %c\n", addr, str[addr], len, str[addr + len]);
	tmp = (char *)malloc(sizeof(char) * len);
	while (str[i] != '\0')
	{
		tmp[i] = str[i + addr];
		i++;
	}
	tmp[i] = '\0';
	free(str);
	return (tmp);
}
