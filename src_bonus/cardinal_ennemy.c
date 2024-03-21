/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cardinal_ennemy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:22:18 by tauer             #+#    #+#             */
/*   Updated: 2024/03/21 14:50:55 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

bool	v_west(t_data *data)
{
	if (data->chunk_v_y > 0)
		data->chunk_v_y -= 5;
	if (pixelator_ennemy(data, west))
	{
		data->textures.current_ennemy = data->textures.ennemy_left;
		return (false);
	}
	return (true);
}

bool	v_east(t_data *data)
{
	if (data->chunk_v_y < 50)
		data->chunk_v_y += 5;
	if (pixelator_ennemy(data, east))
	{
		data->textures.current_ennemy = data->textures.ennemy_left;
		return (false);
	}
	return (true);
}

bool	v_south(t_data *data)
{
	if (data->chunk_v_x < 50)
		data->chunk_v_x += 5;
	if (pixelator_ennemy(data, south))
	{
		data->textures.current_ennemy = data->textures.ennemy_front;
		return (false);
	}
	return (true);
}

bool	v_north(t_data *data)
{
	if (data->chunk_v_x > 0)
		data->chunk_v_x -= 5;
	if (pixelator_ennemy(data, north))
	{
		data->textures.current_ennemy = data->textures.ennemy_back;
		return (false);
	}
	return (true);
}
