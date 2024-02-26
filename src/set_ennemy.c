/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ennemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:28:50 by tauer             #+#    #+#             */
/*   Updated: 2024/01/27 14:40:55 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	place_ennemy(t_data *data)
{
	int	x;
	int	y;

	x = rand() % data->size_x + 1;
	y = rand() % data->size_y + 1;
	if (data->map[x][y] == '0')
	{
		data->map[x][y] = 'V';
		data->v_x = x;
		data->v_y = y;
		return ;
	}
	else
	{
		place_ennemy(data);
	}
}
