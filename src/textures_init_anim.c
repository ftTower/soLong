/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_init_anim.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:34:58 by tauer             #+#    #+#             */
/*   Updated: 2024/03/15 23:41:28 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

bool	init_exit(t_data *data)
{
	printf("=========================================================================================\n| EXIT_TEXTURES\n=========================================================================================\n");
	add_img_to_garbage_memory(data, &data->textures.exit_1,
		"exit_1\t\t      :./img/exit/exit_1.xpm:E");
	add_img_to_garbage_memory(data, &data->textures.exit_2,
		"exit_2\t\t      :./img/exit/exit_open_2.xpm:E");
	add_img_to_garbage_memory(data, &data->textures.exit_3,
		"exit_3\t\t      :./img/exit/exit_open_3.xpm:E");
	add_img_to_garbage_memory(data, &data->textures.exit_4,
		"exit_4\t\t      :./img/exit/exit_open_4.xpm:E");
	add_img_to_garbage_memory(data, &data->textures.exit_5,
		"exit_5\t\t      :./img/exit/exit_open_5.xpm:E");
	add_img_to_garbage_memory(data, &data->textures.exit_6,
		"exit_6\t\t      :./img/exit/exit_open_6.xpm:E");
	add_img_to_garbage_memory(data, &data->textures.exit_7,
		"exit_7\t\t      :./img/exit/exit_open_7.xpm:E");
	add_img_to_garbage_memory(data, &data->textures.exit_8,
		"exit_8\t\t      :./img/exit/exit_open_8.xpm:E");
	add_img_to_garbage_memory(data, &data->textures.exit_9,
		"exit_9\t\t      :./img/exit/exit_open_9.xpm:E");
	add_img_to_garbage_memory(data, &data->textures.exit_10,
		"exit_10\t\t      :./img/exit/exit_open_10.xpm:E");
	add_img_to_garbage_memory(data, &data->textures.exit_11,
		"exit_11\t\t      :./img/exit/exit_open_11.xpm:E");
	add_img_to_garbage_memory(data, &data->textures.exit_12,
		"exit_12\t\t      :./img/exit/exit_open_12.xpm:E");
	add_img_to_garbage_memory(data, &data->textures.exit_13,
		"exit_13\t\t      :./img/exit/exit_open_13.xpm:E");
	add_img_to_garbage_memory(data, &data->textures.exit_14,
		"exit_14\t\t      :./img/exit/exit_open_14.xpm:E");
	add_img_to_garbage_memory(data, &data->textures.exit_15,
		"exit_15\t\t      :./img/exit/exit_open_15.xpm:E");
	add_img_to_garbage_memory(data, &data->textures.exit_16,
		"exit_16\t\t      :./img/exit/exit_open_16.xpm:E");
	add_img_to_garbage_memory(data, &data->textures.exit_17,
		"exit_17\t\t      :./img/exit/exit_open_17.xpm:E");
	add_img_to_garbage_memory(data, &data->textures.exit_18,
		"exit_18\t\t      :./img/exit/exit_open_18.xpm:E");
	add_img_to_garbage_memory(data, &data->textures.exit_19,
		"exit_19\t\t      :./img/exit/exit_open_19.xpm:E");
	if (!data->textures.exit_1.img || !data->textures.exit_2.img
		|| !data->textures.exit_3.img || !data->textures.exit_4.img
		|| !data->textures.exit_5.img || !data->textures.exit_6.img
		|| !data->textures.exit_7.img || !data->textures.exit_8.img
		|| !data->textures.exit_9.img || !data->textures.exit_10.img
		|| !data->textures.exit_11.img || !data->textures.exit_12.img
		|| !data->textures.exit_13.img || !data->textures.exit_14.img
		|| !data->textures.exit_15.img || !data->textures.exit_16.img
		|| !data->textures.exit_17.img || !data->textures.exit_18.img
		|| !data->textures.exit_19.img)
		return (false);
	return (true);
}

bool	init_screen_indoor(t_data *data)
{
	printf("=========================================================================================\n| SCREEN_INDOOR_TEXTURES\n=========================================================================================\n");
	add_img_to_garbage_memory(data, &data->textures.wall_screen_indoor,
		"wall_screen_indoor_0   :./img/wall_screen_animation/wall_screen_indoor.xpm:y");
	add_img_to_garbage_memory(data, &data->textures.wall_screen_indoor_1,
		"wall_screen_indoor_1   :./img/wall_screen_animation/wall_screen_indoor_1.xpm:y");
	add_img_to_garbage_memory(data, &data->textures.wall_screen_indoor_2,
		"wall_screen_indoor_2   :./img/wall_screen_animation/wall_screen_indoor_2.xpm:y");
	add_img_to_garbage_memory(data, &data->textures.wall_screen_indoor_3,
		"wall_screen_indoor_3   :./img/wall_screen_animation/wall_screen_indoor_3.xpm:y");
	add_img_to_garbage_memory(data, &data->textures.wall_screen_indoor_4,
		"wall_screen_indoor_4   :./img/wall_screen_animation/wall_screen_indoor_4.xpm:y");
	add_img_to_garbage_memory(data, &data->textures.wall_screen_indoor_5,
		"wall_screen_indoor_5   :./img/wall_screen_animation/wall_screen_indoor_5.xpm:y");
	add_img_to_garbage_memory(data, &data->textures.wall_screen_indoor_6,
		"wall_screen_indoor_6   :./img/wall_screen_animation/wall_screen_indoor_6.xpm:y");
	add_img_to_garbage_memory(data, &data->textures.wall_screen_indoor_7,
		"wall_screen_indoor_7   :./img/wall_screen_animation/wall_screen_indoor_7.xpm:y");
	add_img_to_garbage_memory(data, &data->textures.wall_screen_indoor_8,
		"wall_screen_indoor_8   :./img/wall_screen_animation/wall_screen_indoor_8.xpm:y");
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

bool	init_screen_outdoor(t_data *data)
{
	printf("=========================================================================================\n| SCREEN_OUTDOOR_TEXTURES\n=========================================================================================\n");
	add_img_to_garbage_memory(data, &data->textures.wall_screen_outdoor,
		"wall_screen_outdoor_0  :./img/screen_outdoor_animation/wall_screen_outdoor.xpm:t");
	add_img_to_garbage_memory(data, &data->textures.wall_screen_outdoor_1,
		"wall_screen_outdoor_1  :./img/screen_outdoor_animation/wall_screen_outdoor_1.xpm:t");
	add_img_to_garbage_memory(data, &data->textures.wall_screen_outdoor_2,
		"wall_screen_outdoor_2  :./img/screen_outdoor_animation/wall_screen_outdoor_2.xpm:t");
	add_img_to_garbage_memory(data, &data->textures.wall_screen_outdoor_3,
		"wall_screen_outdoor_3  :./img/screen_outdoor_animation/wall_screen_outdoor_3.xpm:t");
	add_img_to_garbage_memory(data, &data->textures.wall_screen_outdoor_4,
		"wall_screen_outdoor_4  :./img/screen_outdoor_animation/wall_screen_outdoor_2.xpm:t");
	add_img_to_garbage_memory(data, &data->textures.wall_screen_outdoor_5,
		"wall_screen_outdoor_5  :./img/screen_outdoor_animation/wall_screen_outdoor_1.xpm:t");
	if (!data->textures.wall_screen_outdoor.img
		|| !data->textures.wall_screen_outdoor_1.img
		|| !data->textures.wall_screen_outdoor_2.img
		|| !data->textures.wall_screen_outdoor_3.img
		|| !data->textures.wall_screen_outdoor_4.img
		|| !data->textures.wall_screen_outdoor_5.img)
		return (false);
	return (true);
}

bool	init_capsule(t_data *data)
{
	printf("=========================================================================================\n| CAPSULE_TEXTURES\n=========================================================================================\n");
	add_img_to_garbage_memory(data, &data->textures.capsule,
		"capsule_0              :./img/capsule_animation/capsule.xpm:D");
	add_img_to_garbage_memory(data, &data->textures.capsule_1,
		"capsule_1              :./img/capsule_animation/capsule_1.xpm:D");
	add_img_to_garbage_memory(data, &data->textures.capsule_2,
		"capsule_2              :./img/capsule_animation/capsule_2.xpm:D");
	add_img_to_garbage_memory(data, &data->textures.capsule_3,
		"capsule_3              :./img/capsule_animation/capsule_3.xpm:D");
	add_img_to_garbage_memory(data, &data->textures.capsule_4,
		"capsule_4              :./img/capsule_animation/capsule_3.xpm:D");
	add_img_to_garbage_memory(data, &data->textures.capsule_5,
		"capsule_5              :./img/capsule_animation/capsule_3.xpm:D");
	if (!data->textures.capsule.img || !data->textures.capsule_1.img
		|| !data->textures.capsule_2.img || !data->textures.capsule_3.img
		|| !data->textures.capsule_4.img || !data->textures.capsule_5.img)
		return (false);
	return (true);
}

