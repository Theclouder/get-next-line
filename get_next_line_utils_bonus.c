/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:15:48 by vduchi            #+#    #+#             */
/*   Updated: 2022/06/07 13:33:56 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

	i = -1;
	j = -1;
	count = -1;
	while (s1[++i] != '\0')
		;
	while (s2[++j] != '\0')
		;
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
	free((void *)s1);
	return (str);
}

char	*ft_realloc(char *str, int addr, unsigned int len)
{
	unsigned int	i;
	char			*tmp;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		tmp[i] = str[i + addr];
		i++;
	}
	tmp[i] = '\0';
	free(str);
	return (tmp);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	**ft_reserve_mem(char **chars, int fd)
{
	int		i;
	int		j;
	char	**tmp;

	i = -1;
	tmp = (char **)malloc(sizeof(char *) * (fd + 1));
	if (!tmp)
		return (NULL);
//	printf("Into cycle!\n");
	while (++i < fd)
	{
		j = -1;
		if (!chars || !chars[i])
			tmp[i] = (char *)malloc(sizeof(char) * 1);
		else
		{
//			printf("Chars: %s, Len: %d\n", chars[i], ft_strlen(chars[i]));
			tmp[i] = (char *)malloc(sizeof(char) * (ft_strlen(chars[i]) + 1));
			if (!tmp[i])
				return (NULL);
			while (chars[i][++j] != '\0')
				tmp[i][j] = chars[i][j];
			tmp[i][j] = '\0';
//			printf("Tmp: %s, J: %d\n", tmp[i], j);
		}
//		printf("Len %d\n", len);
		if (!tmp[i])
			return (NULL);
		if (i < fd && (i + 1) == fd)
			tmp[i] = (char *)malloc(sizeof(char) * 1);
		if (!tmp[i])
			return (NULL);
//		printf("Res: %s\n", tmp[i]);
	}
	tmp[i] = NULL;
//	i = -1;
//	printf("Created\n");
//	free(chars);
	return (tmp);
}
