/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_init_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 00:05:41 by tauer             #+#    #+#             */
/*   Updated: 2024/03/20 20:40:43 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

bool	init_floor(t_data *data)
{
	put_error_msg("| FLOORS_TEXTURES");
	add_img_to_garbage_memory(data, &data->textures.floor_x,
		"floor_x\t\t      :./img/floor_cosmetics/floor_x.xpm:0W");
	add_img_to_garbage_memory(data, &data->textures.floor_ventil,
		"floor_ventil\t      :./img/floor_cosmetics/floor_ventil.xpm:0Y");
	add_img_to_garbage_memory(data, &data->textures.empty,
		"empty\t\t      :./img/empty.xpm:0X");
	add_img_to_garbage_memory(data, &data->textures.floor,
		"floor\t\t      :./img/floor.xpm:0V");
	if (!data->textures.floor_x.img || !data->textures.floor_ventil.img
		|| !data->textures.empty.img || !data->textures.floor.img)
		return (false);
	return (true);
}

bool	init_rest(t_data *data)
{
	put_error_msg("| REST_TEXTURES");
	add_img_to_garbage_memory(data, &data->textures.collectibles,
		"collectibles\t      :./img/collectibles.xpm:0C");
	if (!data->textures.collectibles.img)
		return (false);
	return (true);
}
