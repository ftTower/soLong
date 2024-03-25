/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sas_security.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/03/19 14:59:42 by tauer             #+#    #+#             */
/*   Updated: 2024/03/19 14:59:42 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	bad_char(char c)
{
	if (c == 'C' || c == 'E' || c == 'D' || c == 'P' || c == '1' || c == '0')
		return (0);
	return (1);
}

bool	place_exit_is_correct(t_data *data, int x, int y)
{
	if (check_walls(data, x - 1, y))
	{
		data->map[x][y] = '0';
		data->map[x - 1][y] = 'E';
	}
	else
	{
		put_error_msg("[❌ door not connected]");
		map_erreur(data->map);
		return (true);
	}
	return (false);
}

void	look_number_input(t_data *data, int *collectible, int *character)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] == 'C')
				(*collectible)++;
			else if (data->map[x][y] == 'P')
				(*character)++;
			y++;
		}
		x++;
	}
}

bool	holy_find(t_data *data)
{
	int	collectible;
	int	character;
	int	exit;

	collectible = 0;
	character = 0;
	exit = 0;
	data->switcher = 0;
	if (find_bad_map_size(data) || find_exit(data, &exit)
		|| find_bad_char(data))
		return (false);
	look_number_input(data, &collectible, &character);
	if (collectible > 0 && character == 1 && exit == 1)
		return (true);
	put_error_msg("[❌ bad inputs]");
	ft_printf("collectibles : [%d]->[>0]\ncharacter    :", collectible);
	ft_printf(" [%d]->[ 1]\nexit\t     : [%d]->[ 1]\n", character, exit);
	print_simple_line();
	map_erreur(data->map);
	return (false);
}

int	map_ok(t_data *data)
{
	char	**dup;

	if (!holy_find(data))
		return (0);
	dup = get_map(data->map_path);
	if (!dup)
		return (0);
	if (!resolved_path(data, dup, data->x, data->y))
		return (0);
	if (check_acess_to_input(dup) && correct_borders(dup))
	{
		delete_emptyness(data, dup);
		free_map(dup);
		return (1);
	}
	else
		map_erreur(dup);
	free_map(dup);
	return (0);
}
