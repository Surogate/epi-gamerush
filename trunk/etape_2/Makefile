##
## Makefile for project in /u/all/ancel_a/cu/travail/c/
##
## Made by francois1 ancel
## Login   <ancel_a@epitech.net>
##
## Started on  Fri Mar 26 22:19:44 2010 francois1 ancel
## Last update Fri Mar 26 22:19:44 2010 francois1 ancel
##

NAME	= epikong_etape_2
OSNAME	= $(shell uname -s)
OSNAME	!= uname -s
CC	= gcc
RM	= rm -rf
SRCS	= err.c			\
	menu/menu_exec.c	\
	menu/menu_fct.c		\
	display.c		\
	exec_fct.c		\
	image_fct.c		\
	key_func.c		\
	act.c			\
	act2.c			\
	init_player.c		\
	keydown.c		\
	map.c			\
	back_to_start.c		\
	main.c			\
	npc.c			\
	windows.c		\
	monster.c		\
	press_key.c		\
	xio.c

OBJS	= $(SRCS:.c=.o)
CFLAGS	= -W -Wall -Wextra -ansi -pedantic -I. -Imenu
LDFLAGS_Linux	= -lSDLmain -lSDL -lSDL_ttf
LDFLAGS_FreeBSD	= -L/usr/local/lib -Wl,-rpath,/usr/local/lib -lSDL -lpthread -lSDL_ttf

$(NAME)	: $(OBJS)
	$(CC) $(LDFLAGS_$(OSNAME)) -o $(NAME) $(OBJS)

all	: $(NAME)

.c.o	: 
	$(CC) $(CFLAGS) -c -o $@ $<

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all