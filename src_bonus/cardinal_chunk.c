/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cardinal_chunk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:50:39 by tauer             #+#    #+#             */
/*   Updated: 2024/03/21 14:50:47 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

bool	chunk_ennemy_noso(t_data *data, t_dir dir)
{
	if (dir == north)
	{
		data->chunk_v_x = 50;
		data->v_x -= 1;
		return (true);
	}
	else if (dir == south)
	{
		data->chunk_v_x = 0;
		data->v_x += 1;
		return (true);
	}
	return (false);
}

bool	chunk_ennemy_eawe(t_data *data, t_dir dir)
{
	if (dir == east)
	{
		data->chunk_v_y = 0;
		data->v_y += 1;
		return (true);
	}
	else if (dir == west)
	{
		data->chunk_v_y = 50;
		data->v_y -= 1;
		return (true);
	}
	return (false);
}

void	update_chunk(t_data *data, t_dir dir)
{
	if (dir == north)
	{
		data->mov_chunk_x = 50;
		data->x -= 1;
	}
	else if (dir == south)
	{
		data->mov_chunk_x = 0;
		data->x += 1;
	}
	else if (dir == east)
	{
		data->mov_chunk_y = 0;
		data->y += 1;
	}
	else if (dir == west)
	{
		data->mov_chunk_y = 50;
		data->y -= 1;
	}
	data->move += 1;
}

bool	update_chunk_ennemy(t_data *data, t_dir dir)
{
	if (dir != no_dir)
	{
		if (!chunk_ennemy_noso(data, dir) && !chunk_ennemy_eawe(data, dir))
			return (false);
		if (data->map[data->v_x][data->v_y] == 'P')
			close_win(data);
	}
	return (true);
}
