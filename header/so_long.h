/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:55:45 by tauer             #+#    #+#             */
/*   Updated: 2024/03/21 14:59:41 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../header/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				h;
	int				w;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	struct s_img	*next;
}					t_img;

typedef struct s_textures
{
	t_img			empty;
	t_img			floor;

	t_img			right_top_corner_up;
	t_img			left_top_corner_up;

	t_img			right_top_corner;
	t_img			left_top_corner;

	t_img			right_corner;
	t_img			left_corner;

	t_img			right_empty;
	t_img			left_empty;

	t_img			wall;
	t_img			wall_up;
	t_img			wall_4;
	t_img			wall_down;
	t_img			wall_down_empty;
	t_img			down;

	t_img			toward_wall;
	t_img			toward_wall_left_empty;
	t_img			toward_wall_right_empty;

	t_img			collectibles;

	t_img			perso;
	t_img			back_perso;
	t_img			right_perso;
	t_img			left_perso;

	t_img			ennemy_front;
	t_img			ennemy_back;
	t_img			ennemy_right;
	t_img			ennemy_left;

	t_img			capsule;

	t_img			capsule_1;

	t_img			exit_1;
	t_img			exit_19;

	t_img			panel_wall;
	t_img			private_door;

	t_img			wall_screen;

	t_img			wall_screen_outdoor;

	t_img			wall_screen_indoor;

	t_img			floor_x;
	t_img			floor_ventil;

	t_img			num0;
	t_img			num1;
	t_img			num2;
	t_img			num3;
	t_img			num4;
	t_img			num5;
	t_img			num6;
	t_img			num7;
	t_img			num8;
	t_img			num9;

}					t_textures;

typedef struct s_memory
{
	char			*path;
	char			*name;
	char			*id;
	void			*ptr;
	t_img			*img;
	struct s_memory	*next;
}					t_memory;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	int				win_x;
	int				win_y;
	int				shocking_win;

	void			*mlx_num;
	void			*win_num;
	int				win_x_num;
	int				win_y_num;

	int				collectibles;
	int				collectibles_left;
	long			move;

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

	int				selecter_custom;

	t_img			base_image;
	t_img			base_num;
	t_textures		textures;
	t_memory		*memory;
}					t_data;

typedef enum t_dir
{
	north,
	south,
	east,
	west,
	no_dir,
}					t_dir;

#endif