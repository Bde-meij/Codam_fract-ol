CC = gcc
NAME = fractol
SRC = src/main.c src/fractol.c src/controls.c
OBJ = $(SRC:.c=.o)

all: $(OBJ)
	cd MLX42; cmake -B build; cmake --build build -j4
	cd libft; make
	$(CC) $(OBJ) libft/libft.a MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm -o $(NAME)

fclean:
	cd libft; make fclean
	cd MLX42/build; make clean; cd ..; rm -rf build;
	rm -f $(NAME) $(OBJ)