/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:33:52 by tauer             #+#    #+#             */
/*   Updated: 2024/02/19 19:12:17 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	close_win(t_data *data)
{
	free_map(data->map);
	if (data->mlx && data->win)
		mlx_destroy_window(data->mlx, data->win);
	//free(data);

	exit(1);
}
