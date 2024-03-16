/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_init_ennemy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:56:40 by tauer             #+#    #+#             */
/*   Updated: 2024/03/16 17:35:53 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

bool	init_ennemy(t_data *data)
{
	printf("=========================================================================================\n| ENNEMY_TEXTURES\n=========================================================================================\n");
	add_img_to_garbage_memory(data, &data->textures.ennemy_front,
		"enemy_front\t      :./img/ennemy/ennemy_front/ennemy.xpm:0E");
	add_img_to_garbage_memory(data, &data->textures.ennemy_back,
		"enemy_back\t      :./img/ennemy/ennemy_back/back_perso_1.xpm:0E");
	add_img_to_garbage_memory(data, &data->textures.ennemy_left,
		"enemy_back\t      :./img/ennemy/ennemy_left/left_perso_1.xpm:0E");
	add_img_to_garbage_memory(data, &data->textures.ennemy_right,
		"enemy_right\t      :./img/ennemy/ennemy_right/right_perso_1.xpm:0E");
	if (!data->textures.ennemy_front.img || !data->textures.ennemy_back.img
		|| !data->textures.ennemy_left.img || !data->textures.ennemy_right.img)
		return (false);
	return (true);
}
