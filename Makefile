
NAME 	= so_long

CC 		= gcc

CFLAGS 	= -Wall -Wextra -Werror 

SRCS = so_long.c split.c mlx.c get_next_line.c get_next_line_utils.c parsing.c flood_fill.c validation.c functions.c error_and_free.c draw_map.c itoa.c WASD.c trim_functions.c 

all: $(NAME)

OBJS	= $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(CC) -lmlx -framework OpenGL -framework AppKit  $^ -o $@ 

%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all 

