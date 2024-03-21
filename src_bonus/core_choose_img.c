/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_choose_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:34:06 by tauer             #+#    #+#             */
/*   Updated: 2024/03/21 14:51:13 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

bool	choose_img(t_data *data, int x, int y, t_memory *current)
{
	if (current->id[0] && current->id[1])
	{
		choice_for_id_0(data, x, y, current);
		choice_for_id_1(data, x, y, current);
		return (true);
	}
	return (false);
}

void	choice_for_id_0(t_data *data, int x, int y, t_memory *current)
{
	if (current->id[0] == '<')
		check_function(data, check_empty(data, x, y - 1) + check_walls(data, x,
				y - 1), x, y);
	else if (current->id[0] == '>')
		check_function(data, check_empty(data, x, y + 1) + check_walls(data, x,
				y + 1), x, y);
	else if (current->id[0] == '^')
		check_function(data, check_empty(data, x + 1, y) + check_walls(data, x
				+ 1, y), x, y);
	else if (current->id[0] == 'X')
		put_img_to_img(data->base_image, data->textures.empty, x * 50, y * 50);
	else if (current->id[0] == 'V')
		put_img_to_img(data->base_image, data->textures.floor, x * 50, y * 50);
	else if (current->id[0] == 'Y')
		put_img_to_img(data->base_image, data->textures.floor_ventil, x * 50, y
			* 50);
}

void	choice_for_id_1(t_data *data, int x, int y, t_memory *current)
{
	if (current->id[1] == 'D')
		put_img_to_img(data->base_image, data->textures.current_capsule, x * 50
			- 50, y * 50);
	else if (current->id[1] == 't')
		put_img_to_img(data->base_image, data->textures.current_screen_outdoor,
			x * 50, y * 50);
	else if (current->id[1] == 'y')
		put_img_to_img(data->base_image, data->textures.current_screen_indoor, x
			* 50, y * 50);
	else if (current->id[1] == 'E')
		put_img_to_img(data->base_image, data->textures.current_exit, x * 50, y
			* 50);
	else if (current->id[1] == 'n')
		choose_toward_wall(data, x, y);
	else
		put_img_to_img(data->base_image, *(current)->img, x * 50, y * 50);
}

void	check_function(t_data *data, int mode, int x, int y)
{
	if (mode > 0)
		put_img_to_img(data->base_image, data->textures.floor, x * 50, y * 50);
	else
		put_img_to_img(data->base_image, data->textures.empty, x * 50, y * 50);
}

void	look_for_img(t_data *data, char c, int x, int y)
{
	t_memory	*current;

	current = data->memory;
	if (current && (c == '0' || c == 'P' || c == 'V' || c == 'X' || c == 'C'))
	{
		if (c == 'C')
			data->collectibles_left++;
		if (c != 'X')
			put_img_to_img(data->base_image, data->textures.floor, x * 50, y
				* 50);
		else if (c == 'P')
			return ;
		else
			put_img_to_img(data->base_image, data->textures.empty, x * 50, y
				* 50);
	}
	while (current)
	{
		if (current->id[0] != 'N' && current->id[1] == c
			&& current->id[1] != 'P' && choose_img(data, x, y, current))
			return ;
		current = current->next;
	}
	return ;
}
