																																																																				/*	 ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:09:49 by tauer             #+#    #+#             */
/*   Updated: 2024/01/25 20:24:54 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	check_walls(t_data *data, int x, int y)
{
	char	c;

	if (x < 0 || x > data->size_x || y < 0 || y > data->size_y)
		return (0);
	c = data->map[x][y];
	return ((c == '1') || (c >= 'a' && c <= 'z') || c == 'E');
}

int	check_empty(t_data *data, int x, int y)
{
	char	c;

	if (x < 0 || x > data->size_x || y < 0 || y > data->size_y)
		return (0);
	c = data->map[x][y];
	return (c == '0' || c == 'C' || c == 'T' || c == 'V');
}

int	check_void(t_data *data, int x, int y)
{
	char	c;

	if (x < 0 || x > data->size_x || y < 0 || y > data->size_y)
		return (0);
	c = data->map[x][y];
	return (c == 'X');
}

int check_next(t_data *data, int x, int y)
{
    // Vérifier si les coordonnées sont à l'intérieur des limites de la carte
    if (x < 0 || x >= data->size_x || y < 0 || y >= data->size_y)
        return 0;

    // Vérifier le contenu de la case suivante
    char next_cell = data->map[x][y];
    
    // Si la case est vide ou une sortie, retourner 1 pour permettre le déplacement
    if (next_cell == '0' || next_cell == '2' || next_cell == 'T' || (next_cell == 'E' && data->collectibles_left == 0))
        return 1;
    
    // Sinon, retourner 0 pour bloquer le déplacement
    return 0;
}


int	borders(char c)
{
	if (c == 'X' || c == 'C')
	{
		printf("map not closed\n");
		return (1);
	}
	return (0);
}
