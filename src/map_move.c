/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:51:07 by tauer             #+#    #+#             */
/*   Updated: 2024/02/19 19:57:53 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	f_north(t_data *data)
{
	if (data->mov_chunk_x > 0)
		data->mov_chunk_x -= 5;
	if (data->mov_chunk_x == 0 && check_next(data, data->x - 1, data->y))
	{
		data->map[data->x][data->y] = '0';
		data->mov_chunk_x = 50;
		data->x -= 1;
		data->map[data->x][data->y] = 'C';
		data->move += 1;
	}
	data->mov_status = 0;
	data->textures.current_perso = data->textures.back_perso;
	//	printf("up status\n");
}

void	f_south(t_data *data)
{
	if (data->mov_chunk_x < 50)
		data->mov_chunk_x += 5;
	if (data->mov_chunk_x == 50 && check_next(data, data->x + 1, data->y))
	{
		data->map[data->x][data->y] = '0';
		data->mov_chunk_x = 0;
		data->x += 1;
		data->map[data->x][data->y] = 'C';
		data->move += 1;
	}
	data->mov_status = 1;
	data->textures.current_perso = data->textures.running_1;
	//	printf("down status\n");
}
void	f_east(t_data *data)
{
	if (data->mov_chunk_y < 50)
		data->mov_chunk_y += 5;
	if (data->mov_chunk_y == 50 && check_next(data, data->x, data->y + 1))
	{
		data->map[data->x][data->y] = '0';
		data->mov_chunk_y = 0;
		data->y += 1;
		data->map[data->x][data->y] = 'C';
		data->move += 1;
	}
	data->mov_status = 2;
	data->textures.current_perso = data->textures.right_perso;
	// printf("right status\n");
}
void	f_west(t_data *data)
{
	if (data->mov_chunk_y > 0)
		data->mov_chunk_y -= 5;
	if (data->mov_chunk_y == 0 && check_next(data, data->x, data->y - 1))
	{
		data->map[data->x][data->y] = '0';
		data->mov_chunk_y = 50;
		data->y -= 1;
		data->map[data->x][data->y] = 'C';
		data->move += 1;
	}
	data->mov_status = 3;
	data->textures.current_perso = data->textures.left_perso;
	// printf("left status\n");
}

void	f_nor_we(t_data *data)
{
	if (data->mov_chunk_x > 0)
		data->mov_chunk_x -= 5;
	if (data->mov_chunk_y > 0)
		data->mov_chunk_y -= 5;
	if (data->mov_chunk_y == 0 && check_next(data, data->x, data->y - 1))
	{
		data->map[data->x][data->y] = '0';
		data->mov_chunk_y = 50;
		data->y -= 1;
		data->map[data->x][data->y] = 'C';
		data->move += 1;
	}
	if (data->mov_chunk_x == 0 && check_next(data, data->x - 1, data->y))
	{
		data->map[data->x][data->y] = '0';
		data->mov_chunk_x = 50;
		data->x -= 1;
		data->map[data->x][data->y] = 'C';
		data->move += 1;
	}
}

void	f_nor_ea(t_data *data)
{
	if (data->mov_chunk_x > 0)
		data->mov_chunk_x -= 5;
	if (data->mov_chunk_y < 50)
		data->mov_chunk_y += 5;
	if (data->mov_chunk_y == 50 && check_next(data, data->x, data->y + 1))
	{
		data->map[data->x][data->y] = '0';
		data->mov_chunk_y = 0;
		data->y += 1;
		data->map[data->x][data->y] = 'C';
		data->move += 1;
	}
	if (data->mov_chunk_x == 0 && check_next(data, data->x - 1, data->y))
	{
		data->map[data->x][data->y] = '0';
		data->mov_chunk_x = 50;
		data->x -= 1;
		data->map[data->x][data->y] = 'C';
		data->move += 1;
	}
}

void	f_sou_we(t_data *data)
{
	if (data->mov_chunk_x < 50)
		data->mov_chunk_x += 5;
	if (data->mov_chunk_y > 0)
		data->mov_chunk_y -= 5;
	if (data->mov_chunk_y == 0 && check_next(data, data->x, data->y - 1))
	{
		data->map[data->x][data->y] = '0';
		data->mov_chunk_y = 50;
		data->y -= 1;
		data->map[data->x][data->y] = 'C';
		data->move += 1;
	}
	if (data->mov_chunk_x == 50 && check_next(data, data->x + 1, data->y))
	{
		data->map[data->x][data->y] = '0';
		data->mov_chunk_x = 0;
		data->x += 1;
		data->map[data->x][data->y] = 'C';
		data->move += 1;
	}
}

void	f_sou_ea(t_data *data)
{
	if (data->mov_chunk_x < 50)
		data->mov_chunk_x += 5;
	if (data->mov_chunk_y < 50)
		data->mov_chunk_y += 5;
	if (data->mov_chunk_y == 50 && check_next(data, data->x, data->y + 1))
	{
		data->map[data->x][data->y] = '0';
		data->mov_chunk_y = 0;
		data->y += 1;
		data->map[data->x][data->y] = 'C';
		data->move += 1;
	}
	if (data->mov_chunk_x == 50 && check_next(data, data->x + 1, data->y))
	{
		data->map[data->x][data->y] = '0';
		data->mov_chunk_x = 0;
		data->x += 1;
		data->map[data->x][data->y] = 'C';
		data->move += 1;
	}
}

t_dir	get_dir(t_data *data)
{
	if (data->key.up_key == true && data->key.left_key == true)
		return (nor_we);
	if (data->key.up_key == true && data->key.right_key == true)
		return (nor_ea);
	if (data->key.down_key == true && data->key.left_key == true)
		return (sou_we);
	if (data->key.down_key == true && data->key.right_key == true)
		return (sou_ea);
	if (data->key.up_key == true)
		return (north);
	if (data->key.down_key == true)
		return (south);
	if (data->key.left_key == true)
		return (west);
	if (data->key.right_key == true)
		return (east);
	else
		return (-1);
}

void	change_map(t_data *data, t_dir direction)
{
	if (direction == -1)
	{
		data->map[(data->x)][(data->y)] = 'C';
		return ;
	}
	else if (direction == north)
		f_north(data);
	else if (direction == south)
		f_south(data);
	else if (direction == east)
		f_east(data);
	else if (direction == west)
		f_west(data);
	else if (direction == nor_we)
		f_nor_we(data);
	else if (direction == nor_ea)
		f_nor_ea(data);
	else if (direction == sou_we)
		f_sou_we(data);
	else if (direction == sou_ea)
		f_sou_ea(data);
	if (data->map[data->x][data->y] == 'T')
	{
		data->collectibles_left -= 1;
	}
}
