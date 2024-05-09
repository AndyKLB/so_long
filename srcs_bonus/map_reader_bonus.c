/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:46:51 by ankammer          #+#    #+#             */
/*   Updated: 2024/04/24 15:17:39 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <stdio.h>

char	**map_reader(char *path)
{
	int		fd;
	char	*line;
	char	*buff;
	char	**map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	buff = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		buff = ft_strjoin(buff, line);
		free(line);
	}
	map = ft_split(buff, '\n');
	free(buff);
	close(fd);
	return (map);
}
