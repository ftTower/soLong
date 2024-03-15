/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:20:10 by tauer             #+#    #+#             */
/*   Updated: 2024/03/15 19:22:49 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	destroy_img(t_data *data)
{
	mlx_destroy_image(data->mlx, data->base_image.img);
}

int	close_win(t_data *data)
{
	free_map(data->map);
	destroy_img(data);
	clean_garbage_memory(data, (int)data->move);
	
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	
	exit(1);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
