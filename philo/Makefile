# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/22 11:23:12 by kaisuzuk          #+#    #+#              #
#    Updated: 2025/11/23 13:39:25 by kaisuzuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo
CC		=	cc
FLAG	=	-Wall -Werror -Wextra

RM		=	rm -rf

SRCS	=	main.c \
			general.c \
			valid.c \
			parse.c \
			init.c \
			thread_routine.c \
			set.c \
			error.c \
			dispose.c \
			xmalloc.c 

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(FLAG) $(OBJS)

%.o: %.c
	$(CC) -c  $(INC) $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: clean fclean all