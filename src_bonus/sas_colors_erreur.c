/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sas_colors_erreur.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:46:39 by tauer             #+#    #+#             */
/*   Updated: 2024/03/21 14:53:22 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

void	colors_erreur_char(char **map, int x, int y)
{
	if ((map[x][y] >= 'a' && map[x][y] <= 'z') || map[x][y] == '1')
		ft_printf("\033[48;5;240m  \033[0m");
	else if (map[x][y] == 'D')
		ft_printf("\033[48;5;248m  \033[0m");
	else if (map[x][y] == 'C')
		ft_printf("\033[48;5;22m  \033[0m");
	else if (map[x][y] == 'E')
		ft_printf("\033[48;5;76m  \033[0m");
	else if (map[x][y] == 'P')
		ft_printf("\033[48;5;40m  \033[0m");
	else if (map[x][y] == '0')
		ft_printf("\033[48;5;195m  \033[0m");
	else
		ft_printf("\033[48;5;160m  \033[0m");
}

void	colors_erreur_size(char **map, int x_error, int x, int y)
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
	else if (map[x][y] == 'E')
		ft_printf("\033[48;5;76m  \033[0m");
	else if (map[x][y] == 'X')
		ft_printf("\033[48;5;160m  \033[0m");
	else
		ft_printf("\033[48;5;195m  \033[0m");
}

void	colors_erreur_common(char **map, int x, int y)
{
	if ((map[x][y] >= 'a' && map[x][y] <= 'z') || map[x][y] == '1')
		ft_printf("\033[48;5;240m  \033[0m");
	else if (map[x][y] == 'D')
		ft_printf("\033[48;5;248m  \033[0m");
	else if (map[x][y] == 'P')
		ft_printf("\033[48;5;208m  \033[0m");
	else if (map[x][y] == 'C')
		ft_printf("\033[48;5;40m  \033[0m");
	else if (map[x][y] == 'E')
		ft_printf("\033[48;5;160m  \033[0m");
	else if (map[x][y] == 'X')
		ft_printf("\033[48;5;160m  \033[0m");
	else
		ft_printf("\033[48;5;195m  \033[0m");
}

void	colors_terminal(t_data *data, int x, int y)
{
	if ((data->map[x][y] >= 'a' && data->map[x][y] <= 'z')
		|| data->map[x][y] == '1')
		ft_printf("\033[48;5;240m  \033[0m");
	else if (data->map[x][y] == 'V')
		ft_printf("\033[48;5;124m  \033[0m");
	else if (data->map[x][y] == 'D')
		ft_printf("\033[48;5;248m  \033[0m");
	else if (data->map[x][y] == 'P')
		ft_printf("\033[48;5;208m  \033[0m");
	else if (data->map[x][y] == 'C')
		ft_printf("\033[48;5;40m  \033[0m");
	else if (data->map[x][y] == 'E' && data->collectibles_left == 0)
		ft_printf("\033[48;5;76m  \033[0m");
	else if (data->map[x][y] == 'E')
		ft_printf("\033[48;5;160m  \033[0m");
	else if (data->map[x][y] == 'X')
		ft_printf("\033[48;5;16m  \033[0m");
	else
		ft_printf("\033[48;5;195m  \033[0m");
}
