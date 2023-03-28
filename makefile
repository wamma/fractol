# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 15:21:03 by hyungjup          #+#    #+#              #
#    Updated: 2023/03/28 19:38:54 by hyungjup         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc
CFLAG = -Wall -Wextra -Werror -g
RM = rm -f
LIB_DIR = ./libft
LIBFLAG = -lft -L$(LIB_DIR)
MLX = -L./mlx -lmlx -framework OpenGL -framework AppKit

SRCS = ./srcs/main.c\
	   ./srcs/fractol_type.c\
	   ./srcs/fractol_draw.c\
	   ./srcs/error.c

OBJS = $(SRCS:.c=.o)

HEADER = fractol.h

all : $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIB_DIR)
	@make -C mlx
	@$(CC) $(CFLAGS) $(MLX) $(LIBFLAG) $(OBJS) -o $(NAME)

%.o : %.c $(HEADER)
	@${CC} ${CFLAG} -c $< -o $@

clean :
	@$(RM) $(RMFLAG) $(OBJS)
	@make -C $(LIB_DIR) clean
	@make -C ./mlx clean
	@rm -f make_mandatory
	@echo "$(YELLOW)object files deleted!"

fclean : clean
	@$(RM) $(NAME)
	@make -C $(LIB_DIR) fclean
	@make clean -C mlx
	@echo "$(RED)all deleted"

re : fclean all

.PHONY : all clean fclean re

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[0;33m