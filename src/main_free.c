/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:20:10 by tauer             #+#    #+#             */
/*   Updated: 2024/03/26 12:24:13 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	free_element(t_memory *memory_current, t_data *data)
{
	ft_printf("| ❌ : \033[38;5;129m%p\033[0m | \033[38;5;15m%s\033[0m\n",
		memory_current->ptr, memory_current->name);
	if (data->mlx && memory_current->ptr)
		mlx_destroy_image(data->mlx, memory_current->ptr);
	free(memory_current->id);
	free(memory_current->name);
	free(memory_current->path);
	free(memory_current);
}

int	close_win(t_data *data)
{
	if (data->map)
		free_map(data->map);
	mlx_destroy_image(data->mlx, data->base_image.img);
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
	if (!map)
		return ;
	while (map[i])
		free(map[i++]);
	free(map);
}
