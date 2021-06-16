NAME		= pipex

HEADER		= -I includes -I libft

SRCS_DIR	= ./srcs
SRCS_NAME	= main.c \
				get_next_line_bonus.c \
				get_next_line_utils_bonus.c
SRCS		= $(addprefix $(SRCS_DIR)/, $(SRCS_NAME))
OBJS		= $(SRCS:.c=.o)

# BONUS_SRCS_DIR	= ./srcs_bonus
# BONUS_SRCS_NAME	= main_bonus.c \
# 				event_key_bonus.c \
# 				set_game_data_bonus.c \
# 				set_game_player_bonus.c \
# 				set_game_texture_bonus.c \
# 				game_bonus.c \
# 				get_next_line_bonus.c \
# 				get_next_line_utils_bonus.c \
# 				main_bonus.c \
# 				parse_identifier_bonus.c \
# 				parse_map_validation_bonus.c \
# 				parse_map_bonus.c \
# 				parse_utils_bonus.c \
# 				parse_bonus.c \
# 				raycasting_bonus.c \
# 				raycasting_utils_bonus.c \
# 				door_list_bonus.c \
# 				mouse.c

# BONUS_SRCS		= $(addprefix $(BONUS_SRCS_DIR)/, $(BONUS_SRCS_NAME))
# BONUS_OBJS		= $(BONUS_SRCS:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror $(HEADER)
RM			= rm -rf

TEST_FILE	= beach.cub
BONUS_TEST_FILE	= beach_b.cub

all :		$(NAME)

$(NAME) :	$(OBJS)
			make -C libft
			cp ./libft/libft.a .
			$(CC) $(CFLAGS) $^ libft.a -o $@

# bonus	: 	$(BONUS_OBJS)
# 			make -C minilibx
# 			cp minilibx/libmlx.dylib libmlx.dylib
# 			$(CC) $(CFLAGS) $^ libmlx.dylib -o $(NAME)

clean :
			make -C libft clean
			$(RM) $(OBJS) $(BONUS_OBJS)

fclean :	clean
			make -C libft fclean
			$(RM) libft.a
			$(RM) $(NAME)

re :		fclean all

testb:
	make bonus
	./$(NAME) $(BONUS_TEST_FILE)

test:
	make
	./$(NAME) $(TEST_FILE)