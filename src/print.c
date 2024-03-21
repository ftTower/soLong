/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:04:11 by tauer             #+#    #+#             */
/*   Updated: 2024/03/21 19:52:28 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	core_terminal(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	print_line(data);
	while (data->map[x])
	{
		y = 0;
		ft_printf("\033[0;47m  \033[0m");
		while (data->map[x][y])
			colors_terminal(data, x, y++);
		ft_printf("\033[0;47m  \033[0m");
		render_stats(data, x);
		ft_printf("\n");
		x++;
	}
	print_line(data);
}

void	render_terminal(t_data *data)
{
	ft_printf("\033c");
	core_terminal(data);
	//debug_map(data->map);
}
