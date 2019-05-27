# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/21 18:55:40 by matheme      #+#   ##    ##    #+#        #
#    Updated: 2019/03/21 15:48:26 by matheme     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME		= fdf

SRC_PATH	= src
SRC_NAME	=	main.c \
				error.c \
				validate.c \
				help_prog.c \
				algo_bresenham.c \
				show.c \
				event.c
OBJ_PATH    = ./obj
OBJ_NAME	= $(SRC_NAME:.c=.o)
INC_PATH	= include/

CC			= gcc

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

CFLAGS		= -Wall -Werror -Wextra

LIBS		= Librairies
LIBFT		= $(LIBS)/libft/
MINILIBX	= $(LIBS)/minilibx/
MINILIBX.A	= $(MINILIBX)libmlx.a
LIBFT.A		= $(LIBFT)libft.a
FRAMEWORKS	= -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME): $(OBJ) $(MINILIBX.A) $(LIBFT.A)
	@$(CC) -I $(MINILIBX) -L $(MINILIBX) -I $(LIBFT) -L $(LIBFT) $^ -o $@ $(FRAMEWORKS)
	@echo "\033[0;32m [--- COMPILATION TERMINEE ---] \033[0m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
		@echo "\033[0;32m [OK] \033[0m       \033[0;33m Compiling:\033[0m" $<
		
		@mkdir $(OBJ_PATH) 2> /dev/null || true
		@$(CC) -I $(MINILIBX) -I $(LIBFT) -I $(INC_PATH) $(CFLAGS) -c $< -o $@

$(MINILIBX.A) :
	@make -C $(MINILIBX)

$(LIBFT.A) :
	@make -C $(LIBFT)

clean:
	@rm -fv $(OBJ)
	@rm -rf $(MINILIBX)*.o
	@make -C $(LIBFT) clean
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@make -C $(LIBFT) fclean
	@make -C $(MINILIBX) clean
	@rm -fv $(NAME)
	@echo "\033[0;31m [--- EXECUTABLE SUPPRMER ---] \033[0m"

re: fclean all
