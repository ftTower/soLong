/*		************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:09:49 by tauer             #+#    #+#             */
/*   Updated: 2024/01/25 20:24:54 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	check_walls(t_data *data, int x, int y)
{
	char	c;

	if (x < 0 || x > data->size_x || y < 0 || y > data->size_y)
		return (0);
	c = data->map[x][y];
	return ((c == '1') || (c >= 'a' && c <= 'z') || c == 'E');
}

int	check_empty(t_data *data, int x, int y)
{
	char	c;

	if (x < 0 || x > data->size_x || y < 0 || y > data->size_y)
		return (0);
	c = data->map[x][y];
	return (c == '0' || c == 'C' || c == 'T' || c == 'V');
}

int	check_void(t_data *data, int x, int y)
{
	char	c;

	if (x < 0 || x > data->size_x || y < 0 || y > data->size_y)
		return (0);
	c = data->map[x][y];
	return (c == 'X');
}

int	check_next(t_data *data, int x, int y)
{
	char	next_cell;

	if (x < 0 || x >= data->size_x || y < 0 || y >= data->size_y)
		return (0);
	next_cell = data->map[x][y];
	if (next_cell == '0' || next_cell == '2' || next_cell == 'T'
		|| (next_cell == 'E' && data->collectibles_left == 0))
		return (1);
	return (0);
}

int	borders(char c)
{
	if (c == 'X')
	{
		print_simple_line();
		printf("map not closed\n");
		print_simple_line();
		return (1);
	}
	return (0);
}
