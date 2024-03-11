/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_init_num.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:23:15 by tauer             #+#    #+#             */
/*   Updated: 2024/03/11 12:25:01 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int init_num(t_data *data)
{
	data->textures.num0 = new_file_img("./img/num/0.xpm",data);
	data->textures.num1 = new_file_img("./img/num/1.xpm",data);
	data->textures.num2 = new_file_img("./img/num/2.xpm",data);
	data->textures.num3 = new_file_img("./img/num/3.xpm",data);
	data->textures.num4 = new_file_img("./img/num/4.xpm",data);
	data->textures.num5 = new_file_img("./img/num/5.xpm",data);
	data->textures.num6 = new_file_img("./img/num/6.xpm",data);
	data->textures.num7 = new_file_img("./img/num/7.xpm",data);
	data->textures.num8 = new_file_img("./img/num/8.xpm",data);
	data->textures.num9 = new_file_img("./img/num/9.xpm",data);
	return (0);
}