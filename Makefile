NAME = push_swap

OBJ_DIR = obj/
SRC_DIR = src/
HEADER = includes/pushswap.h

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -rf

IFLAGS = -Iincludes

OBJ	=	$(OBJ_DIR)main.o $(OBJ_DIR)ft_push_swap_utils.o \
		$(OBJ_DIR)ft_check_arg.o $(OBJ_DIR)ft_alloc_stack.o \
		$(OBJ_DIR)ft_end.o $(OBJ_DIR)ft_insertion_sort.o \
		$(OBJ_DIR)ft_timsort.o $(OBJ_DIR)ft_timsort_utils.o \
		$(OBJ_DIR)ft_moves.o $(OBJ_DIR)ft_sort_2_or_3.o \
		$(OBJ_DIR)ft_sort.o $(OBJ_DIR)ft_sort_utils.o \
		$(OBJ_DIR)ft_get_limits.o $(OBJ_DIR)ft_rotations.o \
		$(OBJ_DIR)ft_big_sort.o $(OBJ_DIR)ft_big_sort_parts.o \
		$(OBJ_DIR)ft_big_sort_do.o \

all:	$(NAME)

$(NAME):	$(OBJ_DIR) $(OBJ)
			$(CC) $(FLAGS) $(OBJ) -o $@

bonus: all

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(FLAGS) $< -c $(IFLAGS) -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re