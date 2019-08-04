# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hghandi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/28 20:23:54 by hghandi           #+#    #+#              #
#    Updated: 2019/07/28 20:26:30 by hghandi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wextra -Wall -Werror
EXEC = ft_printf
SRC = srcs/*.c
OBJ = *.o

all: $(EXEC)

$(EXEC):
	@gcc -c $(SRC) srcs/libft/*.c
	@ar rc libftprintf.a *.o
	@rm -rf *.o
	@echo "\033[0;31m\033[0;32m Compilation without errors ^_^ \033[0;31m"

clean:
	@rm -rf OBJTS
	@rm -f $(OBJ)
fclean: clean
		@rm -f $(EXEC)

re: fclean all
