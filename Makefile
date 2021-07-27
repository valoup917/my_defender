##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## .
##

CC = gcc

SRC =   src/window.c 	\
		src/move_rect.c 	\
		src/life_texture.c 	\
		src/enemies.c 		\
		src/manage_tower.c 	\
		src/free_all.c 		\
		src/move_pos_enemiesnlife.c 	\
		src/background.c 	\
		src/struct_creation_sprite.c 	\
		src/score.c 	\
		src/all_image.c	\
		src/main_menu.c	\
		src/loose_menu.c	\
		src/pause_menu.c	\
		src/man_function.c	\
		src/menu_management.c	\
		lib/my_revstr.c 	\
		lib/my_strcat.c 	\
		lib/my_strlen.c 	\
		lib/my_strcmp.c 	\


OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -pedantic -pg -g3

LDFLAGS = -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

CPPFLAGS = -I./include

NAME = my_defender

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ) $(OBJ_MAIN)

fclean: clean
	rm -f *gmon*
	rm -f $(NAME)
	rm -f *~
	rm -f *#
	rm -f src/*~
	rm -f src/\*#
	rm -f include/*~
	rm -f include/*#

re: fclean all

.PHONY: all clean fclean re
