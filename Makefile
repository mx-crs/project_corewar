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

AS_NAME = asm
VM_NAME = corewar

CFLAGS = -Wall -Wextra -Werror
CFLAGS_INC = -I includes/
LIB = libft.a 

AS_FILES = main.c \
		get_task.c \
		get_task1.c \
		get_task2.c \
		fill_core.c \
		fill_label.c \
		fill_label1.c \
		write_to_cor.c \
		op_tab.c \
		congr_flag.c \
		validation.c \
		validation1.c \
		validation2.c

VM_FILES =	main.c \
			vm_initializer1.c \
			vm_initializer2.c \
			vm_initializer3.c \
			helper1.c \
			helper2.c \
			helper3.c \
			helper4.c \
			validator1.c \
			data_reader.c \
			outputter1.c \
			game1.c \
			game2.c \
			game3.c \
			game4.c \
			visualization1.c \
			visualization2.c\

.PHONY = all clean fclean clean re

AS_SRCS	= $(addprefix src/, $(AS_FILES))
VM_SRCS = $(addprefix vm_sources/, $(VM_FILES))

AS_OBJ = $(AS_SRCS:.c=.o)
VM_OBJ = $(VM_SRCS:.c=.o)

all: $(AS_NAME) $(VM_NAME)

$(AS_OBJ): %.o: %.c
	@gcc -c $(CFLAGS) $(CFLAGS_INC) $< -o $@

$(VM_OBJ): %.o: %.c
	@gcc -c $(CFLAGS) $(CFLAGS_INC) $< -o $@

$(AS_NAME): $(AS_OBJ)
	@make -f makefile.libft
	@gcc $(CFLAGS) -o $(AS_NAME) $(AS_OBJ) $(LIB)
	@echo "\033[32mCreated asm\033[0m"

$(VM_NAME): $(VM_OBJ)
	@gcc $(CFLAGS) -lncurses -o $(VM_NAME) $(VM_OBJ) $(LIB)
	@echo "\033[32mCreated corewar\033[0m"

clean:
	@rm -rf $(AS_OBJ) $(LIBOBJ) $(VM_OBJ)
	@make -f makefile.libft clean

fclean: clean
	@rm -rf $(AS_NAME) $(VM_NAME)
	@make -f makefile.libft fclean
	@echo "\033[32mRemoved corewar, asm, object Files and library\033[0m"

re: fclean all
