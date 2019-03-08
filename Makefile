# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: badhont <badhont@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/08 17:31:09 by asamir-k          #+#    #+#              #
#    Updated: 2019/03/08 18:41:08 by badhont          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= wolf3d
GCC= GCC
HEADER= INCLUDES/wolf3d.h
FLAGS = -Wall -Werror -Wextra
LIB_PATH= INCLUDES/libft/
COMP= SDL2
SDLLIB= -L mlx -lmlx -framework Opengl -framework Appkit
SRC=SRCS/main.c				\
	SRCS/ft_wolf_loop.c		\
	SRCS/events.c			\
	SRCS/ft_minimap.c \
	SRCS/ft_parsing.c			\
	SRCS/linedrawer.c		\
	SRCS/ft_outils.c		\
	SRCS/ft_raycasting.c	\
	SRCS/crosshair.c \
	SRCS/ft_new_surface.c \
	SRCS/ft_exit.c \

OBJ = $(SRC:.c=.o)
# SDL
LSDL_LIB	:=	$(shell sdl2-config --libs)
LSDL_INC	:=	$(shell sdl2-config --cflags)
LIB			:=	$(LSDL_LIB)
INC			:=	$(LSDL_INC)

all: $(NAME)

$(OBJ): %.o: %.c $(HEADER)
	gcc $(FLAGS) -o $@ -c $< -I $(LIB_PATH) -I ../INCLUDES $(INC)

$(NAME): $(OBJ) $(LIB_PATH)libft.a
	gcc -o $(NAME) $(OBJ) -lm -L $(LIB_PATH) -lft -I $(COMP) $(INC) -lm $(LIB) -lSDL2 -lSDL2_ttf -lSDL2_image
	@echo "\033[1;34;2m FRIED CHICKEN READY TO BE EATEN ~ (__)=3 ~\033[0m"
	@echo "\033[0;31;3m                        (ALL RULE DONE)                               ~ (__)=3 ~\033[0m"

$(LIB_PATH)libft.a :
	make -C $(LIB_PATH)
clean:
	@rm -f $(OBJ)
	@echo "\033[1;33;2m IVE EATEN HALF OF THE CHICKEN , ONE WORD AND WINGS ERADICATION WILL BE ORDERED \033[0m"
	@echo "\033[0;31;3m                        (CLEAN RULE DONE)                             ~ (__)=3 ~ \033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;31;2m JOB DONE SERGEANT WingZLord NO MORE WINGS ARE DETECTED IN THE bckt (-_-)ゞ\033[0m"
	@echo "\033[0;31;3m                        (FCLEAN RULE DONE)                            ~ (__)=3  ~\033[0m"

re: fclean all
	@echo "\033[0;35;2m BTW I'VE SUCCESSFULLY REFILL 24 WINGS JUST FOR YOU (♥_♥)ゞ\033[0m"
	@echo "\033[0;31;3m                        (RE RULE DONE)                                ~ (__)=3  ~\033[0m"
