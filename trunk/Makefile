##
## Makefile for project in /u/all/ancel_a/cu/travail/c/
##
## Made by francois1 ancel
## Login   <ancel_a@epitech.net>
##
## Started on  Fri Mar 26 20:38:14 2010 francois1 ancel
## Last update Fri Mar 26 20:38:14 2010 francois1 ancel
##

NAME	= prog
CC	= gcc
RM	= rm -rf
SRCS	= main.c

OBJS	= $(SRCS:.c=.o)
CFLAGS	= -W -Wall -Wextra -O3 -ansi
LDFLAGS	= -lc

$(NAME)	: $(OBJS)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJS)

all	: $(NAME)

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all