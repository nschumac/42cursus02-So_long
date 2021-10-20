NAME = so_long

LIBFT = ./42cursus00-libft

GETNEXTLINE = ./42cursus01-Get_next_line/sources

SOURCES =	sources/ft_helper.c								\
			sources/ft_init.c								\
			sources/ft_map.c								\
			sources/ft_resize.c								\
			sources/so_long.c								\
			$(GETNEXTLINE)/get_next_line_bonus.c			\
			$(GETNEXTLINE)/get_next_line_utils_bonus.c		\

FLAGS =  -Wall -Werror -Wextra

MLX = ./mlx

OBJECTS = $(SOURCES:.c=.o)

%.o: %.c
	@$(CC) $(CCFLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJECTS)
	@make bonus --directory=$(LIBFT)
	@make --directory=$(MLX)
	@$(CC) $(FLAGS) $(OBJECTS) $(LIBFT)/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo so_long built!

clean:
	@make clean --directory=$(LIBFT)
	@make clean --directory=$(MLX)
	@rm -rf $(OBJECTS)

fclean: clean
	@make fclean --directory=$(LIBFT)
	@make fclean --directory=$(MLX)
	@rm -rf $(OBJECTS) $(NAME)

re: fclean $(NAME)