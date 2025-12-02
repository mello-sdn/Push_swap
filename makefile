NAME        = push_swap
LIBFT       = ./lib/Libft/libft.a
FT_PRINTF   = ./lib/ft_printf/libftprintf.a
INC         = include/
SRC_DIR     = srcs/
OBJ_DIR     = obj/
CC          = gcc
CFLAGS      = -Wall -Werror -Wextra -I
RM          = rm -f

# Source Files
OPERATIONS_DIR = $(SRC_DIR)operations/push.c \
                 $(SRC_DIR)operations/rev_rotate.c \
                 $(SRC_DIR)operations/rotate.c \
                 $(SRC_DIR)operations/sort_stacks.c \
                 $(SRC_DIR)operations/sort_three.c \
                 $(SRC_DIR)operations/swap.c

PUSH_SWAP_DIR = $(SRC_DIR)push_swap/handle_errors.c \
                $(SRC_DIR)push_swap/init_a_to_b.c \
                $(SRC_DIR)push_swap/init_b_to_a.c \
                $(SRC_DIR)push_swap/push_swap.c \
                $(SRC_DIR)push_swap/initialize_stack.c \
                $(SRC_DIR)push_swap/stacks_utils.c \
                $(SRC_DIR)push_swap/split.c

SRCS = $(OPERATIONS_DIR) $(PUSH_SWAP_DIR)
OBJ  = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

start:
	@make all

$(LIBFT):
	@make -C ./lib/Libft

$(FT_PRINTF):
	@make -C ./lib/ft_printf

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) $(FT_PRINTF) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@make clean -C ./lib/Libft
	@make clean -C ./lib/ft_printf

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)
	@$(RM) $(FT_PRINTF)

re: fclean all

.PHONY: start all clean fclean re