# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 20:18:43 by yokamura          #+#    #+#              #
#    Updated: 2023/04/13 21:22:29 by yokamura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= push_swap
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror

SRCS	:= main.c ft_listmaker_and_check.c \
ft_split_and_atoi.c ft_error_and_free.c ft_num_to_order.c \
push_swap_utils.c ft_is_sorted.c ft_pa_pb.c ft_ra_rra.c \
push_swap.c push_swap_for_cinq.c push_swap_for_trois.c \
ft_sa.c ft_test.c 

OBJS	:= $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
