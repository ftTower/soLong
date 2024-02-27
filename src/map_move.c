/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:51:07 by tauer             #+#    #+#             */
/*   Updated: 2024/02/20 10:19:12 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

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
		return (no_dir);
}

void	change_map(t_data *data, t_dir direction)
{
	if (data->map[data->x][data->y] == 'T')
		data->collectibles_left -= 1;
	else if (direction == no_dir)
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
}
