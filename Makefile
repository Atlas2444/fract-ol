NAME = fractol
SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INC = -I.

RM = rm -f


MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: $(MLX_LIB) $(NAME)

$(MLX_LIB):
	@echo "Compiling MLX..."
	@make -C $(MLX_DIR)


$(NAME): $(OBJS) $(MLX_LIB)
	@echo "Linking $(NAME)..."
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)
	@echo "Built $(NAME)"

%.o: %.c
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@echo "Removing object files..."
	$(RM) $(OBJS)
	@make clean -C $(MLX_DIR)

fclean: clean
	@echo "Removing executable..."
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re