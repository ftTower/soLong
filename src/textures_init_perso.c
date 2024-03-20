/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_init_perso.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:26:51 by tauer             #+#    #+#             */
/*   Updated: 2024/03/20 20:23:57 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

bool	init_back_perso(t_data *data)
{
	add_img_to_garbage_memory(data, &data->textures.back_perso,
		"back_perso_0\t      :./img/perso/perso/back_perso.xpm:VP");
	add_img_to_garbage_memory(data, &data->textures.back_perso_1,
		"back_perso_1\t      :./img/perso/back_breathing_perso/\
back_perso_1.xpm:VP");
	add_img_to_garbage_memory(data, &data->textures.back_perso_2,
		"back_perso_2\t      :./img/perso/back_breathing_perso/\
back_perso_2.xpm:VP");
	if (!data->textures.back_perso.img || !data->textures.back_perso_1.img
		|| !data->textures.back_perso_2.img)
		return (false);
	return (true);
}

bool	init_right_perso(t_data *data)
{
	add_img_to_garbage_memory(data, &data->textures.right_perso,
		"right_perso\t      :./img/perso/perso/right_perso.xpm:VP");
	add_img_to_garbage_memory(data, &data->textures.right_perso_1,
		"right_perso_1\t      :./img/perso/right_breathing_perso/\
right_perso_1.xpm:VP");
	add_img_to_garbage_memory(data, &data->textures.right_perso_2,
		"right_perso_2\t      :./img/perso/right_breathing_perso/\
right_perso_2.xpm:VP");
	if (!data->textures.right_perso.img || !data->textures.right_perso_1.img
		|| !data->textures.right_perso_2.img)
		return (false);
	return (true);
}

bool	init_left_perso(t_data *data)
{
	add_img_to_garbage_memory(data, &data->textures.left_perso,
		"left_perso_0\t      :./img/perso/perso/left_perso.xpm:VP");
	add_img_to_garbage_memory(data, &data->textures.left_perso_1,
		"left_perso_1\t      :./img/perso/left_breathing_perso/\
left_perso_1.xpm:VP");
	add_img_to_garbage_memory(data, &data->textures.left_perso_2,
		"left_perso_2\t      :./img/perso/left_breathing_perso/\
left_perso_2.xpm:VP");
	if (!data->textures.left_perso.img || !data->textures.left_perso_1.img
		|| !data->textures.left_perso_2.img)
		return (false);
	return (true);
}

bool	init_running_perso(t_data *data)
{
	add_img_to_garbage_memory(data, &data->textures.running_1,
		"running_1\t      :./img/perso/running_perso/running_1.xpm:VP");
	add_img_to_garbage_memory(data, &data->textures.running_2,
		"running_2\t      :./img/perso/running_perso/running_2.xpm:VP");
	if (!data->textures.running_1.img || !data->textures.running_2.img)
		return (false);
	return (true);
}

bool	init_perso(t_data *data)
{
	put_error_msg("| PERSO_TEXTURES");
	add_img_to_garbage_memory(data, &data->textures.perso,
		"front_perso_0\t      :./img/perso/perso/perso.xpm:VC");
	add_img_to_garbage_memory(data, &data->textures.breathing_perso_2,
		"front_perso_2\t      :./img/perso/breathing_perso/breathing_2.xpm:VP");
	add_img_to_garbage_memory(data, &data->textures.breathing_perso_1,
		"front_perso_1\t      :./img/perso/breathing_perso/breathing_1.xpm:VP");
	if (!data->textures.perso.img || !data->textures.breathing_perso_2.img
		|| !data->textures.breathing_perso_1.img || !init_back_perso(data)
		|| !init_right_perso(data) || !init_left_perso(data)
		|| !init_running_perso(data))
		return (false);
	return (true);
}
