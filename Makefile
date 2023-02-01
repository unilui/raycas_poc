SRCS 		= background.c raycast.c load_hooks.c load_mlx.c render.c

OBJS		=	${SRCS:%.c=$(OBJS_DIR)%.o}
OBJS_DIR	=	objects/
NAME		=	raycast
CC			=	cc
LIBS		=	-lmlx -lX11 -lXext -lm
RM			=	rm -rf

$(OBJS_DIR)%.o:	%.c
			@mkdir -p $(dir $@)
			@$(CC) -c $< -o $@ -I includes

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(OBJS) -o $(NAME) $(LIBS)

clean:
			@$(RM) $(OBJS_DIR)

fclean:
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re run libft
