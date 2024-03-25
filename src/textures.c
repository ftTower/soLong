/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:34:39 by tauer             #+#    #+#             */
/*   Updated: 2024/03/25 22:02:46 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

bool	init_textures(t_data *data)
{
	int	checker;

	checker = 0;
	if (!init_perso(data) || !init_walls(data) || !init_wall_cosmetics(data)
		|| !init_floor(data) || !init_rest(data) || !init_exit(data)
		|| !init_num(data) || !init_capsule(data))
		checker++;
	return (checker > 0);
}

void	textures_loader(t_data *data)
{
	if (init_textures(data))
	{
		data->move = -1;
		close_win(data);
	}
}
