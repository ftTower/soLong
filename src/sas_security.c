/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sas_security.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:20:03 by tauer             #+#    #+#             */
/*   Updated: 2024/03/18 12:20:03 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void put_error_msg(char *error_msg)
{
	print_simple_line();
	ft_printf("%s\n", error_msg);
	print_simple_line();
}

int check_collectibles(char **map)
{
	int x;
	int y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'C')
				return (put_error_msg("tout les collectibles ne sont pas accessibles"), 0);
			else if (map[x][y] == 'E')
				return (put_error_msg("la sortie nest pas accessibles"), 0);
			y++;
		}
		x++;
	}
	return (1);
}

int correct_borders(char **map)
{
	int x;
	int y;

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

int find_first_border(t_data *data)
{
	int x;
	int y;

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
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}

int bad_char(char c)
{
	if (c == 'C' || c == 'E' || c == 'D' || c == 'P' || c == '1' || c == '0')
		return (0);
	return (1);
}

bool find_exit(t_data *data, int *exit, int x, int y)
{
	if (data->map[x][y] == 'E')
	{
		exit++;
		if (data->switcher == 0)
		{
			data->switcher++;
			if (check_walls(data, x + 1, y) && (check_walls(data, x - 1,
															y)))
			{
				data->map[x][y] = '0';
				data->map[x - 1][y] = 'E';
			}
			else if (check_walls(data, x + 1, y))
			{
				data->map[x][y] = '0';
				data->map[x + 1][y] = 'E';
			}
			else if (check_walls(data, x - 1, y))
			{
				data->map[x][y] = '0';
				data->map[x - 1][y] = 'E';
			}
			else
			{
				print_simple_line();
				write(1, "door not connected\n", 20);
				map_erreur(data->map, data);
				print_simple_line();
				return (true);
			}
		}
	}
	return (false);
}

	int holy_find(t_data * data)
	{
		int x;
		int y;
		int collectible;
		int character;
		int exit;

		x = 0;
		y = data->size_y + 1;
		collectible = 0;
		character = 0;
		exit = 0;
		data->switcher = 0;
		while (data->map[x])
		{
			if (data->size_y != y - 1)
			{
				print_simple_line();
				printf("[SIZE LINE]\n\nin line[%d]\nlen    [%d]\nneeded [%d]\n", x,
					   y - 1, data->size_y);
				map_erreur_size(data->map, data, x);
				return (0);
			}
			y = 0;
			while (data->map[x][y])
			{
				if (bad_char(data->map[x][y]))
				{
					print_simple_line();
					printf("[BAD CHAR]\n\nin position [%d][%d]\nchar:\t\t [%c]\n\t [0;1;C;T;E]\n",
						   x, y, data->map[x][y]);
					map_erreur_char(data->map);
					return (0);
				}
				if (data->map[x][y] == 'C')
					collectible++;
				else if (data->map[x][y] == 'P')
					character++;
				else if (find_exit(data, &exit, x, y))
					return (0);
				y++;
			}
		x++;
		}
	if (collectible > 0 && character == 1 && exit == 1)
		return (1);
	print_simple_line();
	write(1, "[BAD MAP]\n\n", 12);
	printf("collectibles : [%d]->[>0]\ncharacter    : [%d]->[ 1]\nexit\t     : [%d]->[ 1]\n\n",collectible, character, exit);
	print_simple_line();
	return (0);
}

int map_ok(t_data *data)
{
	char **dup;

	if (!holy_find(data))
	{
		write(1, "returned in holy_find\n", 23);
		print_simple_line();
		return (0);
	}
	dup = get_map(data->map_path);
	if (!dup)
		return (0);
	resolved_path(data, dup, data->x, data->y);
	if (check_collectibles(dup) && correct_borders(dup))
	{
		delete_emptyness(data, dup);
		free_map(dup);
		return (1);
	}
	else
		map_erreur(dup, data);
	free_map(dup);
	return (0);
}
