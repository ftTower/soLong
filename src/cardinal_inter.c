/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cardinal_inter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:17:17 by tauer             #+#    #+#             */
/*   Updated: 2024/02/20 13:01:30 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	f_nor_we(t_data *data)
{
	if (data->mov_chunk_x > 0)
		data->mov_chunk_x -= 5;
	if (data->mov_chunk_y > 0)
		data->mov_chunk_y -= 5;
	pixelator_perso(data, north);
	pixelator_perso(data, west);
}

void	f_nor_ea(t_data *data)
{
	if (data->mov_chunk_x > 0)
		data->mov_chunk_x -= 5;
	if (data->mov_chunk_y < 50)
		data->mov_chunk_y += 5;
	pixelator_perso(data, north);
	pixelator_perso(data, east);
}

void	f_sou_we(t_data *data)
{
	if (data->mov_chunk_x < 50)
		data->mov_chunk_x += 5;
	if (data->mov_chunk_y > 0)
		data->mov_chunk_y -= 5;
	pixelator_perso(data, south);
	pixelator_perso(data, west);
}

void	f_sou_ea(t_data *data)
{
	if (data->mov_chunk_x < 50)
		data->mov_chunk_x += 5;
	if (data->mov_chunk_y < 50)
		data->mov_chunk_y += 5;
	pixelator_perso(data, south);
	pixelator_perso(data, east);
}
