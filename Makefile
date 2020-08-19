NAME = fractol

CC = gcc
FLAGS = -Wall -Werror -Wextra -O2
LIBS = -lmlx -lm -lft -L$(LIBFT_DIR) -L$(MINILIBX_DIR) -framework OpenGL -framework AppKit
INC = -I$(HEADERS_DIR) -I$(LIBFT_HEADERS) -I$(MINILIBX_HEADERS)

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./libft/
LIBFT_HEADERS = $(LIBFT_DIR)includes/

MINILIBX = $(MINILIBX_DIR)libmlx.a
MINILIBX_DIR = ./minilibx/
MINILIBX_HEADERS = $(MINILIBX_DIR)

HEADERS_LIST = fractol.h
HEADERS_DIR = ./includes/
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

SRCS_DIR = ./sources/
SRCS_LIST = main.c art.c keyboard.c control.c control2.c menu.c colortheme.c fractols.c mouse.c util.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))

OBJ_DIR = objects/
OBJ_LIST = $(patsubst %.c, %.o, $(SRCS_LIST))
OBJ	= $(addprefix $(OBJ_DIR), $(OBJ_LIST))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJ_DIR) $(OBJ)
	@$(CC) $(FLAGS) $(LIBS) $(INCLUDES) $(OBJ) -o $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRCS_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INC) $< -o $@

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIR)

$(MINILIBX):
	@$(MAKE) -sC $(MINILIBX_DIR)

clean:
	@$(MAKE) -sC $(MINILIBX_DIR) clean
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(MINILIBX)
	@rm -f $(LIBFT)
	@rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all