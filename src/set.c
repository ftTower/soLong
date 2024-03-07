/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:46:08 by tauer             #+#    #+#             */
/*   Updated: 2024/03/07 19:10:10 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	set_input(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] == 'T')
			{
				data->collectibles++;
			}
			else if (data->map[x][y] == 'C')
			{
				data->x = x;
				data->y = y;
				data->start_x = data->x;
				data->start_y = data->y;
			}
			else if (data->map[x][y] == 'E')
			{
				data->e_x = x;
				data->e_y = y;
			}
			y++;
		}
		x++;
	}
	data->size_y = y - 1;
	data->size_x = x - 1;
	return ;
}

void	set_window_size(t_data *data)
{
	data->win_y = (data->size_x + 1) * 50;
	data->win_x = (data->size_y + 1) * 50;
	if (data->win_x > 1080 || data->win_y > 1920)
	{
		write(1, "[BAD MAP SIZE]\n\n", 17);
		printf("your map size [x:%d][y:%d]\n", data->size_x, data->size_y);
		write(1, "max map size  [x:38][y: 21]\n", 28);
		exit(1);
	}
}
void	set_key_false(t_data *data)
{
	data->key.up_key = false;
	data->key.down_key = false;
	data->key.left_key = false;
	data->key.right_key = false;
	data->key.right_key = false;
	data->key.shoot_key = false;
}

int	settings(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_num = mlx_init();
	if (!data->mlx || !data->mlx_num)
		close_win(data);
	data->win = mlx_new_window(data->mlx, data->win_x, data->win_y,
			"soooooLong");
	data->win_num = mlx_new_window(data->mlx_num, data->win_y_num,
			data->win_x_num, "Moves");
	if (!data->win || !data->win_num)
		return (free(data->mlx), 1);
	data->base_image = new_img(data->win_x, data->win_y, data);
	data->life_ennemy = 100;
	data->shocking_win = 0;
	data->mov_status = 1;
	data->switcher = 0;
	set_key_false(data);
	prepare_textures(data);
	custom_indoor_map(data);
	return (1);
}

void	set_win_num(t_data *data)
{
	data->win_y_num = 250;
	data->win_x_num = 25;
}

void	pre_settings(t_data *data)
{
	// map getting
	data->map = get_map(data->map_path);
	// print_map(data);
	// textures
	data->selecter_custom = 0;
	// time
	data->time_render = gettime();
	data->time_perso = gettime();
	data->time_capsule = gettime();
	data->time_ennemy = gettime();
	// movement
	data->move = 0;
	data->mov_chunk_x = 20;
	data->mov_chunk_y = 20;
	data->chunk_v_x = 20;
	data->chunk_v_y = 20;
	data->switcher = 1;
	// gameplay
	data->wave = 0;
	find_first_border(data);
	// counting_init
	data->collectibles = 0;
	set_input(data);
	set_window_size(data);
	set_win_num(data);
	data->collectibles_left = data->collectibles;
}
