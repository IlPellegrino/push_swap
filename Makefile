# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nromito <nromito@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 11:04:09 by nromito           #+#    #+#              #
#    Updated: 2024/03/22 11:44:15 by nromito          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = sorting.c moves.c sorting_2.c stack_utils.c stack_ordinating.c commands_swap.c commands_push.c commands_r.c commands_rr.c algos.c main.c clean_and_error.c

OBJS = ${SRCS:.c=.o}

PUSH_SWAP_H = push_swap.h

LIBFT_PATH = libft/
LIBFT = libft/libft.a

NONE = '\033[0m'
RED = '\033[0;31m'
GREEN = '\033[0;32m'
YELLOW = '\033[0;33m'
BLUE = '\033[0;34m'

COMPILE = cc -Wall -Wextra -Werror -g

all: ${NAME}

${NAME}: ${OBJS} $(PUSH_SWAP_H)
		make -C ${LIBFT_PATH}
		$(COMPILE) $(OBJS) $(LIBFT) -o $(NAME)
		@echo $(GREEN)"Mandatory Compiled! Great Job out there mate!"$(NONE)

%.o: %.c
	$(COMPILE) -c $< -o $@

clean:
		@rm -rf $(OBJS)
		@make -C $(LIBFT_PATH)
		@echo $(BLUE)"Successfully cleaned!"$(NONE)

fclean: clean
		@rm -rf $(NAME)
		@make fclean -C $(LIBFT_PATH)
		@echo $(BLUE)"Successfully Fcleaned!"$(NONE)

leaks: all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) here_doc here "cat" "wc" outfile 2> leak_report
	@rm -rf *.o
	@echo $(GREEN)"LEAK REPORT GENERATED!"$(NONE)

re: fclean all

.PHONY: all clean fclean