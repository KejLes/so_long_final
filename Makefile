# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcanales <kcanales@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/15 00:45:55 by kcanales          #+#    #+#              #
#    Updated: 2026/03/16 18:01:17 by kcanales         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
MLX42_DIR = libs/MLX42
MLX42 = $(MLX42_DIR)/build/libmlx42.a
MLX42_INC = $(MLX42_DIR)/include

LIBFT_DIR = libs/libft
LIBFTA = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = libs/ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

OBJ_DIR = obj
SRC_DIR = src
SRCS = $(SRC_DIR)/check_map_00.c $(SRC_DIR)/check_map_01.c $(SRC_DIR)/check_map_02.c \
       $(SRC_DIR)/check_map_03.c \
	   $(SRC_DIR)/initialize_game_struc_00.c $(SRC_DIR)/initialize_game_struc_01.c \
       $(SRC_DIR)/initialize_game_struc_02.c $(SRC_DIR)/initialize_game_struc_03.c \
	   $(SRC_DIR)/initialize_game_struc_04.c \
       $(SRC_DIR)/move_player_00.c $(SRC_DIR)/move_player_01.c $(SRC_DIR)/move_player_02.c \
	   $(SRC_DIR)/main.c \
	   $(SRC_DIR)/error_exit.c\
	   $(SRC_DIR)/utils.c \

OBJS = $(OBJ_DIR)/check_map_00.o $(OBJ_DIR)/check_map_01.o $(OBJ_DIR)/check_map_02.o \
       $(OBJ_DIR)/check_map_03.o \
	   $(OBJ_DIR)/initialize_game_struc_00.o $(OBJ_DIR)/initialize_game_struc_01.o \
       $(OBJ_DIR)/initialize_game_struc_02.o $(OBJ_DIR)/initialize_game_struc_03.o \
	   $(OBJ_DIR)/initialize_game_struc_04.o \
       $(OBJ_DIR)/move_player_00.o $(OBJ_DIR)/move_player_01.o $(OBJ_DIR)/move_player_02.o \
	   $(OBJ_DIR)/main.o \
       $(OBJ_DIR)/error_exit.o\
	   $(OBJ_DIR)/utils.o\

INCLUDE = so_long.h

OS = $(shell uname)
ifeq ($(OS), Linux)
	MLX_FLAGS = -lglfw -lm -ldl -lX11 -lpthread -lXrandr -lXi
else
	MLX_FLAGS = -framework Cocoa -framework OpenGL -framework IOKit -lglfw
endif

all: $(NAME)

$(NAME): $(LIBFTA) $(MLX42) $(FT_PRINTF) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFTA) $(FT_PRINTF) $(MLX42) $(MLX_FLAGS) -I$(MLX42_INC) -o $(NAME)
	@echo "		Compilado so_long\n"

$(LIBFTA):
	@make -C $(LIBFT_DIR)
	@echo "		Compilado LIBFT\n"

$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR)
	@echo "		Compilado LIBFT_PRINTF\n"

$(MLX42):
	@cmake -B $(MLX42_DIR)/build $(MLX42_DIR)
	@cmake --build $(MLX42_DIR)/build
	@echo "		Compilado MLX42\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(FT_PRINTF_DIR)
	@echo "		Limpieza de archivos objeto."

fclean: clean
	@$(RM) $(NAME)
	@rm -rf $(MLX42_DIR)/build
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(FT_PRINTF_DIR)
	@echo "		Limpieza total (ejecutables y librerías)."

re: fclean all

norminette:
	@norminette $(SRCS) ./so_long.h

.PHONY: all clean fclean re
