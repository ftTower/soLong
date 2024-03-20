/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_init_anim_screen.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:28:00 by tauer             #+#    #+#             */
/*   Updated: 2024/03/20 20:28:34 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	initadd_screen_indoor(t_data *data)
{
	add_img_to_garbage_memory(data, &data->textures.wall_screen_indoor,
		"screen_indoor_0   :./img/wall_screen_animation/\
wall_screen_indoor.xpm:0y");
	add_img_to_garbage_memory(data, &data->textures.wall_screen_indoor_1,
		"screen_indoor_1   :./img/wall_screen_animation/\
wall_screen_indoor_1.xpm:0y");
	add_img_to_garbage_memory(data, &data->textures.wall_screen_indoor_2,
		"screen_indoor_2   :./img/wall_screen_animation/\
wall_screen_indoor_2.xpm:0y");
	add_img_to_garbage_memory(data, &data->textures.wall_screen_indoor_3,
		"screen_indoor_3   :./img/wall_screen_animation/\
wall_screen_indoor_3.xpm:0y");
	add_img_to_garbage_memory(data, &data->textures.wall_screen_indoor_4,
		"screen_indoor_4   :./img/wall_screen_animation/\
wall_screen_indoor_4.xpm:0y");
	add_img_to_garbage_memory(data, &data->textures.wall_screen_indoor_5,
		"screen_indoor_5   :./img/wall_screen_animation/\
wall_screen_indoor_5.xpm:0y");
	add_img_to_garbage_memory(data, &data->textures.wall_screen_indoor_6,
		"screen_indoor_6   :./img/wall_screen_animation/\
wall_screen_indoor_6.xpm:0y");
	add_img_to_garbage_memory(data, &data->textures.wall_screen_indoor_7,
		"creen_indoor_7   :./img/wall_screen_animation/\
wall_screen_indoor_7.xpm:0y");
}

bool	init_screen_indoor(t_data *data)
{
	put_error_msg("| SCREEN_INDOOR_TEXTURES");
	initadd_screen_indoor(data);
	add_img_to_garbage_memory(data, &data->textures.wall_screen_indoor_8,
		"screen_indoor_8   :./img/wall_screen_animation/\
wall_screen_indoor_8.xpm:0y");
	if (!data->textures.wall_screen_indoor.img
		|| !data->textures.wall_screen_indoor_1.img
		|| !data->textures.wall_screen_indoor_2.img
		|| !data->textures.wall_screen_indoor_3.img
		|| !data->textures.wall_screen_indoor_4.img
		|| !data->textures.wall_screen_indoor_5.img
		|| !data->textures.wall_screen_indoor_6.img
		|| !data->textures.wall_screen_indoor_7.img
		|| !data->textures.wall_screen_indoor_8.img)
		return (false);
	return (true);
}

void	initadd_screen_outdoor(t_data *data)
{
	add_img_to_garbage_memory(data, &data->textures.wall_screen_outdoor,
		"screen_outdoor_0  :./img/screen_outdoor_animation/\
wall_screen_outdoor.xpm:0t");
	add_img_to_garbage_memory(data, &data->textures.wall_screen_outdoor_1,
		"screen_outdoor_1  :./img/screen_outdoor_animation/\
wall_screen_outdoor_1.xpm:0t");
	add_img_to_garbage_memory(data, &data->textures.wall_screen_outdoor_2,
		"screen_outdoor_2  :./img/screen_outdoor_animation/\
wall_screen_outdoor_2.xpm:0t");
	add_img_to_garbage_memory(data, &data->textures.wall_screen_outdoor_3,
		"screen_outdoor_3  :./img/screen_outdoor_animation/\
wall_screen_outdoor_3.xpm:0t");
	add_img_to_garbage_memory(data, &data->textures.wall_screen_outdoor_4,
		"screen_outdoor_4  :./img/screen_outdoor_animation/\
wall_screen_outdoor_2.xpm:0t");
	add_img_to_garbage_memory(data, &data->textures.wall_screen_outdoor_5,
		"screen_outdoor_5  :./img/screen_outdoor_animation/\
wall_screen_outdoor_1.xpm:0t");
}

bool	init_screen_outdoor(t_data *data)
{
	put_error_msg("| SCREEN_OUTDOOR_TEXTURES");
	initadd_screen_outdoor(data);
	if (!data->textures.wall_screen_outdoor.img
		|| !data->textures.wall_screen_outdoor_1.img
		|| !data->textures.wall_screen_outdoor_2.img
		|| !data->textures.wall_screen_outdoor_3.img
		|| !data->textures.wall_screen_outdoor_4.img
		|| !data->textures.wall_screen_outdoor_5.img)
		return (false);
	return (true);
}
