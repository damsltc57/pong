##
## Makefile for Makefile in /home/dams/delivery/Igraph/raytracer1/
##
## Made by Damien Laurent
## Login   <damien.laurent@epitech.eu@epitech.eu>
##
## Started on  Wed Feb  8 14:38:50 2017 Damien Laurent
## Last update Wed Apr  5 19:52:26 2017 Damien Laurent
##
SRCS	=	main.c			\
				my_init_window.c	\
				move_player.c
.SILENT:

OBJ	=	$(SRCS:.c=.o)

NAME	=	pong

CC	=	gcc -g -Wextra -Wall -O3

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -lc_graph_prog_full -lm

clean:
		rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
