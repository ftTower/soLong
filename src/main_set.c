/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:46:08 by tauer             #+#    #+#             */
/*   Updated: 2024/03/16 18:32:33 by tauer            ###   ########.fr       */
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

bool	data_maker(t_data *data)
{
	data->life_ennemy = 100;
	data->shocking_win = 0;
	data->mov_status = 1;
	data->switcher = 0;
	data->base_image = new_img(data->win_x, data->win_y, data); //! malloc
	if (!data->base_image.img)
		return (free_map(data->map), mlx_destroy_window(data->mlx, data->win),
			mlx_destroy_display(data->mlx), free(data->mlx), false);
	if (!init_garbage_memory(data)) //! malloc
		close_win(data);
	textures_loader(data); //! malloc
	custom_indoor_map(data);
	return (true);
}

bool	settings(t_data *data)
{
	data->mlx = mlx_init(); //! malloc
	if (!data->mlx)
		return (free_map(data->map), false);
	data->win = mlx_new_window(data->mlx, data->win_x, data->win_y,
			"soooooLong");
	if (!data->win)
		return (free_map(data->map), mlx_destroy_display(data->mlx),
			free(data->mlx), false);
	data_maker(data);
	return (true);
}

bool	pre_settings(t_data *data)
{
	data->map = get_map(data->map_path); //! malloc
	if (!data->map)
		return (true);
	data->selecter_custom = 0;
	data->time_render = gettime();
	data->time_perso = gettime();
	data->time_capsule = gettime();
	data->time_ennemy = gettime();
	data->time_start = gettime();
	data->move = 0;
	data->mov_chunk_x = 20;
	data->mov_chunk_y = 20;
	data->chunk_v_x = 20;
	data->chunk_v_y = 20;
	data->switcher = 1;
	data->wave = 0;
	data->collectibles = 0;
	set_key_false(data);
	find_first_border(data);
	set_input(data);
	data->collectibles_left = data->collectibles;
	set_window_size(data);
	return (false);
}
