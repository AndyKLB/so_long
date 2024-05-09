#######################################################
## ARGUMENTS
LIBFT_PATH = ./lib/libft
LIBFT_LIB = $(LIBFT_PATH)/libft.a

FT_PRINTF_PATH = ./lib/ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_PATH)/ft_printf.a

MLX_PATH = ./lib/minilibx-linux
MLX_LIB	= $(MLX_PATH)/libmlx.a

NAME	= so_long
BONUS	= so_long_bonus

CC	= cc
RM = rm -f
FLAG	= -Wall -Wextra -Werror -g3
MLX_FLAG	= -lX11 -lXext

#######################################################
## SOURCES
SRCS_FILES = so_long.c map_reader.c game_init.c \
			map_is_valid.c is_valid_path.c \
			copy_struct.c draw_map.c var_struct_init.c \
			hook_handle.c player_pos_update.c \

BONUS_SRCS_FILES = so_long_bonus.c map_reader_bonus.c game_init_bonus.c \
			map_is_valid_bonus.c is_valid_path_bonus.c \
			copy_struct_bonus.c draw_map_bonus.c var_struct_init_bonus.c \
			hook_handle_bonus.c player_pos_update_bonus.c enemy_init_bonus.c \
			
SRCS_DIR = srcs
SO_LONG_LIB = $(SRCS_DIR)/so_long.a

BONUS_SRCS_DIR = srcs_bonus
BONUS_SO_LONG_LIB = $(BONUS_SRCS_DIR)/so_long_bonus.a

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

BONUS_SRCS = $(addprefix $(BONUS_SRCS_DIR)/, $(BONUS_SRCS_FILES))

OBJECTS = $(SRCS:.c=.o)
BONUS_OBJECTS = $(BONUS_SRCS:.c=.o)

#######################################################
## RULES
all:	$(NAME) $(SO_LONG_LIB)


bonus:	$(BONUS) $(BONUS_SO_LONG_LIB)

full: all bonus

.c.o:
				$(CC) $(FLAG) -c $< -o $(<:.c=.o)

$(NAME):	$(LIBFT_LIB) $(FT_PRINTF_LIB) $(MLX_LIB) $(OBJECTS)
				$(CC) $(FLAG) $(OBJECTS) $(LIBFT_LIB) $(FT_PRINTF_LIB) $(MLX_LIB) $(MLX_FLAG) -o $(NAME)

$(BONUS):	$(LIBFT_LIB) $(FT_PRINTF_LIB) $(MLX_LIB) $(BONUS_OBJECTS)
				$(CC) $(FLAG) $(BONUS_OBJECTS) $(LIBFT_LIB) $(FT_PRINTF_LIB) $(MLX_LIB) $(MLX_FLAG) -o $(BONUS)

${SO_LONG_LIB}: 	${OBJECTS}
		ar -rcs ${SO_LONG_LIB} ${OBJECTS}

${BONUS_SO_LONG_LIB}: 	${BONUS_OBJECTS}
		ar -rcs ${BONUS_SO_LONG_LIB} ${BONUS_OBJECTS} 

$(LIBFT_LIB):	
				$(MAKE) -C $(LIBFT_PATH)

$(MLX_LIB):
				$(MAKE) -C $(MLX_PATH)
$(FT_PRINTF_LIB):
				$(MAKE) -C $(FT_PRINTF_PATH)
				

clean:
				$(MAKE) -C $(LIBFT_PATH) clean
				$(MAKE) -C $(FT_PRINTF_PATH) clean
				$(MAKE) -C $(MLX_PATH) clean
				$(RM) $(OBJECTS)
				
clean_bonus:
				$(MAKE) -C $(LIBFT_PATH) clean
				$(MAKE) -C $(FT_PRINTF_PATH) clean
				$(MAKE) -C $(MLX_PATH) clean
				$(RM) $(BONUS_OBJECTS)

fclean:		clean clean_bonus
				$(MAKE) -C $(LIBFT_PATH) fclean
				$(MAKE) -C $(FT_PRINTF_PATH) fclean
				$(RM) $(NAME)
				$(RM) $(BONUS)
				$(RM) $(SO_LONG_LIB)
				$(RM) $(BONUS_SO_LONG_LIB)

re:		fclean all

re_bonus:	fclean bonus

.PHONY: all bonus clean clean_bonus fclean  re re_bonus