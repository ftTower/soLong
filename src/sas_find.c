/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sas_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:43:37 by tauer             #+#    #+#             */
/*   Updated: 2024/03/19 15:50:21 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	find_bad_map_size(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
			y++;
		if (data->size_y != y - 1)
		{
			print_simple_line();
			printf("[SIZE LINE]\n\nin line[%d]\nlen    [%d]\nneeded [%d]\n", x,
				y - 1, data->size_y);
			print_simple_line();
			map_erreur_size(data->map, x);
			return (1);
		}
		x++;
	}
	return (0);
}

bool	find_first_border(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] != '0')
			{
				data->first_wall_x = x;
				data->first_wall_y = y;
				return (false);
			}
			y++;
		}
		x++;
	}
	return (true);
}

bool	find_bad_char(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (bad_char(data->map[x][y]))
			{
				print_simple_line();
				ft_printf("[BAD CHAR]\n\nin position");
				ft_printf(" [%d][%d]\nchar:\t\t [%c]\n\t [0;1;C;T;E]\n", x, y,
					data->map[x][y]);
				map_erreur_char(data->map);
				return (true);
			}
			y++;
		}
		x++;
	}
	return (false);
}

bool	find_exit(t_data *data, int *exit)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] == 'E')
			{
				(*exit)++;
				if (place_exit_is_correct(data, x, y))
					return (true);
			}
			y++;
		}
		x++;
	}
	return (false);
}
