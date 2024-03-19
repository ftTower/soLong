/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sas_pathfinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:44:47 by tauer             #+#    #+#             */
/*   Updated: 2024/03/19 12:48:15 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

char	**resolved_path(t_data *data, char **map, int x, int y)
{
	map[x][y] = 'X';
	if ((x > 0) && ((map[x - 1][y] == '0' || map[x - 1][y] == 'C' || map[x
			- 1][y] == 'E')))
		resolved_path(data, map, x - 1, y);
	if ((x < data->size_x) && ((map[x + 1][y] == '0' || map[x + 1][y] == 'C'
		|| map[x + 1][y] == 'E')))
		resolved_path(data, map, x + 1, y);
	if ((y < data->size_y) && ((map[x][y + 1] == '0' || map[x][y + 1] == 'C'
		|| map[x][y + 1] == 'E')))
		resolved_path(data, map, x, y + 1);
	if ((y > 0) && ((map[x][y - 1] == '0' || map[x][y - 1] == 'C' || map[x]
		[y - 1] == 'E')))
		resolved_path(data, map, x, y - 1);
	return (map);
}

int	check_acess_to_input(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'C')
				return (put_error_msg("❌ missing acess to collectibles"), 0);
			else if (map[x][y] == 'E')
				return (put_error_msg("❌ missing acess to exit"), 0);
			y++;
		}
		x++;
	}
	return (1);
}

int	correct_borders(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[x])
		if (borders(map[x++][y]))
			return (0);
	x--;
	while (map[x][y])
		if (borders(map[x][y++]))
			return (0);
	y--;
	while (x >= 0)
		if (borders(map[x--][y]))
			return (0);
	x++;
	while (y > 0)
		if (borders(map[x][y--]))
			return (0);
	return (1);
}
