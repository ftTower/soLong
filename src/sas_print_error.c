/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sas_print_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:47:21 by tauer             #+#    #+#             */
/*   Updated: 2024/03/18 12:52:00 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	map_erreur(char **map, t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if ((map[x][y] >= 'a' && map[x][y] <= 'z') || map[x][y] == '1')
				ft_printf("\033[48;5;240m  \033[0m");
			else if (map[x][y] == 'D')
				ft_printf("\033[48;5;248m  \033[0m");
			else if (map[x][y] == 'C')
				ft_printf("\033[48;5;40m  \033[0m");
			else if (map[x][y] == 'E' && data->collectibles_left == 0)
				ft_printf("\033[48;5;76m  \033[0m");
			else if (map[x][y] == 'E')
				ft_printf("\033[48;5;76m  \033[0m");
			else if (map[x][y] == 'X')
				ft_printf("\033[48;5;160m  \033[0m");
			else
				ft_printf("\033[48;5;195m  \033[0m");
			y++;
		}
		ft_printf("\n");
		x++;
	}
	print_simple_line();
}

void	map_erreur_size(char **map, t_data *data, int x_error)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	print_simple_line();
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (x == x_error - 1)
			{
				ft_printf("\033[48;5;160m  \033[0m");
			}
			else if ((map[x][y] >= 'a' && map[x][y] <= 'z') || map[x][y] == '1')
				ft_printf("\033[48;5;240m  \033[0m");
			else if (map[x][y] == 'D')
				ft_printf("\033[48;5;248m  \033[0m");
			else if (map[x][y] == 'C')
				ft_printf("\033[48;5;40m  \033[0m");
			else if (map[x][y] == 'E' && data->collectibles_left == 0)
				ft_printf("\033[48;5;76m  \033[0m");
			else if (map[x][y] == 'E')
				ft_printf("\033[48;5;76m  \033[0m");
			else if (map[x][y] == 'X')
				ft_printf("\033[48;5;160m  \033[0m");
			else
				ft_printf("\033[48;5;195m  \033[0m");
			y++;
		}
		printf("\n");
		x++;
	}
	print_simple_line();
}

void	map_erreur_char(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	print_simple_line();
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if ((map[x][y] >= 'a' && map[x][y] <= 'z') || map[x][y] == '1')
				ft_printf("\033[48;5;240m  \033[0m");
			else if (map[x][y] == 'D')
				ft_printf("\033[48;5;248m  \033[0m");
			else if (map[x][y] == 'C')
				ft_printf("\033[48;5;40m  \033[0m");
			else if (map[x][y] == 'E')
				ft_printf("\033[48;5;76m  \033[0m");
			else if (map[x][y] == 'P')
				ft_printf("\033[48;5;245m  \033[0m");
			else if (map[x][y] == '0')
				ft_printf("\033[48;5;195m  \033[0m");
			else
				ft_printf("\033[48;5;160m  \033[0m");
			y++;
		}
		printf("\n");
		x++;
	}
	print_simple_line();
}
