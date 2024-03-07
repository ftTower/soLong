/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:34:39 by tauer             #+#    #+#             */
/*   Updated: 2024/03/07 19:09:54 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	link_breathing(t_data *data)
{
	data->textures.perso.next = &data->textures.breathing_perso_1;
	data->textures.breathing_perso_1.next = &data->textures.breathing_perso_2;
	data->textures.breathing_perso_2.next = &data->textures.breathing_perso_1;
	// data->textures.breathing_perso_1.next = &data->textures.perso;
}

void	link_back_breathing(t_data *data)
{
	data->textures.back_perso.next = &data->textures.back_perso_1;
	data->textures.back_perso_1.next = &data->textures.back_perso_2;
	data->textures.back_perso_2.next = &data->textures.back_perso;
}

void	link_right_breathing(t_data *data)
{
	data->textures.right_perso.next = &data->textures.right_perso_1;
	data->textures.right_perso_1.next = &data->textures.right_perso_2;
	data->textures.right_perso_2.next = &data->textures.right_perso;
}

void	link_left_breathing(t_data *data)
{
	data->textures.left_perso.next = &data->textures.left_perso_1;
	data->textures.left_perso_1.next = &data->textures.left_perso_2;
	data->textures.left_perso_2.next = &data->textures.left_perso;
}

void	link_running(t_data *data)
{
	data->textures.running_1.next = &data->textures.running_2;
	data->textures.running_2.next = &data->textures.running_1;
}

void	link_capsule(t_data *data)
{
	data->textures.capsule.next = &data->textures.capsule_1;
	data->textures.capsule_1.next = &data->textures.capsule_2;
	data->textures.capsule_2.next = &data->textures.capsule_3;
	data->textures.capsule_3.next = &data->textures.capsule_4;
	data->textures.capsule_4.next = &data->textures.capsule_5;
	data->textures.capsule_5.next = &data->textures.capsule;
}

void	link_screen_outdoor(t_data *data)
{
	data->textures.wall_screen_outdoor.next = &data->textures.wall_screen_outdoor_1;
	data->textures.wall_screen_outdoor_1.next = &data->textures.wall_screen_outdoor_2;
	data->textures.wall_screen_outdoor_2.next = &data->textures.wall_screen_outdoor_3;
	data->textures.wall_screen_outdoor_3.next = &data->textures.wall_screen_outdoor_4;
	data->textures.wall_screen_outdoor_4.next = &data->textures.wall_screen_outdoor_5;
	data->textures.wall_screen_outdoor_5.next = &data->textures.wall_screen_outdoor;
}

void	link_screen_indoor(t_data *data)
{
	data->textures.wall_screen_indoor.next = &data->textures.wall_screen_indoor_1;
	data->textures.wall_screen_indoor_1.next = &data->textures.wall_screen_indoor_2;
	data->textures.wall_screen_indoor_2.next = &data->textures.wall_screen_indoor_3;
	data->textures.wall_screen_indoor_3.next = &data->textures.wall_screen_indoor_4;
	data->textures.wall_screen_indoor_4.next = &data->textures.wall_screen_indoor_5;
	data->textures.wall_screen_indoor_5.next = &data->textures.wall_screen_indoor_6;
	data->textures.wall_screen_indoor_6.next = &data->textures.wall_screen_indoor_7;
	data->textures.wall_screen_indoor_7.next = &data->textures.wall_screen_indoor_8;
	data->textures.wall_screen_indoor_8.next = &data->textures.wall_screen_indoor;
}

void	link_animations(t_data *data)
{
	link_breathing(data);
	link_back_breathing(data);
	link_right_breathing(data);
	link_left_breathing(data);
	link_running(data);
	link_capsule(data);
	link_screen_outdoor(data);
	link_screen_indoor(data);
	link_exit(data);
}

void	init_textures(t_data *data)
{
	init_perso(data);
	init_exit(data);
	init_screen_indoor(data);
	init_screen_outdoor(data);
	init_capsule(data);
	init_walls(data);
	init_wall_cosmetics(data);
	init_floor(data);
	init_ennemy(data);
	init_rest(data);
}

void	set_currents(t_data *data)
{
	data->textures.current_ennemy = data->textures.ennemy_front;
	data->textures.current_perso = data->textures.perso;
	data->textures.current_capsule = data->textures.capsule;
	data->textures.current_screen_outdoor = data->textures.wall_screen_outdoor;
	data->textures.current_screen_indoor = data->textures.wall_screen_indoor;
	data->textures.current_exit = data->textures.exit_1;
}

void	prepare_textures(t_data *data)
{	
	init_textures(data);
	link_animations(data);
	set_currents(data);
}

void	quick_next(t_data *data)
{
	data->textures.current_screen_indoor = *data->textures.current_screen_indoor.next;
	if (data->collectibles_left == 0)
		data->textures.current_exit = *data->textures.current_exit.next;
}

void	medium_next(t_data *data)
{
	data->textures.current_capsule = *data->textures.current_capsule.next;
	data->textures.current_screen_outdoor = *data->textures.current_screen_outdoor.next;
}

void	slow_next(t_data *data)
{
	data->textures.current_perso = *data->textures.current_perso.next;
	data->textures.current_capsule = *data->textures.current_capsule.next;
}
