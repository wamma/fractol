# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 15:21:03 by hyungjup          #+#    #+#              #
#    Updated: 2023/03/30 17:02:43 by hyungjup         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc
CFLAG = -Wall -Wextra -Werror
RM = rm -f
MLX = -L. -lmlx -framework OpenGL -framework AppKit

SRCS = ./srcs/main.c\
	   ./srcs/error.c\
	   ./srcs/fractol_draw.c\
	   ./srcs/fractol_type.c\
	   ./srcs/fractol_utils.c\
	#    ./srcs/fractol_hook.c\


OBJS = $(SRCS:.c=.o)

HEADER = fractol.h

all : $(NAME)

$(NAME): $(OBJS)
	@make -C mlx
	mv ./mlx/libmlx.dylib ./libmlx.dylib
	@$(CC) $(CFLAG) -o $@ $^ $(MLX)

%.o : %.c $(HEADER)
	@$(CC) $(CFLAG) -c $< -o $@


clean :
	@$(RM) $(OBJS)
	@make -C ./mlx clean
	@rm ./libmlx.dylib
	@echo "$(YELLOW)object files deleted!"

fclean : clean
	@$(RM) $(NAME)
	@make clean -C mlx
	@$(RM) libmlx.dylib
	@echo "$(RED)all deleted"

test :
	make -C mlx
	mv ./mlx/libmlx.dylib ./libmlx.dylib
	gcc -g $(SRCS) $(MLX)

re : fclean all

.PHONY : all clean fclean re

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[0;33m