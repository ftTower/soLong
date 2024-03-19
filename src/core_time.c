/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:35:18 by tauer             #+#    #+#             */
/*   Updated: 2024/03/19 12:55:26 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	quick_loop(t_data *data)
{
	if (gettime() - data->time_render >= 16)
	{
		data->time_render = gettime();
		global_render(data);
		ennemy_decisition(data);
		ennemy_dead(data);
		quick_next(data);
		player_death(data);
		change_map(data, get_dir(data));
		data->shocking_win = 0;
	}
}

void	medium_loop(t_data *data)
{
	if (gettime() - data->time_capsule >= 200)
	{
		data->time_capsule = gettime();
		medium_next(data);
	}
}

void	slow_loop(t_data *data)
{
	if (gettime() - data->time_perso >= 250)
	{
		data->time_perso = gettime();
		slow_next(data);
	}
}


void	very_slow_loop(t_data *data)
{
	if (gettime() - data->time_ennemy >= 500)
		data->time_ennemy = gettime();
}

void	loops(t_data *data)
{
	quick_loop(data);
	medium_loop(data);
	slow_loop(data);
	very_slow_loop(data);
}
