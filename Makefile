CC = gcc
SRC = main.c \
	  ft_istype.c \
	  ft_strlen_scope.c \
	  ft_gettype_of_func.c \
	  ft_isdeclar.c \
	  ft_iscondition.c \
	  ft_onlyesp.c \
	  ft_iskeyword.c \
	  ft_isfunction.c \
	  ft_getname_of_func.c \
	  ft_creat_elem.c \
	  ft_add_elem.c \
	  ft_getinfo.c \
	  ft_analyse.c
OBJ = $(SRC:.c=.o)
NAME = norminette
FLAGS = -Wall -Wextra -Werror
LIB = -L./libft -lft

all: $(NAME)

$(NAME):
	@make -C libft/
	@echo "Normination"
	@$(CC) $(FLAGS) -I libft/includes/ -c $(SRC)
	@$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f *~

re: fclean all
