/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:18:23 by tauer             #+#    #+#             */
/*   Updated: 2024/02/18 22:05:37 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	end_wave(t_data *data)
{
	if ((data->x == data->e_x) && (data->y == data->e_y)
		&& data->collectibles_left == 0)
		reset_wave(data);
}

void	reset_wave(t_data *data)
{
	data->map[data->e_x][data->e_y] = 'E';
	data->textures.current_exit = data->textures.exit_1;

	data->wave++;

	data->x = data->start_x;
	data->y = data->start_y;

	data->mov_chunk_x = 20;
	data->mov_chunk_y = 20;
	if (data->wave > 1)
		data->map[data->v_x][data->v_y] = '0';
	
	data->life_ennemy = 100;
	place_ennemy(data);
	reset_collectibles(data);
}




void	shoot(t_data *data)
{
	int	x_bul;
	int	y_bul;

	x_bul = data->x;
	y_bul = data->y;
	if (data->mov_status == 0)
	{
		while (check_empty(data, x_bul - 1, y_bul))
		{
			if (data->map[x_bul - 1][y_bul] == 'V')
				data->life_ennemy -= 50;
			x_bul--;
		}
	}
	else if (data->mov_status == 1)
	{
		while (check_empty(data, x_bul + 1, y_bul))
		{
			if (data->map[x_bul + 1][y_bul] == 'V')
				data->life_ennemy -= 50;
			x_bul++;
		}
	}
	else if (data->mov_status == 2)
	{
		while (check_empty(data, x_bul, y_bul + 1))
		{
			if (data->map[x_bul][y_bul + 1] == 'V')
				data->life_ennemy -= 50;
			y_bul++;
		}
	}
	else if (data->mov_status == 3)
	{
		while (check_empty(data, x_bul, y_bul - 1))
		{
			if (data->map[x_bul][y_bul - 1] == 'V')
				data->life_ennemy -= 50;
			y_bul--;
		}
	}
}