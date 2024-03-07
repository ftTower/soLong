/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_animations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:29:46 by tauer             #+#    #+#             */
/*   Updated: 2024/03/07 18:34:06 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	link_exit(t_data *data)
{
	data->textures.exit_1.next = &data->textures.exit_2;
	data->textures.exit_2.next = &data->textures.exit_3;
	data->textures.exit_3.next = &data->textures.exit_4;
	data->textures.exit_4.next = &data->textures.exit_5;
	data->textures.exit_5.next = &data->textures.exit_6;
	data->textures.exit_6.next = &data->textures.exit_7;
	data->textures.exit_7.next = &data->textures.exit_8;
	data->textures.exit_8.next = &data->textures.exit_9;
	data->textures.exit_9.next = &data->textures.exit_10;
	data->textures.exit_10.next = &data->textures.exit_11;
	data->textures.exit_11.next = &data->textures.exit_12;
	data->textures.exit_12.next = &data->textures.exit_13;
	data->textures.exit_13.next = &data->textures.exit_14;
	data->textures.exit_14.next = &data->textures.exit_15;
	data->textures.exit_15.next = &data->textures.exit_16;
	data->textures.exit_16.next = &data->textures.exit_17;
	data->textures.exit_17.next = &data->textures.exit_18;
	data->textures.exit_18.next = &data->textures.exit_19;
	data->textures.exit_19.next = &data->textures.exit_18;
}
