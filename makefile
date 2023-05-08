#-pthread should be put after gcc, now it has been set up in vscode in tasks.json
NAME	= philosophers
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

HEADER	= philosophers.h

SRCS	= src/philosophers.c src/parsing.c src/msg_util.c src/starter.c src/print_status.c src/utils.c
OBJS	= $(SRCS:.c=.o)
OBJ_DIR = obj

%.o: %.c
		${CC} ${CFLAGS} -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJ_DIR) $(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) -pthread -o $(NAME)
			mv src/*.o ./obj

$(OBJ_DIR):
			mkdir $(OBJ_DIR)

clean:
		@$(RM) obj/

fclean:	clean
		@$(RM) $(NAME)

re:		fclean all
