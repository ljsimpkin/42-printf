
NAME = libft.a

SRC = ft_atoi.c \
				ft_bzero.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_itoa.c \
				ft_memalloc.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memdel.c \
				ft_memmove.c \
				ft_memset.c \
				ft_putchar_fd.c \
				ft_putchar.c \
				ft_putendl_fd.c \
				ft_putendl.c \
				ft_putnbr_fd.c \
				ft_putnbr.c \
				ft_putstr_fd.c \
				ft_putstr.c \
				ft_strcat.c \
				ft_strchr.c \
				ft_strclr.c \
				ft_strcmp.c \
				ft_strcpy.c \
				ft_strdel.c \
				ft_strdup.c \
				ft_strequ.c \
				ft_striter.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlen.c \
				ft_strmap.c \
				ft_strmapi.c \
				ft_strncat.c \
				ft_strncmp.c \
				ft_strncpy.c \
				ft_strnequ.c \
				ft_strnew.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strsplit.c \
				ft_strstr.c \
				ft_strsub.c \
				ft_strtrim.c \
				ft_tolower.c \
				ft_toupper.c
# ____________________________________Bonus Functions_____________________________________
SRC +=	ft_number_len.c \
				ft_strncpy.c \
				ft_word_count.c \
				ft_word_len.c \
				ft_isupper.c \
				ft_islower.c \
				ft_deln.c \
				ft_lstnew.c \
				ft_lstdelone.c \
				ft_lstdel.c \
				ft_lstadd.c \
				ft_lstiter.c \
				ft_lstmap.c

OBJ = $(SRC:.c=.o)

DEL = rm -f

FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@gcc -c $(FLAG) $(SRC) -I .
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "_________________"
	@echo "                 "
	@echo "     SUCCESS!    "
	@echo "     libft.a     "
	@echo "    was created  "
	@echo "_________________"

clean:
	@$(DEL) $(OBJ)
	@echo "_________________"
	@echo "                 "
	@echo "     SUCCESS!    "
	@echo "     XXXXX.o     "
	@echo "  was destroyed  "
	@echo "_________________"

fclean: clean
	@$(DEL) $(NAME)
	@echo "_________________"
	@echo "                 "
	@echo "     SUCCESS!    "
	@echo "     libft.a     "
	@echo "  was destroyed  "
	@echo "_________________"

re: fclean all
