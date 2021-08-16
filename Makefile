NAME		=	libftprintf.a
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
OBJS		=	$(SRCS:.c=.o)
SRCS		=	ft_printf.c print_conv.c utils.c
BONUS_OBJS	=	$(BONUS:.c=.o)
BONUS		=	ft_printf_bonus.c print_conv_bonus.c utils_bonus.c

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

bonus:		$(OBJS) $(BONUS_OBJS)
			ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS) $(BONUS)
	gcc -nostartfiles -shared -o libftprintf.so $(OBJS) $(BONUS_OBJS)

test:		$(OBJS) main.o # -lbsd pour bsd string
			@$(CC) $(CFLAGS) -fsanitize=address $(OBJS) main.o
			@./a.out
			@rm -rf a.out

clean:
			rm -rf $(OBJS) $(BONUS_OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re