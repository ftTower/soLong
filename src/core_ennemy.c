/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_ennemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:51:06 by tauer             #+#    #+#             */
/*   Updated: 2024/03/20 15:33:20 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

bool	diago(t_data *data)
{
	if (data->x < data->v_x && data->y < data->v_y)
		return (v_nor_we(data), false);
	if (data->x < data->v_x && data->y > data->v_y)
		return (v_nor_ea(data), false);
	if (data->x > data->v_x && data->y < data->v_y)
		return (v_south_we(data), false);
	if (data->x > data->v_x && data->y > data->v_y)
		return (v_south_ea(data), false);
	return (true);
}

bool	cote_with_goal(t_data *data)
{
	if (data->x < data->v_x)
		return (v_north(data));
	else if (data->x > data->v_x)
		return (v_south(data));
	else if (data->y < data->v_y)
		return (v_west(data));
	else if (data->y > data->v_y)
		return (v_east(data));
	return (true);
}

void	cote_without_goal(t_data *data)
{
	if (v_north(data))
		if (v_south(data))
			if (v_east(data))
				v_west(data);
}

void	ennemy_decisition(t_data *data)
{
	if (data->life_ennemy > 0 && data->wave > 0)
		if (diago(data))
			if (cote_with_goal(data))
				(cote_without_goal(data));
}
