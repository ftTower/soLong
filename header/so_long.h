/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:16:59 by tauer             #+#    #+#             */
/*   Updated: 2024/03/11 15:20:15 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../header/get_next_line.h"
#include "../minilibx-linux/mlx.h"

#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

typedef struct s_img
{
	void *img;
	char *addr;
	int h;
	int w;
	int bits_per_pixel;
	int line_length;
	int endian;
	struct s_img *next;
} t_img;

typedef struct s_textures
{
	t_img empty;
	t_img floor;

	t_img right_top_corner_up;
	t_img left_top_corner_up;

	t_img right_top_corner;
	t_img left_top_corner;

	t_img right_corner;
	t_img left_corner;

	t_img right_empty;
	t_img left_empty;

	t_img wall;
	t_img wall_up;
	t_img wall_4;
	t_img wall_down;
	t_img wall_down_empty;
	t_img down;

	t_img toward_wall;
	t_img toward_wall_left_empty;
	t_img toward_wall_right_empty;

	t_img collectibles;

	t_img perso;
	t_img breathing_perso_1;
	t_img breathing_perso_2;

	t_img back_perso;
	t_img back_perso_1;
	t_img back_perso_2;

	t_img right_perso;
	t_img right_perso_1;
	t_img right_perso_2;

	t_img left_perso;
	t_img left_perso_1;
	t_img left_perso_2;

	t_img running_1;
	t_img running_2;

	t_img ennemy_front;
	t_img ennemy_back;
	t_img ennemy_right;
	t_img ennemy_left;

	t_img capsule;

	t_img capsule_1;
	t_img capsule_2;

	t_img capsule_3;

	t_img capsule_4;
	t_img capsule_5;

	t_img exit_1;
	t_img exit_2;
	t_img exit_3;
	t_img exit_4;
	t_img exit_5;
	t_img exit_6;
	t_img exit_7;
	t_img exit_8;
	t_img exit_9;
	t_img exit_10;
	t_img exit_11;
	t_img exit_12;
	t_img exit_13;
	t_img exit_14;
	t_img exit_15;
	t_img exit_16;
	t_img exit_17;
	t_img exit_18;
	t_img exit_19;

	t_img panel_wall;
	t_img private_door;

	t_img wall_screen;

	t_img wall_screen_outdoor;
	t_img wall_screen_outdoor_1;
	t_img wall_screen_outdoor_2;
	t_img wall_screen_outdoor_3;
	t_img wall_screen_outdoor_4;
	t_img wall_screen_outdoor_5;

	t_img wall_screen_indoor;
	t_img wall_screen_indoor_1;
	t_img wall_screen_indoor_2;
	t_img wall_screen_indoor_3;
	t_img wall_screen_indoor_4;
	t_img wall_screen_indoor_5;
	t_img wall_screen_indoor_6;
	t_img wall_screen_indoor_7;
	t_img wall_screen_indoor_8;

	t_img floor_x;
	t_img floor_ventil;

	t_img current_exit;
	t_img current_perso;
	t_img current_ennemy;
	t_img current_capsule;
	t_img current_screen_outdoor;
	t_img current_screen_indoor;

	t_img num0;
	t_img num1;
	t_img num2;
	t_img num3;
	t_img num4;
	t_img num5;
	t_img num6;
	t_img num7;
	t_img num8;
	t_img num9;

} t_textures;

typedef struct s_key
{
	bool up_key;
	bool down_key;
	bool right_key;
	bool left_key;
	bool shoot_key;
} t_key;

typedef struct s_data
{
	void *mlx;
	void *win;
	int win_x;
	int win_y;
	int shocking_win;

	void *mlx_num;
	void *win_num;
	int win_x_num;
	int win_y_num;

	int collectibles;
	int collectibles_left;
	long move;

	int wave;

	char **map;
	char **map_dup;
	char *map_path;
	int size_x;
	int size_y;
	int switcher;

	int start_x;
	int start_y;

	int x;
	int y;
	int mov_chunk_x;
	int mov_chunk_y;

	int v_x;
	int v_y;
	int chunk_v_x;
	int chunk_v_y;

	int life_ennemy;

	int mov_status;

	int first_wall_x;
	int first_wall_y;

	int e_x;
	int e_y;

	int selecter_custom;

	clock_t time_render;
	clock_t time_perso;
	clock_t time_ennemy;
	clock_t time_capsule;

	t_img base_image;
	t_img base_num;
	t_textures textures;
	t_key key;
} t_data;

typedef enum t_dir
{
	north,
	south,
	east,
	west,

	nor_ea,
	nor_we,
	sou_ea,
	sou_we,
	no_dir,
} t_dir;

// check
int check_walls(t_data *data, int x, int y);
int check_empty(t_data *data, int x, int y);
int check_void(t_data *data, int x, int y);
int check_next(t_data *data, int x, int y);
int borders(char c);

// custom_map
int custom_indoor_map(t_data *data);

// free
void free_map(char **map);

// gameplay
void end_wave(t_data *data);
void reset_wave(t_data *data);
void change_map(t_data *data, t_dir dir);

// img
t_img new_file_img(char *path, t_data *data);
unsigned int get_pixel_img(t_img img, int x, int y);
void put_pixel_img(t_img img, int x, int y, int color);
void put_img_to_img(t_img dst, t_img src, int y, int x);
t_img new_img(int w, int h, t_data *data);

// key
void hooking(t_data *data);
void move_up(t_data *data);
void move_down(t_data *data);
void move_right(t_data *data);
void move_left(t_data *data);
int deal_key(int key, t_data *data);

// map
char *clean_linefeed(char *str);
char **get_map(char *path);
int count_line(int fd);

// pathfinder
char **resolved_path(t_data *data, char **map, int x, int y);

// print_error
void map_erreur(char **map, t_data *data);

// print
void print_map(t_data *data);
void print_map2(char **map);
void stats(int unite);
void render_stats(t_data *data, int x);
void core_terminal(t_data *data);
void print_line(t_data *data);
void print_simple_line(void);
void render_terminal(t_data *data);
void map_erreur(char **map, t_data *data);

// render
void render_perso(t_data *data, t_img base_image, t_img current);
void render_custom_wall(t_data *data, int x, int y, int x_pos,
						int y_pos);
void global_render(t_data *data);

// reset
void reset_collectibles(t_data *data);

// security
int check_collectibles(char **map);
int correct_borders(char **map);
int find_first_border(t_data *data);
int map_ok(t_data *data);

// set_ennemy
void clear_ennemy(t_data *data);
void place_ennemy(t_data *data);
void set_ennemy_by_waves(t_data *data);

// set
void set_input(t_data *data);
void set_window_size(t_data *data);
int settings(t_data *data);
void pre_settings(t_data *data);

t_img	new_img_num(int w, int h, t_data *data);

// textures
int init_num(t_data *data);
void init_perso(t_data *data);
void init_exit(t_data *data);
void init_screen_indoor(t_data *data);
void init_screen_outdoor(t_data *data);
void init_capsule(t_data *data);
void init_walls(t_data *data);
void init_wall_cosmetics(t_data *data);
void init_floor(t_data *data);
void init_ennemy(t_data *data);
void init_rest(t_data *data);
void	textures_loader(t_data *data);
void	render_compteur(t_data *data);

// animations
void link_exit(t_data *data);
void	link_deco(t_data *data);
void	link_perso(t_data *data);
void	set_currents(t_data *data);

void	security(t_data *data);

void set_breathing(t_data *data);
void set_capsule(t_data *data);
void set_screen_outdoor(t_data *data);
void set_screen_indoor(t_data *data);
void set_exit(t_data *data);
void prepare_textures(t_data *data);

void quick_next(t_data *data);
void medium_next(t_data *data);
void slow_next(t_data *data);

// time
void quick_loop(t_data *data);
void medium_loop(t_data *data);
void slow_loop(t_data *data);
void loops(t_data *data);

// utils
clock_t gettime(void);
void delete_emptyness(t_data *data, char **map);
char	**ft_split(char *s, char c);

// window
int close_win(t_data *data);


void	player_death(t_data *data);
// main
int looper(t_data *data);

char *ft_strdup(const char *s);
void ennemys_conscience(t_data *data);
char **copy_map(t_data *data);
void chose_ennemy_move(t_data *data);
int ennemy_dead(t_data *data);
void shoot(t_data *data);
void map_erreur_size(char **map, t_data *data, int x_error);
void map_erreur_char(char **map, t_data *data, int x_error,
					 int y_error);

t_dir get_dir(t_data *data);

void f_nor_we(t_data *data);
void f_nor_ea(t_data *data);
void f_sou_we(t_data *data);
void f_sou_ea(t_data *data);

void f_north(t_data *data);
void f_south(t_data *data);
void f_east(t_data *data);
void f_west(t_data *data);

bool v_west(t_data *data);
bool v_east(t_data *data);
bool v_south(t_data *data);
bool v_north(t_data *data);

void pixelator_perso(t_data *data, t_dir dir);
bool pixelator_ennemy(t_data *data, t_dir dir);

bool v_nor_we(t_data *data);
bool v_nor_ea(t_data *data);
bool v_south_we(t_data *data);
bool v_south_ea(t_data *data);

size_t ft_strlen(const char *str);
char **tab_tab_split(const char *s, char c);
void	set_key_false(t_data *data);
char	*ft_itoa(int nb);

#endif