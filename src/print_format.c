/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:13:33 by tauer             #+#    #+#             */
/*   Updated: 2024/03/21 18:57:53 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	stats(int unite)
{
	if (unite >= 0 && unite <= 9)
		ft_printf("\033[48;5;248m   \033[0m\033[0;47m\033[0m");
	else if (unite >= 10 && unite <= 99)
		ft_printf("\033[48;5;248m  \033[0m\033[0;47m\033[0m");
	else
		ft_printf("\033[48;5;248m \033\033[0;47m\033[0m");
}

void	basic_stats(t_data *data, int x)
{
	if (x == 0)
		ft_printf("\033[48;5;248m    coords : [%d] - [%d]     \033[0m", data->x,
			data->y);
	if (x == 1)
		ft_printf("\033[48;5;248m              x     y      \033[0m");
	if (x == 2)
		ft_printf("\033[48;5;248m                           \033[0m");
	if (x == 3)
	{
		ft_printf("\033[48;5;248m  collectibles      [%d] \033[0m",
			data->collectibles);
		stats(data->collectibles);
	}
	if (x == 4)
	{
		ft_printf("\033[48;5;248m  collectibles left [%d] \033[0m",
			data->collectibles_left);
		stats(data->collectibles_left);
	}
	if (x == 5)
	{
		ft_printf("\033[48;5;248m  moves             [%d] \033[0m", data->move);
		stats(data->move);
	}
}

void	rest_stats(t_data *data, int x)
{
	if (x == 6)
	{
		ft_printf("\033[48;5;248m  wave      :       [%d] \033[0m", data->wave);
		stats(data->wave);
	}
	if (x == 7)
		ft_printf("\033[48;5;248m  map size  : [%d x %d]    \033[0m",
			data->size_x, data->size_y);
	if (x == 8)
		ft_printf("\033[48;5;248m                           \033[0m");
	if (x == 9)
		ft_printf("\033[48;5;248m      [ESC] to quit        \033[0m");
	if (x > 9)
		ft_printf("\033[48;5;248m                           \033[0m");
}

void	render_stats(t_data *data, int x)
{
	if (x >= 0 && x < 6)
		basic_stats(data, x);
	else
		rest_stats(data, x);
	ft_printf("\033[0;47m  \033[0m");
}
