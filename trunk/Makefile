##
## Makefile for project in /u/all/ancel_a/cu/travail/c/
##
## Made by francois1 ancel
## Login   <ancel_a@epitech.net>
##
## Started on  Fri Mar 26 22:19:44 2010 francois1 ancel
## Last update Fri Mar 26 22:19:44 2010 francois1 ancel
##

NAME	= prog
CC	= gcc
RM	= rm -rf
SRCS	= err.c			\
	exec_fct.c		\
	image_fct.c		\
	key_func.c		\
	init_player.c		\
	keydown.c		\
	map.c			\
	main.c			\
	npc.c			\
	windows.c		\
	xio.c

OBJS	= $(SRCS:.c=.o)
CFLAGS	= -W -Wall -Wextra -O3 -ansi -pedantic
LDFLAGS	= -lSDLmain -lSDL

$(NAME)	: $(OBJS)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJS)

all	: $(NAME)

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all