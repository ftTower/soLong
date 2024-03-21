/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cardinal_ennemy_inter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:29:45 by tauer             #+#    #+#             */
/*   Updated: 2024/03/21 14:50:51 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

bool	v_nor_we(t_data *data)
{
	int	check;

	check = 0;
	if (data->chunk_v_x > 0)
		data->chunk_v_x -= 5;
	if (data->chunk_v_y > 0)
		data->chunk_v_y -= 5;
	if (pixelator_ennemy(data, north))
	{
		check++;
		data->textures.current_ennemy = data->textures.ennemy_back;
	}
	if (pixelator_ennemy(data, west))
	{
		check++;
		data->textures.current_ennemy = data->textures.ennemy_left;
	}
	if (check > 0)
		return (false);
	return (true);
}

bool	v_nor_ea(t_data *data)
{
	int	check;

	check = 0;
	if (data->chunk_v_x > 0)
		data->chunk_v_x -= 5;
	if (data->chunk_v_y < 50)
		data->chunk_v_y += 5;
	if (pixelator_ennemy(data, north))
	{
		check++;
		data->textures.current_ennemy = data->textures.ennemy_back;
	}
	if (pixelator_ennemy(data, east))
	{
		check++;
		data->textures.current_ennemy = data->textures.ennemy_right;
	}
	if (check > 0)
		return (false);
	return (true);
}

bool	v_south_we(t_data *data)
{
	int	check;

	check = 0;
	if (data->chunk_v_x < 50)
		data->chunk_v_x += 5;
	if (data->chunk_v_y > 0)
		data->chunk_v_y -= 5;
	if (pixelator_ennemy(data, south))
	{
		check++;
		data->textures.current_ennemy = data->textures.ennemy_front;
	}
	if (pixelator_ennemy(data, west))
	{
		check++;
		data->textures.current_ennemy = data->textures.ennemy_left;
		return (false);
	}
	if (check > 0)
		return (false);
	return (true);
}

bool	v_south_ea(t_data *data)
{
	int	check;

	check = 0;
	if (data->chunk_v_x < 50)
		data->chunk_v_x += 5;
	if (data->chunk_v_y < 50)
		data->chunk_v_y += 5;
	if (pixelator_ennemy(data, south))
	{
		check++;
		data->textures.current_ennemy = data->textures.ennemy_front;
	}
	if (pixelator_ennemy(data, east))
	{
		check++;
		data->textures.current_ennemy = data->textures.ennemy_right;
	}
	if (check > 0)
		return (false);
	return (true);
}
