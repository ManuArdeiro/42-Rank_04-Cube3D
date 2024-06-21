# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/04 01:04:09 by Ardeiro           #+#    #+#              #
#    Updated: 2024/06/20 22:32:28 by jolopez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			=	cube

BONUS			=	0

vpath 			%.h	include : mlx_linux
vpath 			%.c	mlx_linux : src : src/game : src/parsing : src/utils : tests
vpath 			%.o	obj

INCLUDE 		=	-Iinclude/
INC_LIB 		=	-Iinclude/libft
SANITIZER		=	-g3 -fsanitize=address -g
LIBFT			= 	include/libft/libft.a
LIBFTDIR		= 	include/libft
OBJ_DIR			=	obj
RM 				=	/bin/rm -rf
CC 				= 	gcc
CFLAGS 			= 	-Wall -Werror -Wextra $(INCLUDE) $(SANITIZER)

#-------------------------- C Files -------------------------------------
BONUS			=	render_bonus.c

PARSING			=	checks.c colors.c map.c parse.c textures.c utils.c

RENDER			=	textures.c

UTILS			=	free_mem.c inits.c mlx.c print.c 

TESTS			=	printing.c

SRC 			=	$(GAME) $(PARSING) $(UTILS) $(TESTS) main.c

OBJS			=	$(SRC:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(@D)
	$(COMPILE.c) -DBONUS=$(BONUS) -I/usr/include -Imlx_linux -O3 $< -o $@

all: $(NAME)

$(NAME): 	$(LIBFT) $(OBJS)
			@echo "$(YELLOW) ...Creating Cube3D... $(WHITE)\n"
			$(CC) $(CFLAGS) -DBONUS=$(BONUS) $(OBJS) $(LIBFT) -Lmlx_linux
			 -lmlx_Linux -L/usr/lib  -lXext -lX11 -lm -lz -o $(NAME)
			@echo "\n$(LIGHT_GRAY)---------- Cube3D Ready ------------\n"

.SILENT:
$(LIBFT):
			echo "$(LIGHT_RED) ...Creating libft files... $(WHITE)\n"
			$(MAKE) -C $(LIBFTDIR)
			@echo "$(GREEN) ...libft created... $(WHITE)\n"

bonus:
		make all BONUS=1
	
clean:
		@echo "$(LIGHT_RED) Cleaning libft files... $(WHITE)\n"
		$(MAKE) clean -C $(LIBFTDIR) 
		/bin/rm -rf $(OBJS)

fclean: clean
		$(MAKE) fclean -C $(LIBFTDIR)
		$(RM) $(NAME) $(OBJ_DIR)
		@echo "$(GREEN) *** **** DONE **** *** $(WHITE)\n"
				

re: 	fclean all

.PHONY: all clean fclean re

# COLORS
RED				= \033[0;31m
GREEN			= \033[0;32m
YELLOW			= \033[0;33m
BLUE			= \033[0;34m
MAGENTA			= \033[0;35m
CYAN			= \033[0;36m
LIGHT_GRAY		= \033[0;37m
DARK_GRAY		= \033[0;90m
LIGHT_RED		= \033[0;91m
WHITE			= \033[0;97m

#SETS
BOLD			= \e[0;1m
UNDERLINED		= \e[0;4m
BLINK			= \e[0;5m