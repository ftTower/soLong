/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:32:23 by tauer             #+#    #+#             */
/*   Updated: 2024/02/20 10:13:00 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	true_key(int key, t_data *data)
{
	if (key == 65362)
		data->key.up_key = true;
	else if (key == 65364)
		data->key.down_key = true;
	else if (key == 65363)
		data->key.right_key = true;
	else if (key == 65361)
		data->key.left_key = true;
	else if (key == 32)
	{
		data->shocking_win = 5;
		shoot(data);
	}
	else if (key == 53 || key == 65307 || key == 96)
	{
		close_win(data);
		exit(0);
	}
	return (0);
}

int	false_key(int key, t_data *data)
{
	if (key == 65362)
		data->key.up_key = false;
	else if (key == 65364)
		data->key.down_key = false;
	else if (key == 65363)
		data->key.right_key = false;
	else if (key == 65361)
		data->key.left_key = false;
	return (0);
}

void	hooking(t_data *data)
{
	mlx_hook(data->win, 17, 0L, &close_win, data);
	mlx_hook(data->win, 2, 1L << 0, &true_key, data);
	mlx_hook(data->win, 3, 1L << 1, &false_key, data);
	mlx_loop_hook(data->mlx, looper, data);
}
