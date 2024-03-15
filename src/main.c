/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:13:58 by tauer             #+#    #+#             */
/*   Updated: 2024/03/15 19:28:12 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

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
	if (pre_settings(data))
		return ;
	if (map_ok(data) && settings(data))
		core(data);
	else
	{
		printf("[FAILURE]\n");
		print_simple_line();
		free_map(data->map);
		return ;
	}
	close_win(data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		data.map_path = argv[1];
		sas(&data);
	}
	else
	{
		data.map_path = "./map/error/wrong_arg.ber";
		sas(&data);
	}
	return (0);
}
