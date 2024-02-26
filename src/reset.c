/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:27:16 by tauer             #+#    #+#             */
/*   Updated: 2024/01/27 03:08:01 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	reset_collectibles(t_data *data)
{
	char **dup;
	int x;
	int y;

	x = 0;
	y = 0;

	dup = get_map(data->map_path);
	//print_map2(dup);
	while(dup[x])
	{
		y = 0;
		while(dup[x][y])
		{
			if (dup[x][y] == 'T')
			{
				data->map[x][y] = 'T';
				data->collectibles_left++;	
			}
			y++;
		}
		x++;
	}
}
