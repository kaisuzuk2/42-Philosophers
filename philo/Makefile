# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/22 11:23:12 by kaisuzuk          #+#    #+#              #
#    Updated: 2025/11/27 10:15:54 by kaisuzuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo
CC		=	cc
FLAG	=	-Wall -Werror -Wextra -g

DEBUG	=	-fsanitize=thread

RM		=	rm -rf

INC		=	-Iincludes
SRC_DIR	=	srcs
_SRCS	=	main.c \
			general.c \
			valid.c \
			parse.c \
			parse_utils.c \
			init.c \
			routine_philo.c \
			routine_monitor.c \
			thread_routine_utils.c \
			get.c \
			set.c \
			check.c \
			error.c \
			dispose.c \
			xmalloc.c 
SRCS	=	$(addprefix $(SRC_DIR)/, $(_SRCS))

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(INC) $(FLAG)  $(OBJS)

%.o: %.c
	$(CC) -c  $(INC) $(FLAG) $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: clean fclean all