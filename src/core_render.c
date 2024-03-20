/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:27:02 by tauer             #+#    #+#             */
/*   Updated: 2024/03/20 15:38:06 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	render_perso(t_data *data, t_img base_image, t_img current_perso)
{
	put_img_to_img(base_image, current_perso, (data->x * 50) + data->mov_chunk_x
		- 50, (data->y * 50) + data->mov_chunk_y - 15);
	mlx_put_image_to_window(data->mlx, data->win, base_image.img,
		data->shocking_win, data->shocking_win);
}

void	render_ennemy(t_data *data, t_img base_image, t_img current_ennemy)
{
	put_img_to_img(base_image, current_ennemy, (data->v_x * 50)
		+ data->chunk_v_x - 40, (data->v_y * 50) + data->chunk_v_y - 15);
}

void	render(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	data->collectibles_left = 0;
	while (data->map[x] != NULL)
	{
		y = 0;
		while (data->map[x][y])
		{
			look_for_img(data, data->map[x][y], x, y);
			y++;
		}
		x++;
	}
}

void	global_render(t_data *data)
{
	render(data);
	render_perso(data, data->base_image, data->textures.current_perso);
	if (data->wave > 0 && data->life_ennemy > 0)
		render_ennemy(data, data->base_image, data->textures.current_ennemy);
	render_compteur(data);
	render_terminal(data);
}
