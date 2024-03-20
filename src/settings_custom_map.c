/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_custom_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 00:40:05 by tauer             #+#    #+#             */
/*   Updated: 2024/03/21 00:50:35 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	custom_indoor_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x <= data->size_x)
	{
		y = 0;
		while (y <= data->size_y)
		{
			if (data->map[x][y] == 'E')
			{
				data->e_x = x;
				data->e_y = y;
			}
			else if (data->map[x][y] == 'D')
				data->map[x][y] = 'D';
			else if (tri_four_wall(data, x, y))
			{}
			else if (one_two_wall(data, x, y))
			{}
			y++;
		}
		x++;
	}
}
