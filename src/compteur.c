/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compteur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:11:39 by tauer             #+#    #+#             */
/*   Updated: 2024/03/11 12:54:01 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	putnbrimg(int move, int pos_y ,t_data *data)
{
	if (move > 9)
	{
		putnbrimg(move / 10,pos_y - 25, data);
		putnbrimg(move % 10,pos_y - 25, data);
	}
	
	else
	{
		if (move == 0)
			put_img_to_img(data->base_num, data->textures.num0, 25, pos_y);
	}
}

void	render_compteur(t_data *data)
{
	putnbrimg(data->move, 250, data);
	mlx_put_image_to_window(data->mlx_num, data->win_num, data->base_num.img, 0, 0);
}