/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:13:58 by tauer             #+#    #+#             */
/*   Updated: 2024/02/21 13:47:37 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	security(t_data *data)
{
	if (data->move >= __LONG_LONG_MAX__ || data->x >= __INT_MAX__
		|| data->y >= __INT_MAX__ || data->mov_chunk_x >= __INT_MAX__
		|| data->mov_chunk_y >= __INT_MAX__)
	{
		printf("[security] : variable out of range\n");
		close_win(data);
	}
}


int	looper(t_data *data)
{
	loops(data);
	end_wave(data);
	security(data);
	return (0);
}

static int	core(t_data *data)
{
	hooking(data);
	mlx_loop(data->mlx);
	return (0);
}

void	sas(t_data *data)
{
	pre_settings(data);
	if (map_ok(data) && settings(data))
		core(data);
	else
	{
		printf("[FAILURE]\n");
		print_simple_line();
		free_map(data->map);
		free_map(data->map);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.map_path = argv[1];
	if (argc == 2)
		sas(&data);
	else
	{
		printf("wrong number of arg !\n");
		print_simple_line();
	}
	return (0);
}
