/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_various.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:34:58 by tauer             #+#    #+#             */
/*   Updated: 2024/03/07 18:45:27 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void    init_exit(t_data *data)
{
    data->textures.exit_1 = new_file_img("./img/exit/exit_1.xpm", data);
	data->textures.exit_2 = new_file_img("./img/exit/exit_open_2.xpm", data);
	data->textures.exit_3 = new_file_img("./img/exit/exit_open_3.xpm", data);
	data->textures.exit_4 = new_file_img("./img/exit/exit_open_4.xpm", data);
	data->textures.exit_5 = new_file_img("./img/exit/exit_open_5.xpm", data);
	data->textures.exit_6 = new_file_img("./img/exit/exit_open_6.xpm", data);
	data->textures.exit_7 = new_file_img("./img/exit/exit_open_7.xpm", data);
	data->textures.exit_8 = new_file_img("./img/exit/exit_open_8.xpm", data);
	data->textures.exit_9 = new_file_img("./img/exit/exit_open_9.xpm", data);
	data->textures.exit_10 = new_file_img("./img/exit/exit_open_10.xpm", data);
	data->textures.exit_11 = new_file_img("./img/exit/exit_open_11.xpm", data);
	data->textures.exit_12 = new_file_img("./img/exit/exit_open_12.xpm", data);
	data->textures.exit_13 = new_file_img("./img/exit/exit_open_13.xpm", data);
	data->textures.exit_14 = new_file_img("./img/exit/exit_open_14.xpm", data);
	data->textures.exit_15 = new_file_img("./img/exit/exit_open_15.xpm", data);
	data->textures.exit_16 = new_file_img("./img/exit/exit_open_16.xpm", data);
	data->textures.exit_17 = new_file_img("./img/exit/exit_open_17.xpm", data);
	data->textures.exit_18 = new_file_img("./img/exit/exit_open_18.xpm", data);
	data->textures.exit_19 = new_file_img("./img/exit/exit_open_19.xpm", data);
}

void    init_screen_indoor(t_data *data)
{
    data->textures.wall_screen_indoor = new_file_img("./img/wall_screen_animation/wall_screen_indoor.xpm",
			data);
	data->textures.wall_screen_indoor_1 = new_file_img("./img/wall_screen_animation/wall_screen_indoor_1.xpm",
			data);
	data->textures.wall_screen_indoor_2 = new_file_img("./img/wall_screen_animation/wall_screen_indoor_2.xpm",
			data);
	data->textures.wall_screen_indoor_3 = new_file_img("./img/wall_screen_animation/wall_screen_indoor_3.xpm",
			data);
	data->textures.wall_screen_indoor_4 = new_file_img("./img/wall_screen_animation/wall_screen_indoor_4.xpm",
			data);
	data->textures.wall_screen_indoor_5 = new_file_img("./img/wall_screen_animation/wall_screen_indoor_5.xpm",
			data);
	data->textures.wall_screen_indoor_6 = new_file_img("./img/wall_screen_animation/wall_screen_indoor_6.xpm",
			data);
	data->textures.wall_screen_indoor_7 = new_file_img("./img/wall_screen_animation/wall_screen_indoor_7.xpm",
			data);
	data->textures.wall_screen_indoor_8 = new_file_img("./img/wall_screen_animation/wall_screen_indoor_8.xpm",
			data);
}

void	init_screen_outdoor(t_data *data)
{
	data->textures.wall_screen_outdoor = new_file_img("./img/screen_outdoor_animation/wall_screen_outdoor.xpm",
			data);
	data->textures.wall_screen_outdoor_1 = new_file_img("./img/screen_outdoor_animation/wall_screen_outdoor_1.xpm",
			data);
	data->textures.wall_screen_outdoor_2 = new_file_img("./img/screen_outdoor_animation/wall_screen_outdoor_2.xpm",
			data);
	data->textures.wall_screen_outdoor_3 = new_file_img("./img/screen_outdoor_animation/wall_screen_outdoor_3.xpm",
			data);
	data->textures.wall_screen_outdoor_4 = new_file_img("./img/screen_outdoor_animation/wall_screen_outdoor_2.xpm",
			data);
	data->textures.wall_screen_outdoor_5 = new_file_img("./img/screen_outdoor_animation/wall_screen_outdoor_1.xpm",
			data);
}

void	init_capsule(t_data *data)
{
	data->textures.capsule = new_file_img("./img/capsule_animation/capsule.xpm",
			data);
	data->textures.capsule_1 = new_file_img("./img/capsule_animation/capsule_1.xpm",
			data);
	data->textures.capsule_2 = new_file_img("./img/capsule_animation/capsule_2.xpm",
			data);
	data->textures.capsule_3 = new_file_img("./img/capsule_animation/capsule_3.xpm",
			data);
	data->textures.capsule_4 = new_file_img("./img/capsule_animation/capsule_2.xpm",
			data);
	data->textures.capsule_5 = new_file_img("./img/capsule_animation/capsule_1.xpm",
			data);
}