/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_init_walls.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:39:45 by tauer             #+#    #+#             */
/*   Updated: 2024/03/21 14:54:32 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

void	initadd_walls(t_data *data)
{
	add_img_to_garbage_memory(data, &data->textures.wall,
		"simple_wall            :./img/wall.xpm:01");
	add_img_to_garbage_memory(data, &data->textures.wall_up,
		"wall_up                :./img/wall_up.xpm:0f");
	add_img_to_garbage_memory(data, &data->textures.wall_4,
		"wall_4                 :./img/wall_4.xpm:0e");
	add_img_to_garbage_memory(data, &data->textures.wall_down,
		"wall_down              :./img/wall_down.xpm:Vd");
	add_img_to_garbage_memory(data, &data->textures.wall_down_empty,
		"wall_down_empty        :./img/wall_down_empty.xpm:^c");
}

void	initadd_connections(t_data *data)
{
	add_img_to_garbage_memory(data, &data->textures.toward_wall_left_empty,
		"toward_wall_left_empty :./img/toward_wall_left_empty.xpm:Xn");
	add_img_to_garbage_memory(data, &data->textures.toward_wall_right_empty,
		"toward_wall_right_empty:./img/toward_wall_right_empty.xpm:Xn");
	add_img_to_garbage_memory(data, &data->textures.toward_wall,
		"toward_wall            :./img/toward_wall.xpm:Vn");
	add_img_to_garbage_memory(data, &data->textures.down,
		"down                   :./img/down.xpm:0b");
	add_img_to_garbage_memory(data, &data->textures.right_corner,
		"right_corner           :./img/right_corner.xpm:>m");
	add_img_to_garbage_memory(data, &data->textures.left_corner,
		"left_corner            :./img/left_corner.xpm:<l");
	add_img_to_garbage_memory(data, &data->textures.left_top_corner,
		"left_top_corner        :./img/left_top_corner.xpm:<j");
	add_img_to_garbage_memory(data, &data->textures.right_top_corner,
		"right_top_corner       :./img/right_top_corner.xpm:>o");
	add_img_to_garbage_memory(data, &data->textures.right_top_corner_up,
		"right_top_corner_up    :./img/right_top_corner_up.xpm:>q");
	add_img_to_garbage_memory(data, &data->textures.left_top_corner_up,
		"left_top_corner_up     :./img/left_top_corner_up.xpm:<p");
	add_img_to_garbage_memory(data, &data->textures.right_empty,
		"right_empty            :./img/right_empty.xpm:Xh");
	add_img_to_garbage_memory(data, &data->textures.left_empty,
		"left_empty             :./img/left_empty.xpm:Xg");
}

bool	init_walls(t_data *data)
{
	put_error_msg("| WALLS_TEXTURES");
	initadd_connections(data);
	initadd_walls(data);
	if (!data->textures.toward_wall_left_empty.img
		|| !data->textures.toward_wall_right_empty.img
		|| !data->textures.right_corner.img || !data->textures.left_corner.img
		|| !data->textures.left_top_corner.img
		|| !data->textures.right_top_corner.img
		|| !data->textures.right_top_corner_up.img
		|| !data->textures.left_top_corner_up.img
		|| !data->textures.right_empty.img || !data->textures.left_empty.img
		|| !data->textures.wall.img || !data->textures.wall_up.img
		|| !data->textures.wall_4.img || !data->textures.wall_down.img
		|| !data->textures.wall_down_empty.img || !data->textures.down.img
		|| !data->textures.toward_wall.img)
		return (false);
	return (true);
}

bool	init_wall_cosmetics(t_data *data)
{
	put_error_msg("| WALLS_COSMETICS_TEXTURES");
	add_img_to_garbage_memory(data, &data->textures.private_door,
		"private_door\t      :./img/cosmetic_4_wall/private_door.xpm:0s");
	add_img_to_garbage_memory(data, &data->textures.panel_wall,
		"panel_wall\t      :./img/cosmetic_4_wall/pannel_wall.xpm:0x");
	add_img_to_garbage_memory(data, &data->textures.wall_screen,
		"wall_screen\t      :./img/cosmetic_4_wall/wall_screen.xpm:0r");
	if (!data->textures.private_door.img || !data->textures.panel_wall.img
		|| !data->textures.wall_screen.img)
		return (false);
	return (true);
}
