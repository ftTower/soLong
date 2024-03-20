/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:04:11 by tauer             #+#    #+#             */
/*   Updated: 2024/03/20 02:02:42 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	print_map(t_data *data)
{
	int	x;
	int	y;

	if (!data->map)
	{
		ft_printf("data->map : NULL");
	}
	x = 0;
	y = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			ft_printf("|");
			if (data->map[x][y] == '0')
				ft_printf(" ");
			else
				ft_printf("%c", data->map[x][y]);
			y++;
		}
		ft_printf("|");
		ft_printf("\n");
		x++;
	}
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

void	stats(int unite)
{
	if (unite >= 0 && unite <= 9)
		ft_printf("\033[48;5;248m   \033[0m\033[0;47m\033[0m");
	else if (unite >= 10 && unite <= 99)
		ft_printf("\033[48;5;248m  \033[0m\033[0;47m\033[0m");
	else
		ft_printf("\033[48;5;248m \033\033[0;47m\033[0m");
}

void	render_stats(t_data *data, int x)
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
	if (x == 6)
	{
		ft_printf("\033[48;5;248m  wave      :       [%d] \033[0m", data->wave);
		stats(data->wave);
	}
	if (x == 7)
		ft_printf("\033[48;5;248m  map size  : [%d x %d]    \033[0m", data->size_x,
			data->size_y);
	if (x == 8)
		ft_printf("\033[48;5;248m                           \033[0m");
	if (x == 9)
		ft_printf("\033[48;5;248m      [ESC] to quit        \033[0m");
	if (x > 9)
		ft_printf("\033[48;5;248m                           \033[0m");
	ft_printf("\033[0;47m  \033[0m");
}

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
		{
			if ((data->map[x][y] >= 'a' && data->map[x][y] <= 'z')
				|| data->map[x][y] == '1')
				ft_printf("\033[48;5;240m  \033[0m");
			else if (data->map[x][y] == 'V')
				ft_printf("\033[48;5;124m  \033[0m");
			else if (data->map[x][y] == 'D')
				ft_printf("\033[48;5;248m  \033[0m");
			else if (data->map[x][y] == 'C')
				ft_printf("\033[48;5;208m  \033[0m");
			else if (data->map[x][y] == 'T')
				ft_printf("\033[48;5;40m  \033[0m");
			else if (data->map[x][y] == 'E' && data->collectibles_left == 0)
				ft_printf("\033[48;5;76m  \033[0m");
			else if (data->map[x][y] == 'E')
				ft_printf("\033[48;5;160m  \033[0m");
			else if (data->map[x][y] == 'X')
				ft_printf("\033[48;5;16m  \033[0m");
			else
				ft_printf("\033[48;5;195m  \033[0m");
			y++;
		}
		ft_printf("\033[0;47m  \033[0m");
		render_stats(data, x);
		ft_printf("\n");
		x++;
	}
	print_line(data);
}

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
	write(1,
		"======================================================================\n",
		72);
}

void	render_terminal(t_data *data)
{
	if (gettime() - data->time_start > 500 && gettime()
		- data->time_start <= 1500)
		ft_printf("\033c\n\n\n\n\n\t\t✅ TEXTURES\n\n\n\n\n");
	if (gettime() - data->time_start > 1500)
	{
		ft_printf("\033c");
		core_terminal(data);
		//debug_map(data->map);
	}
}
