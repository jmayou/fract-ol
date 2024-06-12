NAME = fractol

BONUS_NAME = fractol_bonus

CC = cc

MLX_FLAGS = -I /usr/local/include/ -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Wextra -Werror

SRC = mandatory/hooks.c mandatory/sets.c mandatory/utilise.c mandatory/main.c

BSRC = bonus/hooks_bonus.c bonus/sets_bonus.c bonus/utilise_bonus.c bonus/main_bonus.c

OBJ = $(SRC:.c=.o)

BOBJ = $(BSRC:.c=.o)

RM = rm -rf 

all : $(NAME)

$(NAME) : $(OBJ) mandatory/fractol.h
	make -C Libft
	$(CC) $(MLX_FLAGS) $(CFLAGS) $(OBJ) Libft/libft.a -o $(NAME)

bonus : $(BOBJ) bonus/fractol_bonus.h
	make -C Libft
	$(CC) $(MLX_FLAGS) $(CFLAGS) $(BOBJ) Libft/libft.a -o $(BONUS_NAME)

clean :
	make clean -C Libft 
	$(RM) $(OBJ) $(BOBJ)

fclean : clean
	make -C Libft fclean
	$(RM) $(NAME) $(BONUS_NAME)

re : fclean all
