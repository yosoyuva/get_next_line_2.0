/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 18:46:19 by ymehdi            #+#    #+#             */
/*   Updated: 2019/12/20 13:45:11 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <time.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putendl(const char *s)
{
	int	i;

	i = 0;
	if (s)
		while (s[i] != '\0')
		{
			ft_putchar(s[i]);
			i++;
		}
	ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putendl(line);
		free(line);
	}
	if (argc == 2)
		close(fd);
}
