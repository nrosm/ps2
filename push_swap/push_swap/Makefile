CC			=	cc -I$(INCLUDE) -g3 -Wall -Wextra -Werror #-fsanitize=address 

NAME		=	push_swap
INCLUDE		=	include
SRCDIR		=	src/
OBJDIR		=	objs/
SRCS 		= 	src/push_swap.c src/alg_radix.c src/op_reverse_rotate.c src/operations_push.c src/operations_rotate.c src/sort.c src/utils.c src/utilstwo.c src/utilsthree.c src/operations_swap.c src/struct.c
OBJS		=	$(SRCS:$(SRCDIR)%.c=$(OBJDIR)%.o)

LIBFT		=	src/libft/
LIBFT_A		=	$(LIBFT)libft.a

AR			=	ar rcs
RM			=	rm -f

all:		$(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT) -s
	@$(CC) $(OBJS) $(LIBFT_A) -o $(NAME)
	@$(RM)


$(OBJDIR)%.o: $(SRCDIR)%.c
				@mkdir -p $(OBJDIR)
				@$(CC) -c $< -o $@

clean:
				@$(RM) $(OBJS)
				@rm -rf $(OBJDIR)
				@make -C $(LIBFT) clean -s

fclean:			clean
				@make -C $(LIBFT) fclean -s
				@$(RM) $(NAME)
				@$(RM) $(EXEC)
				@$(RM) $(PROG_BAR_FILE)

re:				fclean all

.PHONY:       	all lib clean fclean re bonus