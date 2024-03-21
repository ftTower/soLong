/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_init_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 00:05:41 by tauer             #+#    #+#             */
/*   Updated: 2024/03/21 19:48:24 by tauer            ###   ########.fr       */
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
	add_img_to_garbage_memory(data, &data->textures.wall_screen_outdoor,
		"screen_outdoor\t      :./img/screen_outdoor_animation/wall_screen_outdoor_3.xpm:0y");
	add_img_to_garbage_memory(data, &data->textures.wall_screen_indoor,
		"screen_indoor\t      :./img/wall_screen_animation/wall_screen_indoor_1.xpm:0t");
	if (!data->textures.collectibles.img
		|| !data->textures.wall_screen_indoor.img
		|| !data->textures.wall_screen_outdoor.img)
		return (false);
	return (true);
}

bool	init_exit(t_data *data)
{
	put_error_msg("| EXIT_TEXTURES");
	add_img_to_garbage_memory(data, &data->textures.exit_1,
		"exit_1\t      :./img/exit/exit_1.xpm:0E");
	add_img_to_garbage_memory(data, &data->textures.exit_19,
		"exit_19\t      :./img/exit/exit_open_19.xpm:0E");
	if (!data->textures.exit_19.img || !data->textures.exit_1.img)
		return (false);
	return (true);
}
