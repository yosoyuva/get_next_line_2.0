/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 21:48:28 by ymehdi            #+#    #+#             */
/*   Updated: 2019/12/19 03:22:30 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *s1);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnew(size_t size);
char	*ft_strchr(const char *s, int c);
int		ft_aux(char **red, char **line, int fd);
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strcat(char *s1, const char *s2);
int		ft_new_line(char **s, char **line, int fd, int ret);

#endif
