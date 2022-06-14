##
## EPITECH PROJECT, 2021
## MakeFile
## File description:
## make
##

CC = gcc

SRC =	src/main.c \
		src/more_fct_main.c \
		src/lib/str_to_str_array.c \
		src/lib/my_putchar.c \
		src/lib/my_putstr.c \
		src/lib/my_strcmp.c \
		src/lib/my_getnbr.c \
		src/lib/my_strlen.c \
		src/builtin/my_cd.c \
		src/builtin/my_cd2.c \
		src/builtin/my_builtin.c \
		src/builtin/my_env.c \
		src/builtin/my_env2.c \
		src/builtin/my_env3.c \
		src/builtin/my_env4.c \
		src/command/get_path.c \
		src/command/commandexecutor2.c \
		src/command/commandexecutor.c \
		src/command/error_execute.c

OBJS = $(SRC:.c=.o)

RM = rm -f

CFLAGS = -W -Wall -Wextra -Werror -g -I./include

NAME = mysh

all: 	$(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all