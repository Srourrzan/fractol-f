# _*_ MakeFile _*_

TARGET = fractol
SRCS = main.c map_utils.c display_utils.c mlx_utils.c std_utils.c finish_utils.c parse_args.c \
		fractol_utils.c mandelbrot.c
OBJ_DIR = obj

OBJS = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -lmlx -lX11 -lXext -lXrender
M_FLAGS = -lm 

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(MLX_FLAGS)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ 

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	
re: fclean all

fclean: clean
	rm -f $(TARGET)

clean:
	rm -f $(OBJS)
	rm -rf $(OBJ_DIR)

.PHONY: all clean fclean re