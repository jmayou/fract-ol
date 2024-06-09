NAME = fractol

CC = cc

MLX_FLAGS = -I /usr/local/include/ -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Wextra -Werror

SRC = hooks.c sets.c utilise.c main.c

OBJ = $(SRC:.c=.o)

RM = rm -rf 

all : $(NAME)

$(NAME) : $(OBJ) fractol.h
	make -C Libft
	$(CC) $(MLX_FLAGS) $(CFLAGS) $(OBJ) Libft/libft.a -o $(NAME)

clean :
	make clean -C Libft 
	$(RM) $(OBJ)

fclean : clean
	make -C Libft fclean
	$(RM) $(NAME)

re : fclean all
