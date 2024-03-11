/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_anim_update.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 00:11:20 by tauer             #+#    #+#             */
/*   Updated: 2024/03/11 00:11:28 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	quick_next(t_data *data)
{
	data->textures.current_screen_indoor = *data->textures.current_screen_indoor.next;
	if (data->collectibles_left == 0)
		data->textures.current_exit = *data->textures.current_exit.next;
}

void	medium_next(t_data *data)
{
	data->textures.current_capsule = *data->textures.current_capsule.next;
	data->textures.current_screen_outdoor = *data->textures.current_screen_outdoor.next;
}

void	slow_next(t_data *data)
{
	data->textures.current_perso = *data->textures.current_perso.next;
	data->textures.current_capsule = *data->textures.current_capsule.next;
}