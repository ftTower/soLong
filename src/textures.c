/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:34:39 by tauer             #+#    #+#             */
/*   Updated: 2024/03/11 00:11:51 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	link_animations(t_data *data)
{
	link_perso(data);
	link_deco(data);
	link_exit(data);
	set_currents(data);
}

void	init_textures(t_data *data)
{
	init_perso(data);
	init_exit(data);
	init_screen_indoor(data);
	init_screen_outdoor(data);
	init_capsule(data);
	init_walls(data);
	init_wall_cosmetics(data);
	init_floor(data);
	init_ennemy(data);
	init_rest(data);
}

void	textures_loader(t_data *data)
{	
	init_textures(data);
	link_animations(data);
}

