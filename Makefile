NAME = guilmirita

# Source files #
#SRC_FILES = groups_creator.c
SRC_FILES = $(wildcard srcs/*)

OBJ_FILES = $(SRC_FILES:.c=.o)
# Directories #
SRC_DIR = srcs/
OBJ_DIR = obj/
HEADER_DIR = includes/

# Todo junto #
#SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
SRC = $(SRC_FILES)
#OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
OBJ = $(subst $(SRC_DIR), $(OBJ_DIR), $(SRC:.c=.o))

# Libft #
LIBFT_DIR = ./libft/
LIBFT = libft.a

# Includes #
#HEADER = minishell.h

# Flags #
#READLINE = -lreadline -L /Users/$(USER)/.brew/opt/readline/lib -I/Users/$(USER)/.brew/opt/readline/include -o $(NAME)
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address
CC = gcc

all: make-libft $(NAME) 
	@echo "Proyect $(NAME) ready!"

$(NAME): $(OBJ) $(HEADER_DIR)
	echo hola
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_DIR)$(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -I $(HEADER_DIR) -c $< -o $@

make-libft:
	@make -C $(LIBFT_DIR)

bonus: all

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@rm -rf $(OBJ)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@rm -rf $(NAME)
re: fclean all

.PHONY: all re m clean fclean bonus
