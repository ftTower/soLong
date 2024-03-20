/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:46:08 by tauer             #+#    #+#             */
/*   Updated: 2024/03/20 15:56:19 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

bool	set_map_size(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (!data->map)
		return (true);
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
			y++;
		x++;
	}
	if (x < 1 && y < 1)
		return (free_map(data->map), true);
	data->size_y = y - 1;
	data->size_x = x - 1;
	return (print_simple_line(), ft_printf("❌ check map size\n"),
		put_error_msg("ERROR"), false);
}

void	update_input(t_data *data, int x, int y)
{
	if (data->map[x][y] == 'C')
		data->collectibles++;
	else if (data->map[x][y] == 'P')
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
}

void	set_input(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
			update_input(data, x, y++);
		x++;
	}
	return ;
}

void	set_window_size(t_data *data)
{
	data->win_y = (data->size_x + 1) * 50;
	data->win_x = (data->size_y + 1) * 50;
	if (data->win_x > 1080 || data->win_y > 1920)
	{
		write(1, "[BAD MAP SIZE]\n\n", 17);
		ft_printf("your map size [x:%d][y:%d]\n", data->size_x, data->size_y);
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
	data->base_image = new_img(data->win_x, data->win_y, data);
	if (!data->base_image.img)
		return (free_map(data->map), mlx_destroy_window(data->mlx, data->win),
			mlx_destroy_display(data->mlx), free(data->mlx), false);
	if (!init_garbage_memory(data))
		close_win(data);
	textures_loader(data);
	custom_indoor_map(data);
	return (true);
}
