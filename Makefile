#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/02 13:58:30 by dlyubich          #+#    #+#              #
#    Updated: 2018/05/02 13:58:31 by dlyubich         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

BLUE = echo "\033[0;36m"
RED = echo "\033[0;34m"
GREEN = echo "\033[0;32m"
END = echo "\033[0m"

NAME = filler
NAME_VIS = visualizer

FLAGS = -Wall -Wextra -Werror

SRC = main.c \
			helper.c \
			solution.c \
			solution_helper.c \
			func.c
OBJ = $(SRC:.c=.o)
GCFLAGS = -I -I./libft/

SRC_VIS = filler_visual.c \
			print_map.c \
			solution.c \
			func.c \
			helper.c \
			solution_helper.c
OBJ_VIS = $(SRC_VIS:.c=.o)
GCFLAGS_VIS = -I -I./libft/

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$$($(BLUE))FILLER : Sources compiling...$$($(END))"
	@make -C libft/
	-gcc $(FLAGS) $(GCFLAGS) -o $@ $(OBJ) $(LIBFT)
	@echo "$$($(GREEN))FILLER : compile with SUCCESS!$$($(END))"

$(OBJ_PATH_P)%.o: $(SRC_PATH_P)%.c
	-gcc $(FLAGS) $(GCFLAGS) -o $@ -c $<

visual: $(NAME_VIS)

$(NAME_VIS): $(OBJ_VIS)
	@echo "$$($(BLUE))VISUALIZER : Sources compiling...$$($(END))"
	@make -C libft/
	-gcc $(FLAGS) $(GCFLAGS_VIS) -o $@ $(OBJ_VIS) $(LIBFT)
	@echo "$$($(GREEN))VISUALIZER : compile with SUCCESS!$$($(END))"

libft/libft.a :
	@make -C libft

clean:
	@make -C libft/ clean
	rm -f $(OBJ)
	rm -f $(OBJ_VIS)
	@echo "$$($(RED))Objects removed...$$($(END))"

fclean: clean
	@make -C libft/ fclean
	rm -f $(NAME)
	rm -f $(NAME_VIS)
	@echo "$$($(RED))filler binary removed...$$($(END))"

re: fclean all
