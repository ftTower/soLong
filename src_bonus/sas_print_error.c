/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sas_print_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:47:21 by tauer             #+#    #+#             */
/*   Updated: 2024/03/21 14:53:34 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

void	map_erreur(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
			colors_erreur_common(map, x, y++);
		ft_printf("\n");
		x++;
	}
}

void	map_erreur_size(char **map, int x_error)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
			colors_erreur_size(map, x_error, x, y++);
		printf("\n");
		x++;
	}
}

void	map_erreur_char(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	print_simple_line();
	while (map[x])
	{
		y = 0;
		while (map[x][y])
			colors_erreur_char(map, x, y++);
		printf("\n");
		x++;
	}
}

void	put_error_msg(char *error_msg)
{
	print_simple_line();
	ft_printf("%s\n", error_msg);
	print_simple_line();
}
