NAME = libftprintf.a
# FLAGS = -Wall -Werror -Wextra
SRC := ft_printf.c dispatch.c parse.c handle.c handle_helper.c
SRC_DIR = ./src
OBJECTS := $(SRC:.c=.o)
LIBRARIES = libftprintf.a ./libft/libft.a
SRC := $(addprefix $(SRC_DIR)/, $(SRC))
INC_DIR = ./includes/
LIB_DIR = ./libft/

$(NAME):
	@make -C ./libft --no-print-directory
	@cp ./libft/libft.a $(NAME)
	@echo "creating ft_printf objects..."
	@clang $(FLAGS) -c $(SRC) -I$(INC_DIR) -I$(LIB_DIR)
	@echo "\033[92mdone!\033[0m"
	@echo "creating libftprintf.a library..."
	@ar -rc $(NAME) $(OBJECTS)
	@echo "\033[92mdone!\033[0m"
all: $(NAME)
te: $(NAME)
	clear
	clang $(FLAGS) -c $(SRC) -I$(INC_DIR) -I$(LIB_DIR)
	@ar -rc $(NAME) $(OBJECTS)
	gcc -o extest test_main.c libftprintf.a
	./extest
clean:
	@echo "cleaning..."
	@make clean -C ./libft --no-print-directory
	@echo "libft objects removed!"
	@rm -f $(OBJECTS)
	@echo "ft_printf objects removed!"
fclean: clean
	@make fclean -C ./libft --no-print-directory
	@rm -f $(NAME)
	@echo "libftprintf.a removed!"
re: fclean all
