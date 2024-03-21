/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_wall_connections.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:19:27 by tauer             #+#    #+#             */
/*   Updated: 2024/03/21 14:53:52 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

void	choose_left_right_wall(t_data *data, int x, int y)
{
	if (check_walls(data, x, y + 1) && check_walls(data, x, y - 1))
		put_img_to_img(data->base_image, data->textures.down, x * 50, y * 50);
	if ((check_empty(data, x, y + 1) || check_walls(data, x, y + 1)
			|| check_char(data, x, y + 1, 'D')) && (!check_empty(data, x, y - 1)
			|| !check_walls(data, x, y - 1)))
	{
		put_img_to_img(data->base_image, data->textures.empty, x * 50, y * 50);
		put_img_to_img(data->base_image, data->textures.toward_wall_left_empty,
			x * 50, y * 50);
	}
	if ((check_empty(data, x, y - 1) || check_walls(data, x, y - 1)
			|| check_char(data, x, y - 1, 'D')) && (!check_empty(data, x, y + 1)
			|| !check_walls(data, x, y + 1)))
	{
		put_img_to_img(data->base_image, data->textures.empty, x * 50, y * 50);
		put_img_to_img(data->base_image, data->textures.toward_wall_right_empty,
			x * 50, y * 50);
	}
}

void	choose_toward_wall(t_data *data, int x, int y)
{
	choose_left_right_wall(data, x, y);
	if (check_char(data, x, y + 1, 'X') && check_char(data, x, y - 1, 'X'))
	{
		put_img_to_img(data->base_image, data->textures.empty, x * 50, y * 50);
		put_img_to_img(data->base_image, data->textures.toward_wall, x * 50, y
			* 50);
	}
	if ((check_empty(data, x, y + 1) || check_walls(data, x, y + 1))
		&& ((check_empty(data, x, y - 1)) || check_walls(data, x, y - 1)))
	{
		put_img_to_img(data->base_image, data->textures.floor, x * 50, y * 50);
		put_img_to_img(data->base_image, data->textures.toward_wall, x * 50, y
			* 50);
	}
}

bool	select_custom_wall(t_data *data, int x, int y)
{
	if (check_walls(data, x, y) && check_walls(data, x, y - 1)
		&& check_walls(data, x, y + 1))
	{
		if (data->selecter_custom > 4)
			data->selecter_custom = 0;
		if (data->selecter_custom == 0 && check_empty(data, x + 1, y))
			data->map[x][y] = 'y';
		else if (data->selecter_custom == 1 && check_empty(data, x + 1, y))
			data->map[x][y] = 'x';
		else if (data->selecter_custom == 2 && (check_void(data, x + 1, y)
				|| x == data->size_x))
			data->map[x][y] = 't';
		else if (data->selecter_custom == 3 && ((check_void(data, x + 1, y)
					&& check_empty(data, x - 1, y)) || x == data->size_x))
			data->map[x][y] = 's';
		else if (data->selecter_custom == 4 && (check_void(data, x + 1, y)
				|| x == data->size_x))
			data->map[x][y] = 'r';
		else
			data->map[x][y] = '1';
		data->selecter_custom++;
		return (true);
	}
	return (false);
}

bool	tri_four_wall(t_data *data, int x, int y)
{
	if (check_walls(data, x, y) && check_walls(data, x + 1, y)
		&& check_walls(data, x - 1, y) && check_walls(data, x, y - 1)
		&& check_walls(data, x, y + 1))
		return (data->map[x][y] = 'e', true);
	else if (check_walls(data, x, y) && check_walls(data, x - 1, y)
		&& check_walls(data, x, y - 1) && check_walls(data, x, y + 1))
		return (data->map[x][y] = 'f', true);
	else if (check_walls(data, x, y) && check_walls(data, x + 1, y)
		&& check_walls(data, x, y - 1) && check_walls(data, x, y + 1))
		return (data->map[x][y] = 'b', true);
	else if (check_walls(data, x, y) && check_walls(data, x + 1, y)
		&& check_walls(data, x - 1, y) && check_walls(data, x, y + 1))
		return (data->map[x][y] = 'p', true);
	else if (check_walls(data, x, y) && check_walls(data, x + 1, y)
		&& check_walls(data, x - 1, y) && check_walls(data, x, y - 1))
		return (data->map[x][y] = 'q', true);
	else if (select_custom_wall(data, x, y))
		return (true);
	return (false);
}

bool	one_two_wall(t_data *data, int x, int y)
{
	if (check_walls(data, x, y) && check_walls(data, x - 1, y)
		&& check_walls(data, x, y + 1))
		return (data->map[x][y] = 'l', true);
	else if (check_walls(data, x, y) && check_walls(data, x - 1, y)
		&& check_walls(data, x, y - 1))
		return (data->map[x][y] = 'm', true);
	else if (check_walls(data, x, y) && check_walls(data, x + 1, y)
		&& check_walls(data, x, y + 1))
		return (data->map[x][y] = 'j', true);
	else if (check_walls(data, x, y) && check_walls(data, x - 1, y)
		&& check_walls(data, x + 1, y))
		return (data->map[x][y] = 'n', true);
	else if (check_walls(data, x, y) && check_walls(data, x + 1, y)
		&& check_walls(data, x, y - 1))
		return (data->map[x][y] = 'o', true);
	else if (check_walls(data, x, y) && check_walls(data, x - 1, y))
		return (data->map[x][y] = 'c', true);
	else if (check_walls(data, x, y) && check_walls(data, x + 1, y))
		return (data->map[x][y] = 'd', true);
	else if (check_walls(data, x, y) && check_walls(data, x, y + 1))
		return (data->map[x][y] = 'g', true);
	else if (check_walls(data, x, y) && check_walls(data, x, y - 1))
		return (data->map[x][y] = 'h', true);
	return (false);
}
