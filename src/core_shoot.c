/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_shoot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:00:06 by tauer             #+#    #+#             */
/*   Updated: 2024/03/19 13:00:51 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	bullet_noso(t_data *data, int x_bul, int y_bul)
{
	if (data->mov_status == north)
	{
		while (check_empty(data, x_bul - 1, y_bul))
		{
			if (data->map[x_bul - 1][y_bul] == 'V')
				data->life_ennemy -= 50;
			x_bul--;
		}
	}
	else if (data->mov_status == south)
	{
		while (check_empty(data, x_bul + 1, y_bul))
		{
			if (data->map[x_bul + 1][y_bul] == 'V')
				data->life_ennemy -= 50;
			x_bul++;
		}
	}
}

void	bullet_eawe(t_data *data, int x_bul, int y_bul)
{
	if (data->mov_status == east)
	{
		while (check_empty(data, x_bul, y_bul + 1))
		{
			if (data->map[x_bul][y_bul + 1] == 'V')
				data->life_ennemy -= 50;
			y_bul++;
		}
	}
	else if (data->mov_status == west)
	{
		while (check_empty(data, x_bul, y_bul - 1))
		{
			if (data->map[x_bul][y_bul - 1] == 'V')
				data->life_ennemy -= 50;
			y_bul--;
		}
	}
}

void	shoot(t_data *data)
{
	int	x_bul;
	int	y_bul;

	x_bul = data->x;
	y_bul = data->y;
	bullet_noso(data, x_bul, y_bul);
	bullet_eawe(data, x_bul, y_bul);
}
