# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsimonis <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/07 03:11:40 by tsimonis          #+#    #+#              #
#    Updated: 2019/03/04 00:00:39 by tsimonis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME := libpushswap.a
PUSH_SWAP := push_swap
CHECKER := checker

CFLAGS := -Wall -Werror -Wextra
INCS := .
CC := gcc

SRCS := checker.c ft_atoi_new.c read_args.c list_funcs.c free_argv.c \
		push_and_rotate.c stack_funcs.c push_swap.c ft_strsplit.c \
		print_command.c print_stack.c read_commands_addition.c read_commands.c \
		checker_addition.c push_swap_part_one.c push_swap_part_two.c \
		push_swap_part_three.c push_swap_part_four.c push_swap_part_five.c \
		push_swap_part_six.c push_swap_part_seven.c

CHECKER_SRCS := checker.c ft_atoi_new.c read_args.c list_funcs.c \
				push_and_rotate.c stack_funcs.c ft_strsplit.c free_argv.c \
				print_command.c print_stack.c read_commands_addition.c \
				read_commands.c checker_addition.c

PUSH_SWAP_SRCS := ft_atoi_new.c read_args.c list_funcs.c push_and_rotate.c \
				push_swap.c stack_funcs.c ft_strsplit.c free_argv.c \
				print_command.c print_stack.c checker_addition.c \
				push_swap_part_one.c push_swap_part_two.c \
				push_swap_part_three.c push_swap_part_four.c \
				push_swap_part_five.c push_swap_part_six.c \
				push_swap_part_seven.c

OBJS := $(SRCS:%.c=%.o)
CHECKER_OBJS := $(CHECKER_SRCS:%.c=%.o)
PUSH_SWAP_OBJS := $(PUSH_SWAP_SRCS:%.c=%.o)

all: $(NAME)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCS)

$(NAME): $(OBJS) $(PUSH_SWAP) $(CHECKER)
	@ar rc $(NAME) $(OBJS)

$(PUSH_SWAP): $(PUSH_SWAP_OBJS)
	cd printf && make
	$(CC) $(CFLAGS) -o $(PUSH_SWAP) $(PUSH_SWAP_OBJS) -L./printf/ -lftprintf

$(CHECKER): $(CHECKER_OBJS)
	$(CC) $(CFLAGS) -o $(CHECKER) $(CHECKER_OBJS) -L./printf/ -lftprintf

clean:
	/bin/rm -f $(PUSH_SWAP_OBJS) $(CHECKER_OBJS)
	cd printf && make clean

fclean: clean
	/bin/rm -f $(NAME) $(PUSH_SWAP) $(CHECKER)
	cd printf && make fclean

re: fclean all
