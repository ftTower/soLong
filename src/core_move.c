/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:57:35 by tauer             #+#    #+#             */
/*   Updated: 2024/03/20 15:33:49 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	move_up(t_data *data)
{
	change_map(data, north);
	data->textures.current_perso = data->textures.back_perso;
}

void	move_down(t_data *data)
{
	change_map(data, south);
	data->textures.current_perso = data->textures.running_1;
}

void	move_right(t_data *data)
{
	change_map(data, east);
	data->textures.current_perso = data->textures.right_perso;
}

void	move_left(t_data *data)
{
	change_map(data, west);
	data->textures.current_perso = data->textures.left_perso;
}
