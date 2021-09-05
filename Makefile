NAME		=	libftprintf.a
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -Wformat=0
OBJS		=	$(SRCS:.c=.o)
SRCS		=	ft_printf.c print_chars.c print_numbers.c utils.c				
BONUS_OBJS	=	$(BONUS:.c=.o)
BONUS		=	ft_printf_bonus.c parse_bonus.c \
				print_chars_bonus.c print_numbers_bonus.c \
				print_more_bonus.c utils_bonus.c utils_base_bonus.c 

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

bonus:		$(BONUS_OBJS)
			ar rcs $(NAME) $(BONUS_OBJS)

clean:
			rm -rf $(OBJS) $(BONUS_OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re