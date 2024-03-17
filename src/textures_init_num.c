/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_init_num.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:23:15 by tauer             #+#    #+#             */
/*   Updated: 2024/03/17 22:10:49 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

bool	init_num(t_data *data)
{
	ft_printf("=========================================================================================\n| NUMBER_TEXTURES\n=========================================================================================\n");
	add_img_to_garbage_memory(data, &data->textures.num0,
		"num_0\t\t      :./img/num/0.xpm:N0");
	add_img_to_garbage_memory(data, &data->textures.num1,
		"num_1\t\t      :./img/num/1.xpm:N1");
	add_img_to_garbage_memory(data, &data->textures.num2,
		"num_2\t\t      :./img/num/2.xpm:N2");
	add_img_to_garbage_memory(data, &data->textures.num3,
		"num_3\t\t      :./img/num/3.xpm:N3");
	add_img_to_garbage_memory(data, &data->textures.num4,
		"num_4\t\t      :./img/num/4.xpm:N4");
	add_img_to_garbage_memory(data, &data->textures.num5,
		"num_5\t\t      :./img/num/5.xpm:N5");
	add_img_to_garbage_memory(data, &data->textures.num6,
		"num_6\t\t      :./img/num/6.xpm:N6");
	add_img_to_garbage_memory(data, &data->textures.num7,
		"num_7\t\t      :./img/num/7.xpm:N7");
	add_img_to_garbage_memory(data, &data->textures.num8,
		"num_8\t\t      :./img/num/8.xpm:N8");
	add_img_to_garbage_memory(data, &data->textures.num9,
		"num_9\t\t      :./img/num/9.xpm:N9");
	if (!data->textures.num0.img || !data->textures.num1.img
		|| !data->textures.num2.img || !data->textures.num3.img
		|| !data->textures.num4.img || !data->textures.num5.img
		|| !data->textures.num6.img || !data->textures.num7.img
		|| !data->textures.num8.img || !data->textures.num9.img)
		return (false);
	return (true);
}
