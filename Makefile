#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myarovoy <myarovoy@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/09 14:50:21 by myarovoy          #+#    #+#              #
#    Updated: 2018/11/09 14:50:22 by myarovoy         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = asm

CFLAGS = -Wall -Wextra -Werror
CFLAGS_INC = -I includes/
LIB = libft.a 

FILES = main.c \
		get_task.c \
		get_task1.c \
		get_task2.c \
		fill_core.c \
		fill_label.c \
		fill_label1.c \
		write_to_cor.c \
		op_tab.c \
		validation.c \
		validation1.c \
		validation2.c

.PHONY = all clean fclean clean re

FILLERSRCS	= $(addprefix src/, $(FILES))

OBJ = $(FILLERSRCS:.c=.o)

all: $(NAME)

$(OBJ): %.o: %.c
	@gcc -c $(CFLAGS) $(CFLAGS_INC) $< -o $@

$(NAME): $(OBJ)
	@make -f makefile.libft
	@gcc $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)
	@echo "\033[32mCreated asm, object files and library\033[0m"

clean:
	@rm -rf $(OBJ) $(LIBOBJ)
	@make -f makefile.libft clean

fclean: clean
	@rm -rf $(NAME)
	@make -f makefile.libft fclean
	@echo "\033[32mRemoved asm, object Files and library\033[0m"

re: fclean all
