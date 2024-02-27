/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:06:06 by tauer             #+#    #+#             */
/*   Updated: 2024/02/20 12:31:39 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "../header/so_long.h"
#include "../header/textures.h"


typedef struct s_data
{
	void			*mlx;
	void			*win;
	int				width;
	int				height;
	int				collectibles;
	int				collectibles_left;
	long long		move;

	int				wave;

	char			**map;
	char			**map_dup;
	char			*map_path;
	int				size_x;
	int				size_y;
	int				switcher;

	int				start_x;
	int				start_y;

	int				x;
	int				y;
	int				mov_chunk_x;
	int				mov_chunk_y;

	int				v_x;
	int				v_y;
	int				chunk_v_x;
	int				chunk_v_y;

	int				life_ennemy;

	int				mov_status;

	int				first_wall_x;
	int				first_wall_y;

	int				e_x;
	int				e_y;

	int				win_x;
	int				win_y;
	int				shocking_win;

	int				selecter_custom;

	clock_t			time_render;
	clock_t			time_perso;
	clock_t			time_ennemy;
	clock_t			time_capsule;

	t_img			base_image;
	t_textures		textures;
	t_key			key;
}					t_data;

#endif