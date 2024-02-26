/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:14:57 by tauer             #+#    #+#             */
/*   Updated: 2024/01/25 14:47:59 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

clock_t	gettime(void)
{
	return ((clock() / (CLOCKS_PER_SEC / 1000)));
}

void	delete_emptyness(t_data *data,char **map)
{
	int x;
	int y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == '0')
				data->map[x][y] = 'X';
			y++;
		}
		x++;
	}
}

