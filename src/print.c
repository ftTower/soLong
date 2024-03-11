/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:04:11 by tauer             #+#    #+#             */
/*   Updated: 2024/03/11 09:54:49 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	print_map(t_data *data)
{
	int	x;
	int	y;

	if (!data->map)
	{
		printf("data->map : NULL");
	}
	x = 0;
	y = 0;
	// printf("\033c");
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			printf("|");
			if (data->map[x][y] == '0')
				printf(" ");
			else
				printf("%c", data->map[x][y]);
			y++;
		}
		printf("|");
		printf("\n");
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
			printf("|");
			if (map[x][y] == '0')
				printf(".");
			else
				printf("%c", map[x][y]);
			y++;
		}
		printf("|");
		printf("\n");
		x++;
	}
	print_simple_line();
}

void	stats(int unite)
{
	if (unite >= 0 && unite <= 9)
		printf("\033[48;5;248m   \033[0m\033[0;47m\033[0m");
	else if (unite >= 10 && unite <= 99)
		printf("\033[48;5;248m  \033[0m\033[0;47m\033[0m");
	else
		printf("\033[48;5;248m \033\033[0;47m\033[0m");
}

void	render_stats(t_data *data, int x)
{
	if (x == 0)
	{
		printf("\033[48;5;248m    coords : [%d] - [%d]     \033[0m", data->x,
			data->y);
		/// stats(data->y);
	}
	if (x == 1)
		printf("\033[48;5;248m              x     y      \033[0m");
	if (x == 2)
		printf("\033[48;5;248m                           \033[0m");
	if (x == 3)
	{
		printf("\033[48;5;248m  collectibles      [%d] \033[0m",
			data->collectibles);
		stats(data->collectibles);
	}
	if (x == 4)
	{
		printf("\033[48;5;248m  collectibles left [%d] \033[0m",
			data->collectibles_left);
		stats(data->collectibles_left);
	}
	if (x == 5)
	{
		printf("\033[48;5;248m  moves             [%lld] \033[0m", data->move);
		stats(data->move);
	}
	if (x == 6)
	{
		printf("\033[48;5;248m  wave      :       [%d] \033[0m", data->wave);
		stats(data->wave);
	}
	if (x == 7)
		printf("\033[48;5;248m  map size  : [%d x %d]    \033[0m", data->size_x,
			data->size_y);
	if (x == 8)
		printf("\033[48;5;248m                           \033[0m");
	if (x == 9)
		printf("\033[48;5;248m      [ESC] to quit        \033[0m");
	if (x > 9)
		printf("\033[48;5;248m                           \033[0m");
	printf("\033[0;47m  \033[0m");
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
		printf("\033[0;47m  \033[0m");
		while (data->map[x][y])
		{
			// printf("");
			if ((data->map[x][y] >= 'a' && data->map[x][y] <= 'z')
				|| data->map[x][y] == '1')
				printf("\033[48;5;240m  \033[0m");
			// printf("%c", data->map[x][y]);
			else if (data->map[x][y] == 'V')
				printf("\033[48;5;124m  \033[0m");
			else if (data->map[x][y] == 'D')
				printf("\033[48;5;248m  \033[0m");
			else if (data->map[x][y] == 'C')
				printf("\033[48;5;208m  \033[0m");
			else if (data->map[x][y] == 'T')
				printf("\033[48;5;40m  \033[0m");
			else if (data->map[x][y] == 'E' && data->collectibles_left == 0)
				printf("\033[48;5;76m  \033[0m");
			else if (data->map[x][y] == 'E')
				printf("\033[48;5;160m  \033[0m");
			else if (data->map[x][y] == 'X')
				printf("\033[48;5;16m  \033[0m");
			else
				printf("\033[48;5;195m  \033[0m");
			y++;
		}
		printf("\033[0;47m  \033[0m");
		render_stats(data, x);
		printf("\n");
		x++;
	}
	print_line(data);
}

void	print_line(t_data *data)
{
	int	i;

	i = data->size_y + 14;
	while (i-- >= 0)
		printf("\033[0;47m  ");
	printf("     \n\033[0m");
}

void	print_simple_line(void)
{
	write(1, "======================================================================\n", 72);
}

void	render_terminal(t_data *data)
{
	printf("\033c");
	core_terminal(data);
	//debug_map(data->map);
}
