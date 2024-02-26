/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:20:06 by tauer             #+#    #+#             */
/*   Updated: 2024/02/19 19:26:37 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

char	*clean_linefeed(char *str)
{
	size_t	i;
	size_t	i2;
	char	*dup;

	i = 0;
	i2 = 0;
	while (str[i] && str[i] != '\n')
		i++;
	dup = (char *)malloc(sizeof(char) * (i + 1));
	while (i2 < i)
	{
		dup[i2] = str[i2];
		i2++;
	}
	dup[i2] = '\0';
	free(str);
	return (dup);
}

char	**get_map(char *path)
{
	int		fd;
	int		size;
	int		i;
	char	**map;
	char	*temp;

	i = 0;
	fd = open(path, O_RDONLY);
	size = count_line(fd);
	close(fd);
	map = (char **)malloc(sizeof(char *) * (size + 1));
	if (!map)
		return (NULL);
	fd = open(path, O_RDONLY);
	while (i < size)
	{
		temp = clean_linefeed(get_next_line(fd));
		map[i] = temp;
		i++;
	}
	map[i] = NULL;
	close(fd);
	// print_map(map);
	return (map);
}

int	count_line(int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	if (!line)
	{
		free(line);
		return (0);
	}
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (i);
}
