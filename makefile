# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 15:21:03 by hyungjup          #+#    #+#              #
#    Updated: 2023/03/29 19:27:36 by hyungjup         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

HEADER = fractol.h

CC = cc
CFLAG = -Wall -Wextra -Werror
RM = rm -f
LIB_DIR = ./libft
LIBFLAG = -lft -L$(LIB_DIR)
MLX = -L./mlx -lmlx -framework OpenGL -framework AppKit

SRCS_DIR =	./srcs
OBJS_DIR = ./objs

SRCS = ./srcs/main.c\
	   ./srcs/fractol_type.c\
	   ./srcs/fractol_draw.c\
	   ./srcs/error.c

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

vpath %.c $(SRCS_DIR)

all : $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIB_DIR)
	@make -C mlx
	@$(CC) $(CFLAG) $(MLX) $(LIBFLAG) $(OBJS) -o $(NAME)

%.o : %.c $(HEADER)
	@${CC} ${CFLAG} -c $< -o $@

$(OBJS_DIR) :
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o : %.c | $(OBJS_DIR)
	@$(CC) $(CFLAG) -o $@ -I$(INC_DIR) -I$(LIBFT_DIR) -c $^

clean :
	@$(RM) $(RMFLAG) $(OBJS)
	@make -C $(LIB_DIR) clean
	@make -C ./mlx clean
	@rm -f make_mandatory
	@$(RM) -r $(OBJS_DIR)
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