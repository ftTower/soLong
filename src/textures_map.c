/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:47:43 by tauer             #+#    #+#             */
/*   Updated: 2024/03/07 18:53:40 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void init_walls(t_data *data)
{
    data->textures.right_top_corner_up = new_file_img("./img/right_top_corner_up.xpm",
                                                      data);
    data->textures.left_top_corner_up = new_file_img("./img/left_top_corner_up.xpm",
                                                     data);
    data->textures.left_top_corner = new_file_img("./img/left_top_corner.xpm",
                                                  data);
    data->textures.right_top_corner = new_file_img("./img/right_top_corner.xpm",
                                                   data);
    data->textures.right_corner = new_file_img("./img/right_corner.xpm", data);
    data->textures.left_corner = new_file_img("./img/left_corner.xpm", data);
    data->textures.right_empty = new_file_img("./img/right_empty.xpm", data);
    data->textures.left_empty = new_file_img("./img/left_empty.xpm", data);
    data->textures.wall = new_file_img("./img/wall.xpm", data);
    data->textures.wall_up = new_file_img("./img/wall_up.xpm", data);
    data->textures.wall_4 = new_file_img("./img/wall_4.xpm", data);
    data->textures.wall_down = new_file_img("./img/wall_down.xpm", data);
    data->textures.wall_down_empty = new_file_img("./img/wall_down_empty.xpm",
                                                  data);
    data->textures.down = new_file_img("./img/down.xpm", data);
    data->textures.toward_wall = new_file_img("./img/toward_wall.xpm", data);
    data->textures.toward_wall_left_empty = new_file_img("./img/toward_wall_left_empty.xpm",
                                                         data);
    data->textures.toward_wall_right_empty = new_file_img("./img/toward_wall_right_empty.xpm",
                                                          data);
}

void init_wall_cosmetics(t_data *data)
{
    data->textures.private_door = new_file_img("./img/cosmetic_4_wall/private_door.xpm",
			data);
	data->textures.panel_wall = new_file_img("./img/cosmetic_4_wall/pannel_wall.xpm",
			data);
	data->textures.wall_screen = new_file_img("./img/cosmetic_4_wall/wall_screen.xpm",
			data);
}

void init_floor(t_data *data)
{
    data->textures.floor_x = new_file_img("./img/floor_cosmetics/floor_x.xpm",
			data);
	data->textures.floor_ventil = new_file_img("./img/floor_cosmetics/floor_ventil.xpm",
			data);
	data->textures.empty = new_file_img("./img/empty.xpm", data);
	data->textures.floor = new_file_img("./img/floor.xpm", data);
}