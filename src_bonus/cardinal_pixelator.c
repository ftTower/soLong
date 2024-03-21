/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cardinal_pixelator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:55:00 by tauer             #+#    #+#             */
/*   Updated: 2024/03/21 14:51:01 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

bool	pixel_noso(t_data *data, t_dir dir)
{
	if (dir == north && data->chunk_v_x == 0 && check_empty(data, data->v_x - 1,
			data->v_y))
	{
		data->map[data->v_x][data->v_y] = '0';
		update_chunk_ennemy(data, north);
		data->map[data->v_x][data->v_y] = 'V';
		return (false);
	}
	else if (dir == south && data->chunk_v_x == 50 && check_empty(data,
			data->v_x + 1, data->v_y))
	{
		data->map[data->v_x][data->v_y] = '0';
		update_chunk_ennemy(data, south);
		data->map[data->v_x][data->v_y] = 'V';
		return (false);
	}
	return (true);
}

bool	pixel_eawe(t_data *data, t_dir dir)
{
	if (dir == east && data->chunk_v_y == 50 && check_empty(data, data->v_x,
			data->v_y + 1))
	{
		data->map[data->v_x][data->v_y] = '0';
		update_chunk_ennemy(data, east);
		data->map[data->v_x][data->v_y] = 'V';
		return (false);
	}
	else if (dir == west && data->chunk_v_y == 0 && check_empty(data, data->v_x,
			data->v_y - 1))
	{
		data->map[data->v_x][data->v_y] = '0';
		update_chunk_ennemy(data, west);
		data->map[data->v_x][data->v_y] = 'V';
		return (false);
	}
	return (true);
}

bool	pixelator_ennemy(t_data *data, t_dir dir)
{
	if (!pixel_noso(data, dir) || !pixel_eawe(data, dir))
		return (false);
	return (true);
}

void	pixelator_perso(t_data *data, t_dir dir)
{
	data->map[data->x][data->y] = '0';
	if (dir == north && data->mov_chunk_x == 0 && check_next(data, data->x - 1,
			data->y))
		update_chunk(data, north);
	else if (dir == south && data->mov_chunk_x == 50 && check_next(data, data->x
			+ 1, data->y))
		update_chunk(data, south);
	else if (dir == east && data->mov_chunk_y == 50 && check_next(data, data->x,
			data->y + 1))
		update_chunk(data, east);
	else if (dir == west && data->mov_chunk_y == 0 && check_next(data, data->x,
			data->y - 1))
		update_chunk(data, west);
	data->map[data->x][data->y] = 'P';
}
