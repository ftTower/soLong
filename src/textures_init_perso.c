/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_init_perso.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:26:51 by tauer             #+#    #+#             */
/*   Updated: 2024/03/21 19:34:27 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

bool	init_back_perso(t_data *data)
{
	add_img_to_garbage_memory(data, &data->textures.back_perso,
		"back_perso_0\t      :./img/perso/perso/back_perso.xpm:VP");
	if (!data->textures.back_perso.img)
		return (false);
	return (true);
}

bool	init_right_perso(t_data *data)
{
	add_img_to_garbage_memory(data, &data->textures.right_perso,
		"right_perso\t      :./img/perso/perso/right_perso.xpm:VP");
	if (!data->textures.right_perso.img)
		return (false);
	return (true);
}

bool	init_left_perso(t_data *data)
{
	add_img_to_garbage_memory(data, &data->textures.left_perso,
		"left_perso_0\t      :./img/perso/perso/left_perso.xpm:VP");

	if (!data->textures.left_perso.img)
		return (false);
	return (true);
}

bool	init_perso(t_data *data)
{
	put_error_msg("| PERSO_TEXTURES");
	add_img_to_garbage_memory(data, &data->textures.perso,
		"front_perso_0\t      :./img/perso/perso/perso.xpm:VP");

	if (!data->textures.perso.img || !init_back_perso(data)
		|| !init_right_perso(data) || !init_left_perso(data))
		return (false);
	data->textures.current_perso = data->textures.perso;
	return (true);
}
