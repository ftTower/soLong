/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_perso.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:26:51 by tauer             #+#    #+#             */
/*   Updated: 2024/03/07 18:56:04 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	init_back_perso(t_data *data)
{
	data->textures.back_perso = new_file_img("./img/perso/perso/back_perso.xpm",
			data);
	data->textures.back_perso_1 = new_file_img("./img/perso/back_breathing_perso/back_perso_1.xpm",
			data);
	data->textures.back_perso_2 = new_file_img("./img/perso/back_breathing_perso/back_perso_2.xpm",
			data);
}

void	init_right_perso(t_data *data)
{
	data->textures.right_perso = new_file_img("./img/perso/perso/right_perso.xpm",
			data);
	data->textures.right_perso_1 = new_file_img("./img/perso/right_breathing_perso/right_perso_1.xpm",
			data);
	data->textures.right_perso_2 = new_file_img("./img/perso/right_breathing_perso/right_perso_2.xpm",
			data);
}

void	init_left_perso(t_data *data)
{
	data->textures.left_perso = new_file_img("./img/perso/perso/left_perso.xpm",
			data);
	data->textures.left_perso_1 = new_file_img("./img/perso/left_breathing_perso/left_perso_1.xpm",
			data);
	data->textures.left_perso_2 = new_file_img("./img/perso/left_breathing_perso/left_perso_2.xpm",
			data);
}

void	init_running_perso(t_data *data)
{
	data->textures.running_1 = new_file_img("img/perso/running_perso/running_1.xpm",
			data);
	data->textures.running_2 = new_file_img("img/perso/running_perso/running_2.xpm",
			data);
}

void	init_perso(t_data *data)  
{
	data->textures.perso = new_file_img("./img/perso/perso/perso.xpm", data);
    data->textures.breathing_perso_1 = new_file_img("./img/perso/breathing_perso/breathing_1.xpm",
			data);
	data->textures.breathing_perso_2 = new_file_img("./img/perso/breathing_perso/breathing_2.xpm",
			data);
	init_back_perso(data);
	init_right_perso(data);
	init_left_perso(data);
	init_running_perso(data);
}
