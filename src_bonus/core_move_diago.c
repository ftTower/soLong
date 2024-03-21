/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_move_diago.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:02:54 by tauer             #+#    #+#             */
/*   Updated: 2024/03/21 14:51:38 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

void	move_nor_es(t_data *data)
{
	change_map(data, nor_ea);
}

void	move_nor_we(t_data *data)
{
	change_map(data, nor_we);
}

void	move_sou_es(t_data *data)
{
	change_map(data, sou_ea);
}

void	move_sou_we(t_data *data)
{
	change_map(data, sou_we);
}
