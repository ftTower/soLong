/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sas_check_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:15:50 by tauer             #+#    #+#             */
/*   Updated: 2024/03/21 14:53:14 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

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
	return (c == '0' || c == 'P' || c == 'C' || c == 'V');
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
	if (next_cell == '0' || next_cell == '2' || next_cell == 'C'
		|| (next_cell == 'E' && data->collectibles_left == 0))
		return (1);
	return (0);
}

int	borders(char c)
{
	if (c == 'X')
	{
		print_simple_line();
		printf("[❌ map not closed]\n");
		print_simple_line();
		return (1);
	}
	return (0);
}
