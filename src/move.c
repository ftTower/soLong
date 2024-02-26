/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:57:35 by tauer             #+#    #+#             */
/*   Updated: 2024/02/19 18:09:23 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void move_up(t_data *data)
{
    change_map(data, north);
    data->textures.current_perso = data->textures.back_perso;
}

void move_down(t_data *data)
{
    change_map(data, south);
    data->textures.current_perso = data->textures.running_1;
}

void move_right(t_data *data)
{
    change_map(data, east);
    data->textures.current_perso = data->textures.right_perso;
}
void move_left(t_data *data)
{
    change_map(data, west);
    data->textures.current_perso = data->textures.left_perso;
}

void move_nor_es(t_data *data)
{
    change_map(data, nor_ea);
}

void move_nor_we(t_data *data)
{
    change_map(data, nor_we);   
}

void move_sou_es(t_data *data)
{
    change_map(data, sou_ea);   
}

void move_sou_we(t_data *data)
{
    change_map(data, sou_we);   
}