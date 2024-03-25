/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:28:34 by tauer             #+#    #+#             */
/*   Updated: 2024/03/22 19:29:04 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	up(t_data *data)
{
	if (check_empty(data, data->x - 1, data->y) || check_char(data, data->x - 1,
			data->y, 'E'))
	{
		data->textures.current_perso = data->textures.back_perso;
		data->move++;
		data->map[data->x][data->y] = '0';
		data->x -= 1;
		if (!check_char(data, data->x, data->y, 'E'))
			data->map[data->x][data->y] = 'P';
	}
}

void	down(t_data *data)
{
	if (check_empty(data, data->x + 1, data->y) || check_char(data, data->x + 1,
			data->y, 'E'))
	{
		data->textures.current_perso = data->textures.perso;
		data->move++;
		data->map[data->x][data->y] = '0';
		data->x += 1;
		data->map[data->x][data->y] = 'P';
	}
}

void	right(t_data *data)
{
	if (check_empty(data, data->x, data->y + 1) || check_char(data, data->x,
			data->y + 1, 'E'))
	{
		data->textures.current_perso = data->textures.right_perso;
		data->move++;
		data->map[data->x][data->y] = '0';
		data->y += 1;
		data->map[data->x][data->y] = 'P';
	}
}

void	left(t_data *data)
{
	if (check_empty(data, data->x, data->y - 1) || check_char(data, data->x,
			data->y - 1, 'E'))
	{
		data->textures.current_perso = data->textures.left_perso;
		data->move++;
		data->map[data->x][data->y] = '0';
		data->y -= 1;
		data->map[data->x][data->y] = 'P';
	}
}
