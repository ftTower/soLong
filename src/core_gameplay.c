/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_gameplay.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:18:23 by tauer             #+#    #+#             */
/*   Updated: 2024/03/21 19:59:52 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	end_wave(t_data *data)
{
	if ((data->x == data->e_x) && (data->y == data->e_y)
		&& data->collectibles_left == 0)
		reset_wave(data);
}

void	reset_wave(t_data *data)
{
	data->textures.current_perso = data->textures.perso;
	data->map[data->e_x][data->e_y] = 'E';
	data->wave++;
	data->x = data->start_x;
	data->y = data->start_y;
	data->map[data->x][data->y] = 'P';
	data->mov_chunk_x = 20;
	data->mov_chunk_y = 20;
	reset_collectibles(data);
}

void	reset_collectibles(t_data *data)
{
	char	**dup;
	int		x;
	int		y;

	x = 0;
	y = 0;
	dup = get_map(data->map_path);
	if (!dup)
		return ;
	while (dup[x])
	{
		y = 0;
		while (dup[x][y])
		{
			if (dup[x][y] == 'C')
			{
				data->map[x][y] = 'C';
				data->collectibles_left++;
			}
			y++;
		}
		x++;
	}
	free_map(dup);
}
