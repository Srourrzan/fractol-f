# _*_ MakeFile _*_

TARGET = fractol
SRCS = main.c map_utils.c display_utils.c mlx_utils.c std_utils.c
OBJDIR = obj

OBJS = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -lX11 -lXext -lXrender
M_FLAGS = -lm 

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(M_FLAGS) $(OBJS) -o $(TARGET)
	touch output.txt trials.txt

test:
	@echo $(OBJS)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(M_FLAGS) -c $< -o $@ 

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	
re: fclean all

fclean: clean
	rm -f $(TARGET)

clean:
	rm -f $(OBJS)
	rm -rf $(OBJ_DIR)

.PHONY: all clean fclean re