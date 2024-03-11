/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:46:08 by tauer             #+#    #+#             */
/*   Updated: 2024/03/11 15:53:29 by tauer            ###   ########.fr       */
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
		free_map(data->map);
		exit(1);
	}
}


void	data_maker(t_data *data)
{
	data->life_ennemy = 100;
	data->shocking_win = 0;
	data->mov_status = 1;
	data->switcher = 0;
	data->base_image = new_img(data->win_x, data->win_y, data);
	set_key_false(data);
	textures_loader(data);
	custom_indoor_map(data);
}

int	settings(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		close_win(data);
	data->win = mlx_new_window(data->mlx, data->win_x, data->win_y,
			"soooooLong");
	if (!data->win)
		close_win(data);
	data_maker(data);
	return (1);
}

void	pre_settings(t_data *data)
{
	data->map = get_map(data->map_path);
	data->selecter_custom = 0;
	data->time_render = gettime();
	data->time_perso = gettime();
	data->time_capsule = gettime();
	data->time_ennemy = gettime();
	data->move = 0;
	data->mov_chunk_x = 20;
	data->mov_chunk_y = 20;
	data->chunk_v_x = 20;
	data->chunk_v_y = 20;
	data->switcher = 1;
	data->wave = 0;
	find_first_border(data);
	data->collectibles = 0;
	set_input(data);
	set_window_size(data);
	data->collectibles_left = data->collectibles;
}
