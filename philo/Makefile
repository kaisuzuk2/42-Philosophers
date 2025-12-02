# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/22 11:23:12 by kaisuzuk          #+#    #+#              #
#    Updated: 2025/12/02 13:53:05 by kaisuzuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo
CC		=	cc
FLAG	=	-Wall -Werror -Wextra

RM		=	rm -rf

INC		=	-Iincludes
SRC_DIR	=	srcs
_SRCS	=	general.c \
			valid.c \
			parse.c \
			parse_utils.c \
			init.c \
			init_utils.c \
			routine_philo.c \
			routine_philo_utils.c \
			routine_monitor.c \
			routine_monitor_scheduler.c \
			quick_sort.c \
			routine_utils.c \
			get.c \
			set.c \
			check.c \
			error.c \
			xmalloc.c \
			dispose.c

SRCS	=	$(addprefix $(SRC_DIR)/, $(_SRCS))

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) main.c $(INC) $(FLAG) $(OBJS)

%.o: %.c
	$(CC) -c  $(INC) $(FLAG) $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: clean fclean all re