NAME		=	cub3D

SRC			=	srcs
SRC_BONUS	=	srcs_bonus
INC			=	includes
INC_BONUS	=	includes_bonus
OBJ			=	obj

LIB			=	lib
LIBFT		=	$(LIB)/libft
MLX_LINUX	=	$(LIB)/mlx_linux
MLX_MAC 	= 	$(LIB)/mlx_mac

CC			=	clang
CFLAGS		=	-Wall -Werror -Wextra -g

YELLOW 	= \033[0;33m
GREEN 	= \033[0;32m
RED 	= \033[0;31m
END 	= \033[0m

RM			=	rm -rf
MK			=	mkdir -p
NM			=	norminette

MAKE_DIR	= $(MAKE) -C

CFILES		=	main.c \
				get_next_line.c \
				parsing_info.c \
				parsing_map.c \
				parsing_map2.c \
				parsing_utils.c \
				start_mlx.c \
				keys_handle.c \
				draw.c \
				mlx_utils.c \
				move_player.c \
				rotate_player.c \
				draw_rt.c \
				draw_rt2.c \

CFILES_BONUS =	main_bonus.c \
				get_next_line_bonus.c \
				parsing_info_bonus.c \
				parsing_map_bonus.c \
				parsing_map2_bonus.c \
				parsing_utils_bonus.c \
				start_mlx_bonus.c \
				keys_handle_bonus.c \
				draw_bonus.c \
				mlx_utils_bonus.c \
				move_player_bonus.c \
				rotate_player_bonus.c \
				draw_rt_bonus.c \
				draw_rt2_bonus.c \
				draw_minimap_bonus.c \

HFILES		=	kub.h \
				struct.h \
				def.h \

HFILES_BONUS =	kub_bonus.h \
				struct_bonus.h \
				def_bonus.h \
				
OFILES		 =	$(CFILES:.c=.o)
OFILES_BONUS =	$(CFILES_BONUS:.c=.o)

SRCS			=	$(addprefix $(SRC)/, $(CFILES))
SRCS_BONUS		=	$(addprefix $(SRC_BONUS)/, $(CFILES_BONUS))
HEADERS			=	$(addprefix $(INC)/, $(HFILES))
HEADERS_BONUS	=	$(addprefix $(INC_BONUS)/, $(HFILES_BONUS))
OBJS			=	$(addprefix $(OBJ)/, $(OFILES))
OBJS_BONUS		=	$(addprefix $(OBJ)/, $(OFILES_BONUS))

VPATH		=	$(SRCS)

FRAMEWORKS_MAC 		= -lft -lmlx -lm -framework OpenGL -framework AppKit
FRAMEWORKS_LINUX 	= -lft -lmlx -lm -lXext -lbsd -lX11

$(OBJ)/%.o:	$(SRC)/%.c
			$(CC) $(CFLAGS) -I$(INC) -I$(LIB) -c $< -o $@

$(OBJ)/%.o:	$(SRC_BONUS)/%.c
			$(CC) $(CFLAGS) -I$(INC_BONUS) -I$(LIB) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJ) $(OBJS)
		@echo "$(GREEN) Compiling..."
		@$(MAKE_DIR) $(LIBFT)
		@$(MAKE_DIR) $(MLX_MAC)
		$(CC) $(OBJS) -L$(LIBFT) -L$(MLX_MAC) $(FRAMEWORKS_MAC) -o $(NAME)
		@echo "$(END)"
		@echo "$(GREEN)  Cub3D Compiled\n $(END)"

bonus :		bclean $(OBJ) $(OBJS_BONUS)
		@echo "$(GREEN) Compiling..."
		@$(MAKE_DIR) $(LIBFT)
		@$(MAKE_DIR) $(MLX_MAC)
		$(CC) $(OBJS_BONUS) -L$(LIBFT) -L$(MLX_MAC) $(FRAMEWORKS_MAC) -o $(NAME)
		@echo "$(END)"
		@echo "$(GREEN)  Cub3D Compiled\n $(END)"

$(OBJ):
			@$(MK) $(OBJ)

$(OBJ_BONUS):
			@$(MK) $(OBJ_BONUS)

linux:		$(OBJ) $(OBJS)
			@echo "$(GREEN) Compiling..."
			@$(MAKE_DIR) $(LIBFT)
			@$(MAKE_DIR) $(MLX_LINUX)
			$(CC) $(OBJS)  -L$(LIBFT) -L$(MLX_LINUX) $(FRAMEWORKS_LINUX) -o $(NAME)
			@echo "$(GREEN) Cub3D Compiled\n $(END)"
			
clean:
			@$(MAKE_DIR) $(LIBFT) clean
			@$(MAKE_DIR) $(MLX_MAC) clean
			@$(RM) $(OBJS)
			@$(RM) $(OBJS_BONUS)
			@$(RM) $(OBJ)

linux-clean:
			@echo "$(RED) Cleaning..."
			@$(MAKE_DIR) $(LIBFT) clean
			@$(MAKE_DIR) $(MLX_LINUX) clean
			@$(RM) $(OBJS)
			@$(RM) $(OBJS_BONUS)
			@$(RM) $(OBJ)
			@echo "$(END)"

fclean:		clean
			@echo "$(RED) Removing executable..."
			@$(MAKE_DIR) $(LIBFT) fclean
			@$(RM) $(NAME)
			@echo "$(END)"

bclean:
			@$(RM) $(OBJS) $(OBJS_BONUS)

re:			fclean all

relinux:			fclean linux

norm:
			@$(NM) $(SRCS) $(SRCS_BONUS) $(HEADERS) $(HEADERS_BONUS)

val: all
	valgrind   --leak-check=full --track-origins=yes -s --trace-children=yes  ./$(NAME) map.cub

.PHONY:		all debug clean fclean re linux bonus bclean