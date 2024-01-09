NAME = push_swap

CC = cc

SRC_DIR = srcs
OBJ_DIR = Objects
LIBFT_DIR = Libft
INCLUDE_DIR = includes

SOURCES = $(SRC_DIR)/main.c \
		  $(SRC_DIR)/parsing.c \
		  $(SRC_DIR)/proximity.c \
		  $(SRC_DIR)/moves_stack_b.c \
		  $(SRC_DIR)/moves_stack_a.c \
		  $(SRC_DIR)/algo.c \
		  $(SRC_DIR)/search.c \
		  $(SRC_DIR)/tab_tools.c \
		  $(SRC_DIR)/simple_case.c \

LIBFT = $(LIBFT_DIR)/libft.a

CFLAG = -Wall -Werror -Wextra -g3

OBJ_FILES = $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPS_FILES = $(OBJ_FILES:%.o=%.d)

all: $(NAME)

-include $(DEPS_FILES)

$(NAME): $(LIBFT) $(OBJ_FILES)
	@$(CC) $(CFLAG) $(OBJ_FILES) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT): FORCE
	@make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR) 
	$(CC) $(CFLAG) -I $(INCLUDE_DIR) -MMD -MP -o $@ -c $<

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean:clean
	make -C $(LIBFT_DIR) fclean
	rm -rf $(NAME) 

re : fclean
	all

FORCE:

.PHONY: fclean clean all re FORCE
