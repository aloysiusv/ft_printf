NAME		=	libftprintf.a
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -Wformat=0
INC			= 	-I ./
OBJS		=	$(SRCS:.c=.o)
SRCS		=	printf_bitwise.c parse_bitwise.c convert_bitwise.c utils_bitwise.c 

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

%.o:		%.c ft_printf.h # -c permet de compiler .c en .o # -o permet de rassembler les .o pour créer l'exécutable # $@ =>  règle  $< => 1ère dépendance
			$(CC) $(CFLAGS) $(INC) -c -o $@ $< 

test:		$(OBJS) main_bitwise.o # -lbsd pour bsd string
			@$(CC) $(CFLAGS) -fsanitize=address $(OBJS) main_bitwise.o
			@./a.out

bonus:		all

clean:
			rm -rf $(OBJS) $(BONUS_OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re