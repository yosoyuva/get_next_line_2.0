/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 21:48:28 by ymehdi            #+#    #+#             */
/*   Updated: 2020/01/24 16:09:13 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

struct	s_variables
{
	char		*buf;
	char		*tmp;
	int			ret;
}		;
int		get_next_line(int fd, char **line);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnew(int size, int a);
char	*ft_strchr(const char *s, int c);
int		ft_aux(char **red, char **line, int fd);
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strcat(char *s1, const char *s2);
int		ft_new_line(char **s, char **line, int fd, int ret);
void	ft_strdel(char **as);

#endif
