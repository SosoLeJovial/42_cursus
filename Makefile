NAME =  so_long

CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES) -I$(MLX_DIR)

EXT_FLAGS = -lX11 -lm -lz -lXext

OPTI_FLAGS = -Ofast -march=native -flto -fno-signed-zeros -funroll-loops

DFLAGS = -MMD -MP

MLX_DIR = minilib

MLX = libmlx.a

SRC_DIR = srcs

BUILD_DIR = .build

INCLUDES = includes

SRC_FILES = main.c \
            check_wall.c \
            checkmap.c \
            display_map.c \
            free_all.c \
            get_next_line_utils.c \
            get_next_line.c \
            init_image.c \
            init_map.c \
            player_move.c \
            so_long_utils.c \
                        expand_v.c \
                        map_playable.c\
                        close_window.c\

SRC = $(addprefix $(SRC_DIR)/, SRC_FILES)

OBJ = $(addprefix $(BUILD_DIR)/, $(SRC_FILES:.c=.o))

DEPS = $(OBJ:.o=.d)

.PHONY: all
all : $(NAME)


$(NAME) :  $(OBJ)
        $(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(OPTI_FLAGS) $(MLX_DIR)/$(MLX) $(EXT_FLAGS)
.PHONY: mlx
$(MLX_DIR)/$(MLX): FORCE
        $(MAKE) -C $(MLX_DIR)

.PHONY: libf
$(LIBFT_DIR)/$(LIBFT): FORCE
        $(MAKE) -C $(LIBFT_DIR)

$(BUILD_DIR)/%.o : $(SRC_DIR)/%.c | $(BUILD_DIR) $(MLX_DIR)/$(MLX)
        $(CC) $(CFLAGS) $(DFLAGS) -o $@ -c $<

$(BUILD_DIR):
        mkdir -p $(BUILD_DIR)

-include $(DEPS)

.PHONY: clean
clean :
        $(MAKE) -C $(MLX_DIR)/ clean
        $(RM) -r $(BUILD_DIR)

.PHONY: fclean
fclean : clean
        $(RM) $(NAME)

.PHONY: re
re : fclean
        $(MAKE) all

.PHONY: FORCE
FORCE: