/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_gameplay.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:18:23 by tauer             #+#    #+#             */
/*   Updated: 2024/03/17 22:10:20 by tauer            ###   ########.fr       */
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

void	bullet_noso(t_data *data, int x_bul, int y_bul)
{
	if (data->mov_status == north)
	{
		while (check_empty(data, x_bul - 1, y_bul))
		{
			if (data->map[x_bul - 1][y_bul] == 'V')
				data->life_ennemy -= 50;
			x_bul--;
		}
	}
	else if (data->mov_status == south)
	{
		while (check_empty(data, x_bul + 1, y_bul))
		{
			if (data->map[x_bul + 1][y_bul] == 'V')
				data->life_ennemy -= 50;
			x_bul++;
		}
	}
}

void	bullet_eawe(t_data *data, int x_bul, int y_bul)
{
	if (data->mov_status == east)
	{
		while (check_empty(data, x_bul, y_bul + 1))
		{
			if (data->map[x_bul][y_bul + 1] == 'V')
				data->life_ennemy -= 50;
			y_bul++;
		}
	}
	else if (data->mov_status == west)
	{
		while (check_empty(data, x_bul, y_bul - 1))
		{
			if (data->map[x_bul][y_bul - 1] == 'V')
				data->life_ennemy -= 50;
			y_bul--;
		}
	}
}

void	shoot(t_data *data)
{
	int	x_bul;
	int	y_bul;

	x_bul = data->x;
	y_bul = data->y;
	bullet_noso(data, x_bul, y_bul);
	bullet_eawe(data, x_bul, y_bul);
}

void	player_death(t_data *data)
{
	if (data->wave == 1 && data->x == data->v_x && data->y == data->v_y
		&& data->life_ennemy > 0)
	{
		ft_printf("you died !\n");
		close_win(data);
	}
}
