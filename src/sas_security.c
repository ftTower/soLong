/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/01/07 00:51:19 by marvin            #+#    #+#             */
/*   Updated: 2024/01/07 00:51:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"


int	check_collectibles(char **map)
{
	int x;
	int y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'T')
			{
				print_simple_line();
				write(1, "tout les collectibles ne sont pas accessibles\n",
					47);
				print_simple_line();
				return (0);
			}
			else if (map[x][y] == 'E')
			{
				print_simple_line();
				write(1, "la sortie nest pas accessibles\n", 32);
				print_simple_line();

				return (0);
			}
			y++;
		}
		x++;
	}
	return (1);
}

int	correct_borders(char **map)
{
	int x;
	int y;

	x = 0;
	y = 0;

	while (map[x])
	{
		if (borders(map[x][y]))
			return (0);
		x++;
	}
	x--;
	while (map[x][y])
	{
		if (borders(map[x][y]))
			return (0);
		y++;
	}
	y--;
	while (x >= 0)
	{
		if (borders(map[x][y]))
			return (0);
		x--;
	}
	x++;
	while (y > 0)
	{
		if (borders(map[x][y]))
			return (0);
		y--;
	}
	return (1);
}

int	find_first_border(t_data *data)
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

// refaire map ok pour custom decoration
// pose un D aleatoirement au debut et fait un full fill pour
// savoir si les collectibles et la sortie sont toujours accessible

int	bad_char(char c)
{
	if (c == 'T')
		return (0);
	else if (c == 'E')
		return (0);
	else if (c == 'D')
		return (0);
	else if (c == 'C')
		return (0);
	else if (c == '1')
		return (0);
	else if (c == '0')
		return (0);
	else
		return (1);
}

int	holy_find(t_data *data)
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
		// write(1, "cc2\n", 4);
		if (data->size_y != y - 1)
		{
			print_simple_line();
			printf("[SIZE LINE]\n\nin line[%d]\nlen    [%d]\nneeded [%d]\n", x,
				y - 1, data->size_y);
			map_erreur_size(data->map, data, x);
			print_simple_line();

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
				print_simple_line();
				return (0);
			}
			if (data->map[x][y] == 'T')
			{
				collectible++;
			}
			else if (data->map[x][y] == 'C')
				character++;
			else if (data->map[x][y] == 'E')
			{
				exit++;
				// printf("%d\n", data->switcher);
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
						return (0);
					}
				}
			}
			y++;
		}
		x++;
	}
	if (collectible > 0 && character == 1 && exit == 1)
		return (1);
	print_simple_line();
	write(1, "[BAD MAP]\n\n", 12);
	printf("collectibles : [%d]->[>0]\ncharacter    : [%d]->[ 1]\nexit\t     : [%d]->[ 1]\n\n",
		collectible, character, exit);
	print_simple_line();
	// printf("[ > 0 && C == 1 && E == 1]\n\n");
	return (0);
}

int	map_ok(t_data *data)
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
	// print_map2(dup);
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
