/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:44:47 by tauer             #+#    #+#             */
/*   Updated: 2024/01/27 03:44:27 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

char	**resolved_path(t_data *data, char **map, int x, int y)
{
	map[x][y] = 'X';
	if ((x > 0) && ((map[x - 1][y] == '0' || map[x - 1][y] == 'T' || map[x - 1][y] == 'E'))) //haut
		resolved_path(data, map, x - 1, y);
	if ((x < data->size_x) && ((map[x + 1][y] == '0' || map[x + 1][y] == 'T'|| map[x + 1][y] == 'E'))) //bas
		resolved_path(data,map, x + 1, y);	
	if ((y < data->size_y) && ((map[x][y + 1] == '0' || map[x][y + 1] == 'T' || map[x][y + 1] == 'E'))) //droite
		resolved_path(data,map, x, y + 1);
	if ((y > 0) && ((map[x][y - 1] == '0' || map[x][y - 1] == 'T' || map[x][y - 1] == 'E'))) //gauche
		resolved_path(data,map, x, y - 1);
	return (map);
}


