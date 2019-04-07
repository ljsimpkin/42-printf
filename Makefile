NAME = aprint

SRC = main.c \
		src/ft_printf.c \
		src/dispatch.c \
		libft/libft.a

FLAGS = -Wall -Werror -Wextra

$(NAME):
	@gcc -g -o $(NAME) $(SRC) libft/libft.a
	@echo "_________________"
	@echo "                 "
	@echo "    SUCCESS!     "
	@echo "     printf      "
	@echo "    was created  "
	@echo "_________________"


all: $(NAME)

clean:
	@make -C libft/ clean

fclean:
	@rm -f $(NAME)

re: fclean all $(NAME)
