CC = gcc
NAME = libftprintf.a
DIR = src
INCLUDES = includes
MAKE = make
FLAGS = -Wall -Wextra -Werror
SRCS = $(DIR)/ft_printf.c \
			$(DIR)/ft_printf_utils.c \
			$(DIR)/ft_conclusion_char.c $(DIR)/ft_char_utils.c \
			$(DIR)/ft_conclusion_string.c $(DIR)/ft_string_utils.c $(DIR)/ft_string_utils2.c \
			$(DIR)/ft_conclusion_integer.c $(DIR)/ft_integer_utils.c $(DIR)/ft_integer_utils2.c \
			$(DIR)/ft_conclusion_unsigned.c $(DIR)/ft_unsigned_utils.c \
			$(DIR)/ft_conclusion_hex.c \
			$(DIR)/ft_conclusion_pointer.c $(DIR)/ft_pointer_utils.c \

HEAD = $(INCLUDES)/ft_printf.h
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(HEAD)
	cd libft && $(MAKE) bonus
	cp libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -c $<  -o $(<:.c=.o)

clean :
	rm -f $(OBJS)
	$(MAKE) clean -C ./libft

fclean : clean
	rm -f $(NAME)
	rm -f libft.a
	$(MAKE) fclean -C ./libft

re : fclean all

.PHONY: all re fclean clean
