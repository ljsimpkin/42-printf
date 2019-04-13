NAME = exprint

SRC = main.c \
		src/printf.c \
		src/dispatch.c \
		src/parse.c \
		src/handle.c \
		src/handle_helper.c \
		libft/libft.a

FLAGS = -Wall -Werror -Wextra

$(NAME):
	@gcc -o $(NAME) $(SRC) libft/libft.a
	@echo "_________________"
	@echo "                 "
	@echo "    SUCCESS!     "
	@echo "     printf      "
	@echo "    was created  "
	@echo "_________________"


all: $(NAME)

te:
	@gcc -g -o testprint $(SRC) libft/libft.a

lib:
	@make -C libft/ re
	@gcc -o $(NAME) $(SRC) libft/libft.a
	@echo "_________________"
	@echo "                 "
	@echo "    SUCCESS!     "
	@echo "    libft re     "
	@echo "    printf re    "
	@echo "_________________"


clean:
	@make -C libft/ clean

fclean:
	@rm -f $(NAME)

re: fclean all $(NAME)
