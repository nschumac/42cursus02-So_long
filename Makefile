NAME = so_long

INCLUDES = so_long.h

SRC = *.c get_next_line/*.c

FLAGS =  -Wall -Werror -Wextra

LIBFT = ./libft

MLX = ./mlx

all: $(NAME)

$(NAME):
	make bonus --directory=$(LIBFT)
	make --directory=$(MLX)
	$(CC) $(FLAGS) $(SRC) libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	make clean --directory=$(LIBFT)
	make clean --directory=$(MLX)

fclean: clean
	make fclean --directory=$(LIBFT)
	make fclean --directory=$(MLX)
	rm -rf $(OBJECTS) $(NAME)

re: fclean $(NAME)