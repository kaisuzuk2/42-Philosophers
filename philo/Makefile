# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/22 11:23:12 by kaisuzuk          #+#    #+#              #
#    Updated: 2025/11/24 14:34:24 by kaisuzuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo
CC		=	cc
FLAG	=	-Wall -Werror -Wextra -g

DEBUG	=	-fsanitize=thread

RM		=	rm -rf

SRCS	=	main.c \
			general.c \
			valid.c \
			parse.c \
			init.c \
			thread_routine.c \
			get.c \
			set.c \
			print_state.c \
			error.c \
			dispose.c \
			xmalloc.c 

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(FLAG)  $(OBJS)

%.o: %.c
	$(CC) -c  $(FLAG) $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: clean fclean all