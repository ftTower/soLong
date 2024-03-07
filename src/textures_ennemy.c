/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_ennemy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:56:40 by tauer             #+#    #+#             */
/*   Updated: 2024/03/07 19:07:55 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void    init_ennemy(t_data *data)
{
    data->textures.ennemy_front = new_file_img("./img/ennemy/ennemy_front/ennemy.xpm",
			data);
	data->textures.ennemy_back = new_file_img("./img/ennemy/ennemy_back/back_perso_1.xpm",
			data);
	data->textures.ennemy_left = new_file_img("./img/ennemy/ennemy_left/left_perso_1.xpm",
			data);
	data->textures.ennemy_right = new_file_img("./img/ennemy/ennemy_right/right_perso_1.xpm",
			data);
}

void    init_rest(t_data *data)
{
	data->textures.collectibles = new_file_img("./img/collectibles.xpm", data);
    
}