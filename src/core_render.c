/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:27:02 by tauer             #+#    #+#             */
/*   Updated: 2024/03/16 09:30:20 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void render_perso(t_data *data, t_img base_image, t_img current_perso)
{
	put_img_to_img(base_image, current_perso, (data->x * 50) + data->mov_chunk_x - 50, (data->y * 50) + data->mov_chunk_y - 15);
	mlx_put_image_to_window(data->mlx, data->win, base_image.img,
							data->shocking_win, data->shocking_win);
}

void render_ennemy(t_data *data, t_img base_image, t_img current_ennemy)
{
	put_img_to_img(base_image, current_ennemy, (data->v_x * 50) + data->chunk_v_x - 40, (data->v_y * 50) + data->chunk_v_y - 15);
}

void render_custom_wall(t_data *data, int x, int y, int x_pos, int y_pos)
{
	if (data->selecter_custom > 4)
		data->selecter_custom = 0;
	if (data->selecter_custom == 0 && check_empty(data, x + 1, y))
		put_img_to_img(data->base_image, data->textures.wall_screen_indoor,
					   x_pos, y_pos);
	else if (data->selecter_custom == 1 && check_empty(data, x + 1, y))
		put_img_to_img(data->base_image, data->textures.panel_wall, x_pos,
					   y_pos);
	else if (data->selecter_custom == 2 && check_void(data, x + 1, y))
		put_img_to_img(data->base_image, data->textures.wall_screen_outdoor,
					   x_pos, y_pos);
	else if (data->selecter_custom == 3 && check_void(data, x + 1, y) && check_empty(data, x - 1, y))
		put_img_to_img(data->base_image, data->textures.private_door, x_pos,
					   y_pos);
	else if (data->selecter_custom == 4 && check_void(data, x + 1, y) && check_empty(data, x - 1, y))
		put_img_to_img(data->base_image, data->textures.wall_screen, x_pos,
					   y_pos);
	else
		put_img_to_img(data->base_image, data->textures.wall, x_pos, y_pos);
	data->selecter_custom++;
}

bool if_forest_1(t_data *data, int x, int y)
{
	if (data->map[x][y] == 'X')
	{
		put_img_to_img(data->base_image, data->textures.empty, x * 50,
					   y * 50);
		return (true);
	}
	else if (data->map[x][y] == 'V')
	{
		put_img_to_img(data->base_image, data->textures.floor,
					   x * 50, y * 50);
		return (true);
	}
	else if (data->map[x][y] == 'r')
	{
		put_img_to_img(data->base_image, data->textures.wall_screen,
					   x * 50, y * 50);
		return (true);
	}
	else if (data->map[x][y] == 's')
	{
		put_img_to_img(data->base_image, data->textures.private_door,
					   x * 50, y * 50);
		return (true);
	}
	return (false);
}

bool if_forest_2(t_data *data, int x, int y)
{
	if (data->map[x][y] == 't')
	{
		put_img_to_img(data->base_image,
					   data->textures.current_screen_outdoor, x * 50, y * 50);
		return (true);
	}
	else if (data->map[x][y] == 'x')
	{
		put_img_to_img(data->base_image, data->textures.panel_wall, x * 50, y * 50);
		return (true);
	}
	else if (data->map[x][y] == 'y')
	{
		put_img_to_img(data->base_image,
					   data->textures.current_screen_indoor, x * 50, y * 50);
		return (true);
	}
	return (false);
}

bool if_forest_3(t_data *data, int x, int y)
{
			if (data->map[x][y] == 'D')
			{
				put_img_to_img(data->base_image, data->textures.floor_ventil,
							   x * 50, y * 50);
				put_img_to_img(data->base_image, data->textures.current_capsule,
							   (x * 50) - 50, y * 50);
			}
			else if (data->map[x][y] == 'q')
			{
				if (check_empty(data, x, y + 1) || check_walls(data, x, y + 1))
					put_img_to_img(data->base_image, data->textures.floor,
								   x * 50, y * 50);
				else
					put_img_to_img(data->base_image, data->textures.empty,
								   x * 50, y * 50);
				put_img_to_img(data->base_image,
							   data->textures.right_top_corner_up, x * 50, y * 50);
			}
	return (false);
}

void render(t_data *data)
{
	int y;
	int x;
	int y_pos;
	int x_pos;

	y = 0;
	y_pos = 0;
	x = 0;
	x_pos = 0;
	data->collectibles_left = 0;
	while (data->map[x] != NULL)
	{
		y = 0;
		y_pos = 0;
		while (data->map[x][y])
		{
			if_forest_1(data, x, y);
			if_forest_2(data, x, y);
			if_forest_3(data, x, y);
			if (data->map[x][y] == 'p')
			{
				if (check_empty(data, x, y - 1) || check_walls(data, x, y - 1))
					put_img_to_img(data->base_image, data->textures.floor,
								   x_pos, y_pos);
				else
					put_img_to_img(data->base_image, data->textures.empty,
								   x_pos, y_pos);
				put_img_to_img(data->base_image,
							   data->textures.left_top_corner_up, x_pos, y_pos);
			}
			else if (data->map[x][y] == 'o')
			{
				if (check_walls(data, x, y + 1) || check_empty(data, x, y + 1))
					put_img_to_img(data->base_image, data->textures.floor,
								   x_pos, y_pos);
				else
					put_img_to_img(data->base_image, data->textures.empty,
								   x_pos, y_pos);
				put_img_to_img(data->base_image,
							   data->textures.right_top_corner, x_pos, y_pos);
			}
			else if (data->map[x][y] == 'n')
			{
				if (check_empty(data, x, y + 1) && check_empty(data, x, y - 1))
				{
					put_img_to_img(data->base_image, data->textures.floor,
								   x_pos, y_pos);
					put_img_to_img(data->base_image, data->textures.toward_wall,
								   x_pos, y_pos);
				}
				else if (check_empty(data, x, y + 1) == 0 && check_empty(data,
																		 x, y - 1) == 0)
				{
					put_img_to_img(data->base_image, data->textures.empty,
								   x_pos, y_pos);
					put_img_to_img(data->base_image, data->textures.toward_wall,
								   x_pos, y_pos);
				}
				else if (check_empty(data, x, y + 1))
				{
					put_img_to_img(data->base_image, data->textures.empty,
								   x_pos, y_pos);
					put_img_to_img(data->base_image,
								   data->textures.toward_wall_left_empty, x_pos, y_pos);
				}
				else
				{
					put_img_to_img(data->base_image, data->textures.empty,
								   x_pos, y_pos);
					put_img_to_img(data->base_image,
								   data->textures.toward_wall_right_empty, x_pos, y_pos);
				}
			}
			else if (data->map[x][y] == 'm')
			{
				if (check_walls(data, x, y + 1) || check_empty(data, x, y + 1))
					put_img_to_img(data->base_image, data->textures.floor,
								   x_pos, y_pos);
				else
					put_img_to_img(data->base_image, data->textures.empty,
								   x_pos, y_pos);
				put_img_to_img(data->base_image, data->textures.right_corner,
							   x_pos, y_pos);
			}
			else if (data->map[x][y] == 'j')
			{
				if (check_walls(data, x, y - 1) || check_empty(data, x, y - 1))
					put_img_to_img(data->base_image, data->textures.floor,
								   x_pos, y_pos);
				else
					put_img_to_img(data->base_image, data->textures.empty,
								   x_pos, y_pos);
				put_img_to_img(data->base_image, data->textures.left_top_corner,
							   x_pos, y_pos);
			}
			else if (data->map[x][y] == 'l')
			{
				if (check_walls(data, x, y - 1) || check_empty(data, x, y - 1))
					put_img_to_img(data->base_image, data->textures.floor,
								   x_pos, y_pos);
				else
					put_img_to_img(data->base_image, data->textures.empty,
								   x_pos, y_pos);
				put_img_to_img(data->base_image, data->textures.left_corner,
							   x_pos, y_pos);
			}
			else if (data->map[x][y] == 'h')
				put_img_to_img(data->base_image, data->textures.right_empty,
							   x_pos, y_pos);
			else if (data->map[x][y] == 'g')
			{
				put_img_to_img(data->base_image, data->textures.floor, x_pos,
							   y_pos);
				put_img_to_img(data->base_image, data->textures.left_empty,
							   x_pos, y_pos);
			}
			else if (data->map[x][y] == 'f')
				put_img_to_img(data->base_image, data->textures.wall_up, x_pos,
							   y_pos);
			else if (data->map[x][y] == 'e')
				put_img_to_img(data->base_image, data->textures.wall_4, x_pos,
							   y_pos);
			else if (data->map[x][y] == 'c')
			{
				if (check_walls(data, x + 1, y) || check_empty(data, x + 1, y))
					put_img_to_img(data->base_image, data->textures.floor,
								   x_pos, y_pos);
				else
					put_img_to_img(data->base_image, data->textures.empty,
								   x_pos, y_pos);
				put_img_to_img(data->base_image, data->textures.wall_down_empty,
							   x_pos, y_pos);
			}
			else if (data->map[x][y] == 'd')
			{
				put_img_to_img(data->base_image, data->textures.floor, x_pos,
							   y_pos);
				put_img_to_img(data->base_image, data->textures.wall_down,
							   x_pos, y_pos);
			}
			else if (data->map[x][y] == 'b')
			{
				put_img_to_img(data->base_image, data->textures.floor, x_pos,
							   y_pos);
				put_img_to_img(data->base_image, data->textures.down, x_pos,
							   y_pos);
			}
			else if (data->map[x][y] == 'E' && data->collectibles_left == 0)
			{
				put_img_to_img(data->base_image, data->textures.floor, x_pos,
							   y_pos);
				put_img_to_img(data->base_image, data->textures.current_exit,
							   x_pos, y_pos);
			}
			else if (data->map[x][y] == 'E')
				put_img_to_img(data->base_image, data->textures.current_exit,
							   x_pos, y_pos);
			else if (data->map[x][y] == '1')
			{
				put_img_to_img(data->base_image, data->textures.wall, x_pos,
							   y_pos);
			}
			else if (data->map[x][y] == '0' || data->map[x][y] == 'C')
				put_img_to_img(data->base_image, data->textures.floor, x_pos,
							   y_pos);
			else if (data->map[x][y] == 'T')
			{
				data->collectibles_left++;
				put_img_to_img(data->base_image, data->textures.floor, x_pos,
							   y_pos);
				put_img_to_img(data->base_image, data->textures.collectibles,
							   x_pos, y_pos);
			}
			y_pos += 50;
			y++;
		}
		x_pos += 50;
		x++;
	}
}

void global_render(t_data *data)
{
	render(data);
	render_perso(data, data->base_image, data->textures.current_perso);
	render_compteur(data);
	render_terminal(data);
	if (data->wave > 0 && data->life_ennemy > 0)
		render_ennemy(data, data->base_image, data->textures.current_ennemy);
}
