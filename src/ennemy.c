/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:51:06 by tauer             #+#    #+#             */
/*   Updated: 2024/02/19 20:06:59 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	diago(t_data *data)
{
	if (data->x > data->v_x && data->y < data->v_y && check_empty(data,
			data->v_x + 1, data->v_y - 1))
	{
		data->map[data->v_x][data->v_y] = '0';
		if (data->map[data->v_x + 1][data->v_y - 1] == 'C')
			close_win(data);
		data->map[data->v_x + 1][data->v_y - 1] = 'V';
		data->v_x++;
		data->v_y--;
		return (0);
	}
	else if (data->x < data->v_x && data->y < data->v_y && check_empty(data,
			data->v_x - 1, data->v_y - 1))
	{
		data->map[data->v_x][data->v_y] = '0';
		data->map[data->v_x - 1][data->v_y - 1] = 'V';
		if (data->map[data->v_x - 1][data->v_y - 1] == 'C')
			close_win(data);
		data->v_x--;
		data->v_y--;
		return (0);
	}
	else if (data->x < data->v_x && data->y > data->v_y && check_empty(data,
			data->v_x - 1, data->v_y + 1))
	{
		data->map[data->v_x][data->v_y] = '0';
		if (data->map[data->v_x - 1][data->v_y + 1] == 'C')
			close_win(data);
		data->map[data->v_x - 1][data->v_y + 1] = 'V';
		data->v_x--;
		data->v_y++;
		return (0);
	}
	else if (data->x > data->v_x && data->y > data->v_y && check_empty(data,
			data->v_x + 1, data->v_y + 1))
	{
		data->map[data->v_x][data->v_y] = '0';
		if (data->map[data->v_x + 1][data->v_y + 1] == 'C')
			close_win(data);
		data->map[data->v_x + 1][data->v_y + 1] = 'V';
		data->v_x++;
		data->v_y++;
		return (0);
	}
	return (1);
}

int	cote(t_data *data)
{
	if (data->y < data->v_y && check_empty(data, data->v_x, data->v_y - 1))
	{
		data->map[data->v_x][data->v_y] = '0';
		if (data->map[data->v_x][data->v_y - 1] == 'C')
			close_win(data);
		data->map[data->v_x][data->v_y - 1] = 'V';
		data->v_y--;
		return (0);
	}
	else if (data->x > data->v_x && check_empty(data, data->v_x + 1, data->v_y))
	{
		data->map[data->v_x][data->v_y] = '0';
		if (data->map[data->v_x + 1][data->v_y] == 'C')
			close_win(data);
		data->map[data->v_x + 1][data->v_y] = 'V';
		data->v_x++;
		return (0);
	}
	else if (data->x < data->v_x && check_empty(data, data->v_x - 1, data->v_y))
	{
		data->map[data->v_x][data->v_y] = '0';
		if (data->map[data->v_x - 1][data->v_y] == 'C')
			close_win(data);
		data->map[data->v_x - 1][data->v_y] = 'V';
		data->v_x--;
		return (0);
	}
	else if (data->y > data->v_y && check_empty(data, data->v_x, data->v_y + 1))
	{
		data->map[data->v_x][data->v_y] = '0';
		if (data->map[data->v_x][data->v_y + 1] == 'C')
			close_win(data);
		data->map[data->v_x][data->v_y + 1] = 'V';
		data->v_y++;
		return (0);
	}
	return (1);
}

int	cote_without_goal(t_data *data)
{
	if (check_empty(data, data->v_x, data->v_y - 1))
	{
		data->map[data->v_x][data->v_y] = '0';
		if (data->map[data->v_x][data->v_y - 1] == 'C')
			close_win(data);
		data->map[data->v_x][data->v_y - 1] = 'V';
		data->v_y--;
		return (0);
	}
	else if (check_empty(data, data->v_x, data->v_y + 1))
	{
		data->map[data->v_x][data->v_y] = '0';
		if (data->map[data->v_x][data->v_y + 1] == 'C')
			close_win(data);
		data->map[data->v_x][data->v_y + 1] = 'V';
		data->v_y++;
		return (0);
	}
	else if (check_empty(data, data->v_x + 1, data->v_y))
	{
		data->map[data->v_x][data->v_y] = '0';
		if (data->map[data->v_x + 1][data->v_y] == 'C')
			close_win(data);
		data->map[data->v_x + 1][data->v_y] = 'V';
		data->v_x++;
		return (0);
	}
	else if (check_empty(data, data->v_x - 1, data->v_y))
	{
		data->map[data->v_x][data->v_y] = '0';
		if (data->map[data->v_x - 1][data->v_y] == 'C')
			close_win(data);
		data->map[data->v_x - 1][data->v_y] = 'V';
		data->v_x--;
		return (0);
	}
	return (1);
}

void	best_decisition(t_data *data)
{
	if (diago(data))
		if (cote(data))
			if (cote_without_goal(data))
				return ;
}

int	ennemy_dead(t_data *data)
{
	if (data->life_ennemy == 0)
	{
		data->map[data->v_x][data->v_y] = '0';
		return (0);
	}
	return (1);
}

void	ennemys_conscience(t_data *data)
{
	if (data->life_ennemy > 0 && data->wave > 0)
		best_decisition(data);
}
