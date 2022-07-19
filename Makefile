# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 10:12:21 by kbrousse          #+#    #+#              #
#    Updated: 2022/07/19 00:09:37 by kbrousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = libft/libft.a

SRC = main.c						\
	check_args.c					\
	clear_program.c					\
	clear_program_good_ending.c		\
	fill_tab.c						\
	fill_stack_a.c					\
	verify_tab_data.c

INIT = init_program.c	\
	init_stacks.c

LL = ft_lstnew_ps.c			\
	ft_lstadd_front_ps.c

#INSTRUCTIONS =

SRCS = $(addprefix src/, $(SRC))						\
	 $(addprefix src/init/, $(INIT))					\
	 $(addprefix src/instructions/, $(INSTRUCTIONS))	\
	 $(addprefix src/LL/, $(LL))

CC =	gcc

FLAGS =	-Wall -Wextra -Werror -g

OBJS = $(SRCS:.c=.o)

all: $(NAME)

clean:
	rm -f $(OBJS)
	echo "\033[0;32m~*~*~*~*~*~*~*~*~*~*~*~*~*~*~"
	echo "*                           *"
	echo "~     Clean terminated!     ~"
	echo "*          so_long          *"
	echo "~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\033[0m"

fclean: clean
	make fclean -C libft --no-print-directory
	rm -f $(NAME) $(BONUS)

re: fclean all

.c.o:
	$(CC) $(FLAGS) -c -o $@ $< 
 
$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -Llibft -lft -Ilibft -o $(NAME)
	echo "\033[0;32m~*~*~*~*~*~*~*~*~*~*~*~*~*~*~"
	echo "*                           *"
	echo "~  Compilation terminated!  ~"
	echo "*          so_long          *"
	echo "~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\033[0m"

$(LIBFT):
	make -C libft --no-print-directory

.SILENT:
.PHONY: all clean fclean bonus re
