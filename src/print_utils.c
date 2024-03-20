/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:02:26 by tauer             #+#    #+#             */
/*   Updated: 2024/03/20 16:04:22 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	print_line(t_data *data)
{
	int	i;

	i = data->size_y + 14;
	while (i-- >= 0)
		ft_printf("\033[0;47m  ");
	ft_printf("     \n\033[0m");
}

void	print_simple_line(void)
{
	int i;

	i = 80;
	while(i--)
		write(1, "=", 1);
	write(1, "\n", 1);  
}

void	debug_map(char **map)
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
		{
			ft_printf("%c ", map[x][y]);
			y++;
		}
		ft_printf("|");
		ft_printf("\n");
		x++;
	}
	print_simple_line();
}
