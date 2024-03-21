/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_init_anim.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:34:58 by tauer             #+#    #+#             */
/*   Updated: 2024/03/21 14:54:14 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

void	initadd_first_door(t_data *data)
{
	if (add_img_to_garbage_memory(data, &data->textures.exit_1,
			"exit_1\t\t      :./img/exit/exit_1.xpm:0E"))
		add_img_to_garbage_memory(data, &data->textures.exit_1,
			"exit_1\t\t      :./img/exit/exit_1.xpm:0E");
	add_img_to_garbage_memory(data, &data->textures.exit_2,
		"exit_2\t\t      :./img/exit/exit_open_2.xpm:0E");
	add_img_to_garbage_memory(data, &data->textures.exit_3,
		"exit_3\t\t      :./img/exit/exit_open_3.xpm:0E");
	add_img_to_garbage_memory(data, &data->textures.exit_4,
		"exit_4\t\t      :./img/exit/exit_open_4.xpm:0E");
	add_img_to_garbage_memory(data, &data->textures.exit_5,
		"exit_5\t\t      :./img/exit/exit_open_5.xpm:0E");
	add_img_to_garbage_memory(data, &data->textures.exit_6,
		"exit_6\t\t      :./img/exit/exit_open_6.xpm:0E");
	add_img_to_garbage_memory(data, &data->textures.exit_7,
		"exit_7\t\t      :./img/exit/exit_open_7.xpm:0E");
	add_img_to_garbage_memory(data, &data->textures.exit_8,
		"exit_8\t\t      :./img/exit/exit_open_8.xpm:0E");
	add_img_to_garbage_memory(data, &data->textures.exit_9,
		"exit_9\t\t      :./img/exit/exit_open_9.xpm:0E");
	add_img_to_garbage_memory(data, &data->textures.exit_10,
		"exit_10\t\t      :./img/exit/exit_open_10.xpm:0E");
	add_img_to_garbage_memory(data, &data->textures.exit_11,
		"exit_11\t\t      :./img/exit/exit_open_11.xpm:0E");
}

void	initadd_last_door(t_data *data)
{
	add_img_to_garbage_memory(data, &data->textures.exit_12,
		"exit_12\t\t      :./img/exit/exit_open_12.xpm:0E");
	add_img_to_garbage_memory(data, &data->textures.exit_13,
		"exit_13\t\t      :./img/exit/exit_open_13.xpm:0E");
	add_img_to_garbage_memory(data, &data->textures.exit_14,
		"exit_14\t\t      :./img/exit/exit_open_14.xpm:0E");
	add_img_to_garbage_memory(data, &data->textures.exit_15,
		"exit_15\t\t      :./img/exit/exit_open_15.xpm:0E");
	add_img_to_garbage_memory(data, &data->textures.exit_16,
		"exit_16\t\t      :./img/exit/exit_open_16.xpm:0E");
	add_img_to_garbage_memory(data, &data->textures.exit_17,
		"exit_17\t\t      :./img/exit/exit_open_17.xpm:0E");
	add_img_to_garbage_memory(data, &data->textures.exit_18,
		"exit_18\t\t      :./img/exit/exit_open_18.xpm:0E");
	add_img_to_garbage_memory(data, &data->textures.exit_19,
		"exit_19\t\t      :./img/exit/exit_open_19.xpm:0E");
}

bool	init_exit(t_data *data)
{
	put_error_msg("| EXIT_TEXTURES");
	initadd_first_door(data);
	initadd_last_door(data);
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

bool	init_capsule(t_data *data)
{
	put_error_msg("| CAPSULE_TEXTURES");
	add_img_to_garbage_memory(data, &data->textures.capsule,
		"capsule_0              :./img/capsule_animation/capsule.xpm:YD");
	add_img_to_garbage_memory(data, &data->textures.capsule_1,
		"capsule_1              :./img/capsule_animation/capsule_1.xpm:YD");
	add_img_to_garbage_memory(data, &data->textures.capsule_2,
		"capsule_2              :./img/capsule_animation/capsule_2.xpm:YD");
	add_img_to_garbage_memory(data, &data->textures.capsule_3,
		"capsule_3              :./img/capsule_animation/capsule_3.xpm:YD");
	add_img_to_garbage_memory(data, &data->textures.capsule_4,
		"capsule_4              :./img/capsule_animation/capsule_3.xpm:YD");
	add_img_to_garbage_memory(data, &data->textures.capsule_5,
		"capsule_5              :./img/capsule_animation/capsule_3.xpm:YD");
	if (!data->textures.capsule.img || !data->textures.capsule_1.img
		|| !data->textures.capsule_2.img || !data->textures.capsule_3.img
		|| !data->textures.capsule_4.img || !data->textures.capsule_5.img)
		return (false);
	return (true);
}
