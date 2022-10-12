NAME	=	push_swap

LIBFTPRINTF	=	./ft_printf/libftprintf.a

CFLAGS	=	-g -Wall -Werror -Wextra

SRCS	=	main.c \
			utils/utils.c utils/utils2.c\
			stack/stack_init.c stack/validator.c \
			moves/sort.c moves/operations.c moves/macros.c moves/operations2.c

OBJS	=	$(SRCS:.c=.o)

%.o: %.c 
	@ $(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
		@ make -s -C ./ft_printf
		@ cc $(OBJS) -o $(NAME) $(LIBFTPRINTF)
		@echo ">>[Push_Swap Compiled]"
		@echo "..........[OK].........."

all:		$(NAME)

clean:
		@ rm -f $(OBJS)
		@ make clean -s -C ./ft_printf
		@echo "All clean."
		
fclean:		clean
		@ rm -f $(NAME)
		@ make fclean -s -C ./ft_printf

re:		fclean all

.PHONY:		all clean fclean re
