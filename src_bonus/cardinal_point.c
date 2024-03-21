/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cardinal_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:15:26 by tauer             #+#    #+#             */
/*   Updated: 2024/03/21 14:51:05 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

void	f_north(t_data *data)
{
	if (data->mov_chunk_x > 0)
		data->mov_chunk_x -= 5;
	pixelator_perso(data, north);
	data->mov_status = 0;
	data->textures.current_perso = data->textures.back_perso;
}

void	f_south(t_data *data)
{
	if (data->mov_chunk_x < 50)
		data->mov_chunk_x += 5;
	pixelator_perso(data, south);
	data->mov_status = 1;
	data->textures.current_perso = data->textures.running_1;
}

void	f_east(t_data *data)
{
	if (data->mov_chunk_y < 50)
		data->mov_chunk_y += 5;
	pixelator_perso(data, east);
	data->mov_status = 2;
	data->textures.current_perso = data->textures.right_perso;
}

void	f_west(t_data *data)
{
	if (data->mov_chunk_y > 0)
		data->mov_chunk_y -= 5;
	pixelator_perso(data, west);
	data->mov_status = 3;
	data->textures.current_perso = data->textures.left_perso;
}
