/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:47:21 by tauer             #+#    #+#             */
/*   Updated: 2024/01/27 04:54:34 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	map_erreur(char **map, t_data *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (map[x])
	{
		y = 0;
		// printf("\033[0;47m  \033[0m");
		while (map[x][y])
		{
			if ((map[x][y] >= 'a' && map[x][y] <= 'z') || map[x][y] == '1')
				printf("\033[48;5;240m  \033[0m");
			else if (map[x][y] == 'D')
				printf("\033[48;5;248m  \033[0m");
			else if (map[x][y] == 'T')
				printf("\033[48;5;40m  \033[0m");
			else if (map[x][y] == 'E' && data->collectibles_left == 0)
				printf("\033[48;5;76m  \033[0m");
			else if (map[x][y] == 'E')
				printf("\033[48;5;76m  \033[0m");
			else if (map[x][y] == 'X')
				printf("\033[48;5;160m  \033[0m");
			else
				printf("\033[48;5;195m  \033[0m");
			y++;
		}
		// printf("\033[0;47m  \033[0m");
		printf("\n");
		x++;
	}
}

void	map_erreur_size(char **map, t_data *data, int x_error)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (map[x])
	{
		y = 0;
		// printf("\033[0;47m  \033[0m");
		while (map[x][y])
		{
			if (x == x_error - 1)
			{
				printf("\033[48;5;160m  \033[0m");
			}
			else if ((map[x][y] >= 'a' && map[x][y] <= 'z') || map[x][y] == '1')
				printf("\033[48;5;240m  \033[0m");
			else if (map[x][y] == 'D')
				printf("\033[48;5;248m  \033[0m");
			else if (map[x][y] == 'T')
				printf("\033[48;5;40m  \033[0m");
			else if (map[x][y] == 'E' && data->collectibles_left == 0)
				printf("\033[48;5;76m  \033[0m");
			else if (map[x][y] == 'E')
				printf("\033[48;5;76m  \033[0m");
			else if (map[x][y] == 'X')
				printf("\033[48;5;160m  \033[0m");
			else
				printf("\033[48;5;195m  \033[0m");
			y++;
		}
		// printf("\033[0;47m  \033[0m");
		printf("\n");
		x++;
	}
}

void	map_erreur_char(char **map, t_data *data, int x_error, int y_error)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (map[x])
	{
		y = 0;
		// printf("\033[0;47m  \033[0m");
		while (map[x][y])
		{
			if (x == x_error - 1 && y == y_error - 1)
			{
				printf("\033[48;5;160m  \033[0m");
			}
			else if ((map[x][y] >= 'a' && map[x][y] <= 'z') || map[x][y] == '1')
				printf("\033[48;5;240m  \033[0m");
			else if (map[x][y] == 'D')
				printf("\033[48;5;248m  \033[0m");
			else if (map[x][y] == 'T')
				printf("\033[48;5;40m  \033[0m");
			else if (map[x][y] == 'E' && data->collectibles_left == 0)
				printf("\033[48;5;76m  \033[0m");
			else if (map[x][y] == 'E')
				printf("\033[48;5;76m  \033[0m");
			else if (map[x][y] == 'X')
				printf("\033[48;5;160m  \033[0m");
			else
				printf("\033[48;5;195m  \033[0m");
			y++;
		}
		// printf("\033[0;47m  \033[0m");
		printf("\n");
		x++;
	}
}
