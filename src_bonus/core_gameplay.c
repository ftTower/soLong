/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_gameplay.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:18:23 by tauer             #+#    #+#             */
/*   Updated: 2024/03/21 14:51:22 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

void	end_wave(t_data *data)
{
	if ((data->x == data->e_x) && (data->y == data->e_y)
		&& data->collectibles_left == 0)
		reset_wave(data);
}

int	ennemy_dead(t_data *data)
{
	if (data->life_ennemy == 0)
		return (data->map[data->v_x][data->v_y] = '0', 0);
	return (1);
}

void	reset_wave(t_data *data)
{
	data->map[data->e_x][data->e_y] = 'E';
	data->textures.current_exit = data->textures.exit_1;
	data->wave++;
	data->x = data->start_x;
	data->y = data->start_y;
	data->mov_chunk_x = 20;
	data->mov_chunk_y = 20;
	if (data->wave > 1)
		data->map[data->v_x][data->v_y] = '0';
	data->life_ennemy = 100;
	place_ennemy(data);
	reset_collectibles(data);
}

void	player_death(t_data *data)
{
	if (data->wave == 1 && data->x == data->v_x && data->y == data->v_y
		&& data->life_ennemy > 0)
	{
		ft_printf("you died !\n");
		close_win(data);
	}
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
