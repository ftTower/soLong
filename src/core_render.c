/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:27:02 by tauer             #+#    #+#             */
/*   Updated: 2024/03/19 15:08:24 by tauer            ###   ########.fr       */
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

void	check_function(t_data *data, int mode, int x, int y)
{
	if (mode > 0)
		put_img_to_img(data->base_image, data->textures.floor, x * 50, y * 50);
	else
		put_img_to_img(data->base_image, data->textures.empty, x * 50, y * 50);
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

void	choose_toward_wall(t_data *data, int x, int y) //!size
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
	//render_terminal(data);
}
