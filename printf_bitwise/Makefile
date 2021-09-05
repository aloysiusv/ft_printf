NAME		=	libftprintf.a
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -Wformat=0
INC			= 	-I ./
OBJS		=	$(SRCS:.c=.o)
SRCS		=	bitwise_printf.c bitwise_parse.c \
				bitwise_print_numbers.c bitwise_print_chars.c \
				bitwise_print_more.c bitwise_utils.c bitwise_utils_base.c

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

%.o:		%.c ft_printf.h # -c permet de compiler .c en .o # -o permet de rassembler les .o pour créer l'exécutable # $@ =>  règle  $< => 1ère dépendance
			$(CC) $(CFLAGS) $(INC) -c -o $@ $< 

test:		$(OBJS) bitwise_main.o # -lbsd pour bsd string
			@$(CC) $(CFLAGS) -fsanitize=address $(OBJS) bitwise_main.o
			@./a.out

bonus:		all

clean:
			rm -rf $(OBJS) $(BONUS_OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re