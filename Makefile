SRC_BONUS_DIR		=	src_bonus
BUILD_BONUS_DIR		=	build_bonus
SRC_DIR				=	src
BUILD_DIR			=	build
NAME				=	so_long
CFLAG				=	-Wall -Wextra -Werror -I./header/ -I./minilibx-linux/
LDFLAGS 			= 	-L./minilibx-linux -lmlx_Linux -lmlx -lX11 -lXext

SRC					=	src/cardinal_chunk.c\
						src/compteur.c\
						src/core_choose_img.c\
						src/core_dir.c\
						src/core_gameplay.c\
						src/core_img.c\
						src/core_key.c\
						src/core_render.c\
						src/main_free.c\
						src/main_set.c\
						src/main_settings.c\
						src/main.c\
						src/print_format.c\
						src/print_utils.c\
						src/print.c\
						src/sas_check_map.c\
						src/sas_check.c\
						src/sas_colors_erreur.c\
						src/sas_find.c\
						src/sas_pathfinder.c\
						src/sas_print_error.c\
						src/sas_security.c\
						src/settings_custom_map.c\
						src/settings_wall_connections.c\
						src/textures_init_map.c\
						src/textures_init_num.c\
						src/textures_init_perso.c\
						src/textures_init_walls.c\
						src/textures.c\
						src/utils_for_get_next_line.c\
						src/utils_get_next_line.c\
						src/utils_itoa.c\
						src/utils_printf_1.c\
						src/utils_printf_2.c\
						src/utils_printf_main.c\
						src/utils_printf.c\
						src/utils_for_split.c\
						src/utils_split.c\
						src/utils.c\
						src/textures_garbage.c\
						src/presettings_get_map.c\

SRC_BONUS			=	src_bonus/cardinal_chunk.c\
						src_bonus/cardinal_ennemy_inter.c\
						src_bonus/cardinal_ennemy.c\
						src_bonus/cardinal_inter.c\
						src_bonus/cardinal_pixelator.c\
						src_bonus/cardinal_point.c\
						src_bonus/compteur.c\
						src_bonus/core_choose_img.c\
						src_bonus/core_ennemy.c\
						src_bonus/core_gameplay.c\
						src_bonus/core_img.c\
						src_bonus/core_key.c\
						src_bonus/core_map_move.c\
						src_bonus/core_move_diago.c\
						src_bonus/core_move.c\
						src_bonus/core_render.c\
						src_bonus/core_shoot.c\
						src_bonus/core_time.c\
						src_bonus/main_free.c\
						src_bonus/main_set.c\
						src_bonus/main_settings.c\
						src_bonus/main.c\
						src_bonus/presettings_get_map.c\
						src_bonus/print_format.c\
						src_bonus/print_utils.c\
						src_bonus/print.c\
						src_bonus/sas_check_map.c\
						src_bonus/sas_check.c\
						src_bonus/sas_colors_erreur.c\
						src_bonus/sas_find.c\
						src_bonus/sas_pathfinder.c\
						src_bonus/sas_print_error.c\
						src_bonus/sas_security.c\
						src_bonus/set_ennemy.c\
						src_bonus/settings_custom_map.c\
						src_bonus/settings_wall_connections.c\
						src_bonus/textures_anim_link.c\
						src_bonus/textures_anim_update.c\
						src_bonus/textures_garbage.c\
						src_bonus/textures_init_anim_screen.c\
						src_bonus/textures_init_anim.c\
						src_bonus/textures_init_ennemy.c\
						src_bonus/textures_init_map.c\
						src_bonus/textures_init_num.c\
						src_bonus/textures_init_perso.c\
						src_bonus/textures_init_walls.c\
						src_bonus/textures.c\
						src_bonus/utils_for_get_next_line.c\
						src_bonus/utils_for_split.c\
						src_bonus/utils_get_next_line.c\
						src_bonus/utils_itoa.c\
						src_bonus/utils_printf_1.c\
						src_bonus/utils_printf_2.c\
						src_bonus/utils_printf_main.c\
						src_bonus/utils_printf.c\
						src_bonus/utils_split.c\
						src_bonus/utils.c\
						
CC					=	cc # Add this line

OBJ					=	$(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o, $(SRC))
OBJ_BONUS			=	$(patsubst $(SRC_BONUS_DIR)/%.c,$(BUILD_BONUS_DIR)/%.o, $(SRC_BONUS))

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC)	$(CFLAG)	-c	$< -o	$@
	@clear

$(BUILD_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC)	$(CFLAG)	-c	$< -o	$@
	@clear

all : $(NAME)

$(NAME):$(OBJ)
	@echo $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) $(CFLAG) $(LDFLAGS)
	@clear

bonus: $(OBJ_BONUS)
	@$(CC) $(OBJ_BONUS) -o $(NAME) $(CFLAG) $(LDFLAGS)
	@clear

clear :
	@clear
	@echo "42Paris : $(NAME)"
	@echo ""

clean : clear
	@rm -rf $(BUILD_DIR)
	@rm -rf $(BUILD_BONUS_DIR)
	@echo "Clean   : *.o in build and build_bonus!"

fclean : clean
	@rm -f $(NAME)
	@echo "Clean   : ./$(NAME)"

aclean : fclean cleanlib clear

minlibx :
	@git clone https://github.com/42Paris/minilibx-linux.git
	@make -C ./minilibx-linux
	clear
	
cleanlib :
	@rm -rf minilibx-linux

re: fclean all clear 

.PHONY: all clean fclean re
