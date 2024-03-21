/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:32:23 by tauer             #+#    #+#             */
/*   Updated: 2024/03/21 19:58:49 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	up(t_data *data)
{
	if (check_empty(data, data->x - 1, data->y) || check_char(data, data->x - 1,
			data->y, 'E'))
	{
		data->textures.current_perso = data->textures.back_perso;
		// if (!check_char(data, data->x - 1, data->y, 'E'))
		data->map[data->x][data->y] = '0';
		data->x -= 1;
		if (!check_char(data, data->x, data->y, 'E'))
			data->map[data->x][data->y] = 'P';
	}
}
void	down(t_data *data)
{
	if (check_empty(data, data->x + 1, data->y) || check_char(data, data->x + 1,
			data->y, 'E'))
	{
		data->textures.current_perso = data->textures.perso;
		if (!check_char(data, data->x + 1, data->y, 'E'))
			data->map[data->x][data->y] = '0';
		data->x += 1;
		data->map[data->x][data->y] = 'P';
	}
}

void	right(t_data *data)
{
	if (check_empty(data, data->x, data->y + 1) || check_char(data, data->x,
			data->y + 1, 'E'))
	{
		data->textures.current_perso = data->textures.right_perso;
		if (!check_char(data, data->x, data->y + 1, 'E'))
			data->map[data->x][data->y] = '0';
		data->y += 1;
		data->map[data->x][data->y] = 'P';
	}
}

void	left(t_data *data)
{
	if (check_empty(data, data->x, data->y - 1) || check_char(data, data->x,
			data->y - 1, 'E'))
	{
		data->textures.current_perso = data->textures.left_perso;
		if (!check_char(data, data->x, data->y - 1, 'E'))
			data->map[data->x][data->y] = '0';
		data->y -= 1;
		data->map[data->x][data->y] = 'P';
	}
}

int	true_key(int key, t_data *data)
{
	if (key == 65362)
		up(data);
	else if (key == 65364)
		down(data);
	else if (key == 65363)
		right(data);
	else if (key == 65361)
		left(data);
	else if (key == 32)
	{
		data->shocking_win = 5;
	}
	else if (key == 53 || key == 65307 || key == 96)
	{
		close_win(data);
		exit(0);
	}
	return (0);
}

void	hooking(t_data *data)
{
	mlx_hook(data->win, 17, 0L, &close_win, data);
	mlx_hook(data->win, 2, 1L << 0, &true_key, data);
	// mlx_hook(data->win, 3, 1L << 1, &false_key, data);
	mlx_loop_hook(data->mlx, looper, data);
}
