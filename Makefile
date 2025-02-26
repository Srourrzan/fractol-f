# _*_ MakeFile _*_

NAME = fractol
SRCS = main.c mlx_utils.c std_utils.c finish_utils.c parse_args.c fractol_utils.c mandelbrot.c julia.c
OBJ_DIR = obj

OBJS = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -lX11 -lXext 

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(MLX_FLAGS)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ 

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	
re: fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJS)
	rm -rf $(OBJ_DIR)

.PHONY: all clean fclean re