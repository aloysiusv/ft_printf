NAME		=	libftprintf.a
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
# INC			= 	-I ./
OBJS		=	$(SRCS:.c=.o)
SRCS		=	ft_printf.c print_conv.c utils.c 
BONUS_OBJS	=	$(BONUS:.c=.o)
BONUS		=	ft_printf_bonus.c print_conv_bonus.c \
				utils_bonus.c parse_options_bonus.c 

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

bonus:		$(BONUS_OBJS)
			ar rcs $(NAME) $(BONUS_OBJS)

%.o:		%.c # -c permet de compiler .c en .o # -o permet de rassembler les .o pour créer l'exécutable # $@ =>  règle  $< => 1ère dépendance
			$(CC) $(CFLAGS) $(INC) -c -o $@ $< 

test:		$(OBJS) main.o # -lbsd pour bsd string
			@$(CC) $(CFLAGS) -fsanitize=address $(OBJS) main.o
			@./a.out

test_bonus: $(BONUS_OBJS) main.o # -lbsd pour bsd string
			@$(CC) $(CFLAGS) -fsanitize=address $(BONUS_OBJS) main.o
			@./a.out

clean:
			rm -rf $(OBJS) $(BONUS_OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re