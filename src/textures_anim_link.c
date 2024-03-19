/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_anim_link.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:29:46 by tauer             #+#    #+#             */
/*   Updated: 2024/03/19 15:55:30 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	link_exit(t_data *data)
{
	data->textures.exit_1.next = &data->textures.exit_2;
	data->textures.exit_2.next = &data->textures.exit_3;
	data->textures.exit_3.next = &data->textures.exit_4;
	data->textures.exit_4.next = &data->textures.exit_5;
	data->textures.exit_5.next = &data->textures.exit_6;
	data->textures.exit_6.next = &data->textures.exit_7;
	data->textures.exit_7.next = &data->textures.exit_8;
	data->textures.exit_8.next = &data->textures.exit_9;
	data->textures.exit_9.next = &data->textures.exit_10;
	data->textures.exit_10.next = &data->textures.exit_11;
	data->textures.exit_11.next = &data->textures.exit_12;
	data->textures.exit_12.next = &data->textures.exit_13;
	data->textures.exit_13.next = &data->textures.exit_14;
	data->textures.exit_14.next = &data->textures.exit_15;
	data->textures.exit_15.next = &data->textures.exit_16;
	data->textures.exit_16.next = &data->textures.exit_17;
	data->textures.exit_17.next = &data->textures.exit_18;
	data->textures.exit_18.next = &data->textures.exit_19;
	data->textures.exit_19.next = &data->textures.exit_18;
}

void	link_deco_start(t_data *data)
{
	data->textures.capsule.next = &data->textures.capsule_1;
	data->textures.capsule_1.next = &data->textures.capsule_2;
	data->textures.capsule_2.next = &data->textures.capsule_3;
	data->textures.capsule_3.next = &data->textures.capsule_4;
	data->textures.capsule_4.next = &data->textures.capsule_5;
	data->textures.capsule_5.next = &data->textures.capsule;
	data->textures.wall_screen_outdoor.next
		= &data->textures.wall_screen_outdoor_1;
	data->textures.wall_screen_outdoor_1.next
		= &data->textures.wall_screen_outdoor_2;
	data->textures.wall_screen_outdoor_2.next
		= &data->textures.wall_screen_outdoor_3;
	data->textures.wall_screen_outdoor_3.next
		= &data->textures.wall_screen_outdoor_4;
	data->textures.wall_screen_outdoor_4.next
		= &data->textures.wall_screen_outdoor_5;
	data->textures.wall_screen_outdoor_5.next
		= &data->textures.wall_screen_outdoor;
}

void	link_deco(t_data *data)
{
	link_deco_start(data);
	data->textures.wall_screen_indoor.next
		= &data->textures.wall_screen_indoor_1;
	data->textures.wall_screen_indoor_1.next
		= &data->textures.wall_screen_indoor_2;
	data->textures.wall_screen_indoor_2.next
		= &data->textures.wall_screen_indoor_3;
	data->textures.wall_screen_indoor_3.next
		= &data->textures.wall_screen_indoor_4;
	data->textures.wall_screen_indoor_4.next
		= &data->textures.wall_screen_indoor_5;
	data->textures.wall_screen_indoor_5.next
		= &data->textures.wall_screen_indoor_6;
	data->textures.wall_screen_indoor_6.next
		= &data->textures.wall_screen_indoor_7;
	data->textures.wall_screen_indoor_7.next
		= &data->textures.wall_screen_indoor_8;
	data->textures.wall_screen_indoor_8.next
		= &data->textures.wall_screen_indoor;
}

void	link_perso(t_data *data)
{
	data->textures.perso.next = &data->textures.breathing_perso_1;
	data->textures.breathing_perso_1.next = &data->textures.breathing_perso_2;
	data->textures.breathing_perso_2.next = &data->textures.breathing_perso_1;
	data->textures.back_perso.next = &data->textures.back_perso_1;
	data->textures.back_perso_1.next = &data->textures.back_perso_2;
	data->textures.back_perso_2.next = &data->textures.back_perso;
	data->textures.right_perso.next = &data->textures.right_perso_1;
	data->textures.right_perso_1.next = &data->textures.right_perso_2;
	data->textures.right_perso_2.next = &data->textures.right_perso;
	data->textures.left_perso.next = &data->textures.left_perso_1;
	data->textures.left_perso_1.next = &data->textures.left_perso_2;
	data->textures.left_perso_2.next = &data->textures.left_perso;
	data->textures.running_1.next = &data->textures.running_2;
	data->textures.running_2.next = &data->textures.running_1;
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
