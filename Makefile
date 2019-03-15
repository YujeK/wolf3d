NAME 		= wolf3d
CC			= gcc
CFLAGS 		= -Wall -Wextra -Werror -O3 #-g -fsanitize=address

ID_UN 		= $(shell id -un)
SRC_PATH 	= srcs/
OBJ_PATH 	= objs/
INC_PATH	= includes/ \
				libft/includes/
LIBFT 		= libft/

WHITE       = "\\033[0m"
CYAN        = "\\033[36m"
GREEN       = "\\033[32m"

SDL_NUM		= $(shell ls /Users/$(ID_UN)/.brew/Cellar/sdl2/ | tail -1)
TTF_NUM		= $(shell ls /Users/$(ID_UN)/.brew/Cellar/sdl2_ttf/ | tail -1)
IMG_NUM		= $(shell ls /Users/$(ID_UN)/.brew/Cellar/sdl2_image/ | tail -1)
MIX_NUM		= $(shell ls /Users/$(ID_UN)/.brew/Cellar/sdl2_mixer/ | tail -1)

INC_PATH	+=	/Users/$(ID_UN)/.brew/Cellar/sdl2/$(SDL_NUM)/include/ \
				/Users/$(ID_UN)/.brew/Cellar/sdl2/$(SDL_NUM)/include/SDL2/ \
				/Users/$(ID_UN)/.brew/Cellar/sdl2_ttf/$(TTF_NUM)/include/ \
				/Users/$(ID_UN)/.brew/Cellar/sdl2_image/$(IMG_NUM)/include/ \
				/Users/$(ID_UN)/.brew/Cellar/sdl2_mixer/$(MIX_NUM)/include/

SRC_NAME 	= 	main.c \
				ft_crosshair.c \
				events.c \
				ft_exit.c \
				ft_minimap.c \
				ft_new_surface.c \
				ft_outils.c \
				ft_parsing.c \
				ft_raycasting.c \
				ft_wolf_loop.c \
				linedrawer.c \
				ft_ui.c \
				ft_text_utils.c \
				ft_inventory.c \

OBJ_NAME = $(SRC_NAME:.c=.o)
LSDL2 	 = -L/Users/$(ID_UN)/.brew/lib/ -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
	@Make -C $(LIBFT)
	@printf "$(CYAN)[WAIT]$(WHITE) Compiling into %-50s\r" $(NAME)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L$(LIBFT) -lft $(INC) $(LSDL2)
	@printf "$(GREEN)[OK]$(WHITE) %s has been well compiled\n" $(NAME)

$(OBJ) : | $(OBJ_PATH)

$(OBJ_PATH) :
	@mkdir objs

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INC_PATH) Makefile
	@printf "$(CYAN)[WAIT]$(WHITE) Compiling into .o %-50s\r" $@
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@make -C $(LIBFT) clean
	@rm -rf $(OBJ_PATH)
	@printf "$(GREEN)[OK]$(WHITE) Clean done\n"

fclean: clean
	@make -C $(LIBFT) fclean
	@rm -f $(NAME)
	@printf "$(GREEN)[OK]$(WHITE) Fclean done\n"

re: fclean all

.PHONY: all re clean fclean
