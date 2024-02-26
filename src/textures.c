/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:34:39 by tauer             #+#    #+#             */
/*   Updated: 2024/02/19 19:54:40 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	set_breathing(t_data *data)
{
	data->textures.perso.next = &data->textures.breathing_perso_1;
	data->textures.breathing_perso_1.next = &data->textures.breathing_perso_2;
	data->textures.breathing_perso_2.next = &data->textures.breathing_perso_1;
	// data->textures.breathing_perso_1.next = &data->textures.perso;
}

void	set_back_breathing(t_data *data)
{
	data->textures.back_perso.next = &data->textures.back_perso_1;
	data->textures.back_perso_1.next = &data->textures.back_perso_2;
	data->textures.back_perso_2.next = &data->textures.back_perso;
}

void	set_right_breathing(t_data *data)
{
	data->textures.right_perso.next = &data->textures.right_perso_1;
	data->textures.right_perso_1.next = &data->textures.right_perso_2;
	data->textures.right_perso_2.next = &data->textures.right_perso;	
}

void	set_left_breathing(t_data *data)
{
	data->textures.left_perso.next = &data->textures.left_perso_1;
	data->textures.left_perso_1.next = &data->textures.left_perso_2;
	data->textures.left_perso_2.next = &data->textures.left_perso;	
}

void	set_running(t_data *data)
{
	data->textures.running_1.next = &data->textures.running_2;
	data->textures.running_2.next = &data->textures.running_1;
}

void	set_capsule(t_data *data)
{
	data->textures.capsule.next = &data->textures.capsule_1;
	data->textures.capsule_1.next = &data->textures.capsule_2;
	data->textures.capsule_2.next = &data->textures.capsule_3;
	data->textures.capsule_3.next = &data->textures.capsule_4;
	data->textures.capsule_4.next = &data->textures.capsule_5;
	data->textures.capsule_5.next = &data->textures.capsule;
}

void	set_screen_outdoor(t_data *data)
{
	data->textures.wall_screen_outdoor.next = &data->textures.wall_screen_outdoor_1;
	data->textures.wall_screen_outdoor_1.next = &data->textures.wall_screen_outdoor_2;
	data->textures.wall_screen_outdoor_2.next = &data->textures.wall_screen_outdoor_3;
	data->textures.wall_screen_outdoor_3.next = &data->textures.wall_screen_outdoor_4;
	data->textures.wall_screen_outdoor_4.next = &data->textures.wall_screen_outdoor_5;
	data->textures.wall_screen_outdoor_5.next = &data->textures.wall_screen_outdoor;
}

void	set_screen_indoor(t_data *data)
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

void	set_exit(t_data *data)
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

void	set_textures(t_data *data)
{
	data->textures.perso = new_file_img("./img/perso/perso/perso.xpm",
			data);
	data->textures.breathing_perso_1 = new_file_img("./img/perso/breathing_perso/breathing_1.xpm",
			data);
	data->textures.breathing_perso_2 = new_file_img("./img/perso/breathing_perso/breathing_2.xpm",
			data);

	data->textures.back_perso = new_file_img("./img/perso/perso/back_perso.xpm", data);
	data->textures.back_perso_1 = new_file_img("./img/perso/back_breathing_perso/back_perso_1.xpm", data);
	data->textures.back_perso_2 = new_file_img("./img/perso/back_breathing_perso/back_perso_2.xpm", data);

	data->textures.right_perso = new_file_img("./img/perso/perso/right_perso.xpm", data);
	data->textures.right_perso_1 = new_file_img("./img/perso/right_breathing_perso/right_perso_1.xpm", data);
	data->textures.right_perso_2 = new_file_img("./img/perso/right_breathing_perso/right_perso_2.xpm", data);

	data->textures.left_perso = new_file_img("./img/perso/perso/left_perso.xpm", data);
	data->textures.left_perso_1 = new_file_img("./img/perso/left_breathing_perso/left_perso_1.xpm", data);
	data->textures.left_perso_2 = new_file_img("./img/perso/left_breathing_perso/left_perso_2.xpm", data);

	data->textures.running_1 = new_file_img("img/perso/running_perso/running_1.xpm", data);
	data->textures.running_2 = new_file_img("img/perso/running_perso/running_2.xpm", data);

	// exit
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
	// wall_screen_animation
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
	// cosmetic wall
	data->textures.private_door = new_file_img("./img/cosmetic_4_wall/private_door.xpm",
			data);
	data->textures.panel_wall = new_file_img("./img/cosmetic_4_wall/pannel_wall.xpm",
			data);
	data->textures.wall_screen = new_file_img("./img/cosmetic_4_wall/wall_screen.xpm",
			data);
	// screen_outdoor_animation
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
	// cosmetic floor
	data->textures.floor_x = new_file_img("./img/floor_cosmetics/floor_x.xpm",
			data);
	data->textures.floor_ventil = new_file_img("./img/floor_cosmetics/floor_ventil.xpm",
			data);
	data->textures.floor_ventil = new_file_img("./img/floor_cosmetics/floor_ventil.xpm",
			data);
	data->textures.empty = new_file_img("./img/empty.xpm", data);
	data->textures.floor = new_file_img("./img/floor.xpm", data);
	data->textures.right_top_corner_up = new_file_img("./img/right_top_corner_up.xpm",
			data);
	data->textures.left_top_corner_up = new_file_img("./img/left_top_corner_up.xpm",
			data);
	data->textures.left_top_corner = new_file_img("./img/left_top_corner.xpm",
			data);
	data->textures.right_top_corner = new_file_img("./img/right_top_corner.xpm",
			data);
	data->textures.right_corner = new_file_img("./img/right_corner.xpm", data);
	data->textures.left_corner = new_file_img("./img/left_corner.xpm", data);
	data->textures.right_empty = new_file_img("./img/right_empty.xpm", data);
	data->textures.left_empty = new_file_img("./img/left_empty.xpm", data);
	data->textures.wall = new_file_img("./img/wall.xpm", data);
	data->textures.wall_up = new_file_img("./img/wall_up.xpm", data);
	data->textures.wall_4 = new_file_img("./img/wall_4.xpm", data);
	data->textures.wall_down = new_file_img("./img/wall_down.xpm", data);
	data->textures.wall_down_empty = new_file_img("./img/wall_down_empty.xpm",
			data);
	data->textures.down = new_file_img("./img/down.xpm", data);
	data->textures.toward_wall = new_file_img("./img/toward_wall.xpm", data);
	data->textures.toward_wall_left_empty = new_file_img("./img/toward_wall_left_empty.xpm",
			data);
	data->textures.toward_wall_right_empty = new_file_img("./img/toward_wall_right_empty.xpm",
			data);
	// data->textures.exit = new_file_img("./img/exit/exit.xpm", data);
	// data->textures.exit_open = new_file_img("./img/exit/exit_open.xpm",
	//		data);
	data->textures.ennemy = new_file_img("./img/ennemy/ennemy.xpm", data);
	data->textures.collectibles = new_file_img("./img/collectibles.xpm", data);
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
	set_breathing(data);
	set_back_breathing(data);
	set_right_breathing(data);
	set_left_breathing(data);
	set_running(data);
	set_capsule(data);
	set_screen_outdoor(data);
	set_screen_indoor(data);
	set_exit(data);
	data->textures.current_perso = data->textures.perso;
	data->textures.current_capsule = data->textures.capsule;
	data->textures.current_screen_outdoor = data->textures.wall_screen_outdoor;
	data->textures.current_screen_indoor = data->textures.wall_screen_indoor;
	data->textures.current_exit = data->textures.exit_1;
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
