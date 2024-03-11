/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:20:10 by tauer             #+#    #+#             */
/*   Updated: 2024/03/11 12:52:09 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	destroy_img(t_data *data)
{
	// floors
	mlx_destroy_image(data->mlx, data->textures.empty.img);
	mlx_destroy_image(data->mlx, data->textures.floor.img);
	// corner
	mlx_destroy_image(data->mlx, data->textures.right_top_corner_up.img);
	mlx_destroy_image(data->mlx, data->textures.left_top_corner_up.img);
	mlx_destroy_image(data->mlx, data->textures.right_top_corner.img);
	mlx_destroy_image(data->mlx, data->textures.left_top_corner.img);
	mlx_destroy_image(data->mlx, data->textures.right_corner.img);
	mlx_destroy_image(data->mlx, data->textures.left_corner.img);
	// walls
	mlx_destroy_image(data->mlx, data->textures.right_empty.img);
	mlx_destroy_image(data->mlx, data->textures.left_empty.img);
	mlx_destroy_image(data->mlx, data->textures.wall.img);
	mlx_destroy_image(data->mlx, data->textures.wall_up.img);
	mlx_destroy_image(data->mlx, data->textures.wall_4.img);
	mlx_destroy_image(data->mlx, data->textures.wall_down.img);
	mlx_destroy_image(data->mlx, data->textures.wall_down_empty.img);
	mlx_destroy_image(data->mlx, data->textures.down.img);
	mlx_destroy_image(data->mlx, data->textures.toward_wall.img);
	mlx_destroy_image(data->mlx, data->textures.toward_wall_left_empty.img);
	mlx_destroy_image(data->mlx, data->textures.toward_wall_right_empty.img);
	mlx_destroy_image(data->mlx, data->textures.collectibles.img);
	mlx_destroy_image(data->mlx, data->textures.perso.img);
	mlx_destroy_image(data->mlx, data->textures.breathing_perso_1.img);
	mlx_destroy_image(data->mlx, data->textures.breathing_perso_2.img);
	mlx_destroy_image(data->mlx, data->textures.back_perso.img);
	mlx_destroy_image(data->mlx, data->textures.back_perso_1.img);
	mlx_destroy_image(data->mlx, data->textures.back_perso_2.img);
	mlx_destroy_image(data->mlx, data->textures.right_perso.img);
	mlx_destroy_image(data->mlx, data->textures.right_perso_1.img);
	mlx_destroy_image(data->mlx, data->textures.right_perso_2.img);
	mlx_destroy_image(data->mlx, data->textures.left_perso.img);
	mlx_destroy_image(data->mlx, data->textures.left_perso_1.img);
	mlx_destroy_image(data->mlx, data->textures.left_perso_2.img);
	mlx_destroy_image(data->mlx, data->textures.running_1.img);
	mlx_destroy_image(data->mlx, data->textures.running_2.img);
	mlx_destroy_image(data->mlx, data->textures.ennemy_front.img);
	mlx_destroy_image(data->mlx, data->textures.ennemy_back.img);
	mlx_destroy_image(data->mlx, data->textures.ennemy_right.img);
	mlx_destroy_image(data->mlx, data->textures.ennemy_left.img);
	mlx_destroy_image(data->mlx, data->textures.capsule.img);
	mlx_destroy_image(data->mlx, data->textures.capsule_1.img);
	mlx_destroy_image(data->mlx, data->textures.capsule_2.img);
	mlx_destroy_image(data->mlx, data->textures.capsule_3.img);
	mlx_destroy_image(data->mlx, data->textures.capsule_4.img);
	mlx_destroy_image(data->mlx, data->textures.capsule_5.img);
	mlx_destroy_image(data->mlx, data->textures.exit_1.img);
	mlx_destroy_image(data->mlx, data->textures.exit_2.img);
	mlx_destroy_image(data->mlx, data->textures.exit_3.img);
	mlx_destroy_image(data->mlx, data->textures.exit_4.img);
	mlx_destroy_image(data->mlx, data->textures.exit_5.img);
	mlx_destroy_image(data->mlx, data->textures.exit_6.img);
	mlx_destroy_image(data->mlx, data->textures.exit_7.img);
	mlx_destroy_image(data->mlx, data->textures.exit_8.img);
	mlx_destroy_image(data->mlx, data->textures.exit_9.img);
	mlx_destroy_image(data->mlx, data->textures.exit_10.img);
	mlx_destroy_image(data->mlx, data->textures.exit_11.img);
	mlx_destroy_image(data->mlx, data->textures.exit_12.img);
	mlx_destroy_image(data->mlx, data->textures.exit_13.img);
	mlx_destroy_image(data->mlx, data->textures.exit_14.img);
	mlx_destroy_image(data->mlx, data->textures.exit_15.img);
	mlx_destroy_image(data->mlx, data->textures.exit_16.img);
	mlx_destroy_image(data->mlx, data->textures.exit_17.img);
	mlx_destroy_image(data->mlx, data->textures.exit_18.img);
	mlx_destroy_image(data->mlx, data->textures.exit_19.img);
	mlx_destroy_image(data->mlx, data->textures.panel_wall.img);
	mlx_destroy_image(data->mlx, data->textures.private_door.img);
	mlx_destroy_image(data->mlx, data->textures.wall_screen.img);
	mlx_destroy_image(data->mlx, data->textures.wall_screen_outdoor.img);
	mlx_destroy_image(data->mlx, data->textures.wall_screen_outdoor_1.img);
	mlx_destroy_image(data->mlx, data->textures.wall_screen_outdoor_2.img);
	mlx_destroy_image(data->mlx, data->textures.wall_screen_outdoor_3.img);
	mlx_destroy_image(data->mlx, data->textures.wall_screen_outdoor_4.img);
	mlx_destroy_image(data->mlx, data->textures.wall_screen_outdoor_5.img);
	mlx_destroy_image(data->mlx, data->textures.wall_screen_indoor.img);
	mlx_destroy_image(data->mlx, data->textures.wall_screen_indoor_1.img);
	mlx_destroy_image(data->mlx, data->textures.wall_screen_indoor_2.img);
	mlx_destroy_image(data->mlx, data->textures.wall_screen_indoor_3.img);
	mlx_destroy_image(data->mlx, data->textures.wall_screen_indoor_4.img);
	mlx_destroy_image(data->mlx, data->textures.wall_screen_indoor_5.img);
	mlx_destroy_image(data->mlx, data->textures.wall_screen_indoor_6.img);
	mlx_destroy_image(data->mlx, data->textures.wall_screen_indoor_7.img);
	mlx_destroy_image(data->mlx, data->textures.wall_screen_indoor_8.img);
	mlx_destroy_image(data->mlx, data->textures.floor_x.img);
	mlx_destroy_image(data->mlx, data->textures.floor_ventil.img);
	mlx_destroy_image(data->mlx, data->textures.num0.img);
	mlx_destroy_image(data->mlx, data->textures.num1.img);
	mlx_destroy_image(data->mlx, data->textures.num2.img);
	mlx_destroy_image(data->mlx, data->textures.num3.img);
	mlx_destroy_image(data->mlx, data->textures.num4.img);
	mlx_destroy_image(data->mlx, data->textures.num5.img);
	mlx_destroy_image(data->mlx, data->textures.num6.img);
	mlx_destroy_image(data->mlx, data->textures.num7.img);
	mlx_destroy_image(data->mlx, data->textures.num8.img);
	mlx_destroy_image(data->mlx, data->textures.num9.img);
	mlx_destroy_image(data->mlx, data->base_image.img);
	mlx_destroy_image(data->mlx, data->base_num.img);
}

int	close_win(t_data *data)
{
	free_map(data->map);
	destroy_img(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	mlx_destroy_window(data->mlx_num, data->win_num);
	mlx_destroy_display(data->mlx_num);
	free(data->mlx_num);
	exit(1);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
