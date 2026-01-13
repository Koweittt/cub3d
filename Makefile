NAME		= Cub3d

CC			= cc
CFLAGS		= -g
RM			= rm -f

MLX_DIR		= includes/minilibx-linux
MLX_LIB		= $(MLX_DIR)/libmlx.a
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

INC_DIR		= inc/
SRC_DIR		= src/
OBJ_DIR		= obj/

SRCS		= sources/main.c \
			  sources/parsing/utils.c \
			  sources/parsing/utils2.c \
			  sources/parsing/utils3.c \
			  sources/parsing/init.c \
			  sources/parsing/parsing.c \
			  sources/parsing/parse_textures.c \
			  sources/parsing/parse_map.c \
			  sources/parsing/parse_colors.c \
			  sources/parsing/find_player.c \
			  sources/parsing/map_utils.c \
			  sources/exec/init_mlx.c \
			  sources/exec/key_handlers.c \
			  sources/exec/render.c \
			  sources/exec/player.c \
			  sources/exec/raycasting.c \
			  sources/exec/raycasting_init.c \
			  sources/exec/raycasting_draw.c \
			  sources/exec/raycasting_dda.c \
			  sources/exec/movements.c \
			  sources/exec/collision.c \
			  sources/exec/textures.c \
			  sources/exec/free.c \
			  includes/Libft/libft.a \
			  includes/GNL/get_next_line_bonus.c \
			  includes/GNL/get_next_line_utils_bonus.c


OBJS		= $(SRCS:src/%.c=obj/%.o)

HEADERS		= -I$(INC_DIR)

$(OBJ_DIR)%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

all: $(NAME)

$(MLX_LIB):
	@make -C $(MLX_DIR)

$(NAME): $(MLX_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)
	@echo "$(NAME) compiled successfully!"

clean:
	$(RM) -r $(OBJ_DIR)
	@make clean -C $(MLX_DIR)
	@echo "Object files cleaned!"

fclean: clean
	$(RM) $(NAME)
	@echo "$(NAME) removed!"

re: fclean all

.PHONY: all clean fclean re
