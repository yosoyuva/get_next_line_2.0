/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 21:46:23 by ymehdi            #+#    #+#             */
/*   Updated: 2019/12/20 22:03:27 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		l1;
	int		l2;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (l1 + l2 + 1))))
		return (NULL);
	str = ft_strcpy(str, s1);
	str = ft_strcat(str, s2);
	return (str);
}

char	*ft_strnew(size_t size)
{
	void		*s;
	size_t		i;

	i = 0;
	if ((s = malloc(size + 1)) == NULL)
		return (NULL);
	while (i < size + 1)
	{
		((char *)s)[i] = '\0';
		i++;
	}
	return (s);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == 0)
		return ((char *)&s[i]);
	return (NULL);
}

int		ft_aux(char **red, char **line, int fd)
{
	char	*tmp;
	int		i;

	i = 0;
	while (red[fd][i] != '\n' && red[fd][i] != '\0')
		i++;
	if (red[fd][i] == '\n')
	{
		if (((*line = ft_strsub(red[fd], 0, i)) == NULL))
			return -1;
		if ((tmp = ft_strdup(red[fd] + i + 1)) == NULL)
			return -1;
		free(red[fd]);
		red[fd] = tmp;
		if (red[fd][0] == '\0')
		{
			free(red[fd]);
			red[fd] = NULL;
		}
	}
	else if (red[fd][i] == '\0')
	{
		if((*line = ft_strdup(red[fd])) == NULL)
			return -1;
		free(red[fd]);
		red[fd] = NULL;
		return 0;
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*red[1024];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (red[fd] == NULL)
			if (!(red[fd] = ft_strnew(1)))
				return (-1);
		if (!(tmp = ft_strjoin(red[fd], buf)))
			return (-1);
		free(red[fd]);
		red[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (red[fd] == NULL || red[fd][0] == '\0'))
	{	
		*line = ft_strnew(0);
		return (0);
	}
	return (ft_aux(red, line, fd));
}
