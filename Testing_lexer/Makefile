NAME = lexer
CC = cc
CFLAGS =  -lreadline
SRCS = main.c lexer.c

OBJS = $(SRCS:.c=.o)

SUBDIR = ../LIBFT

all: $(NAME)

$(NAME) : $(SUBDIR) $(OBJS)
	@$(MAKE) -C $(SUBDIR)
	@$(CC) $(OBJS) -L$(SUBDIR) -lft -lreadline -o $(NAME)

$(SUBDIR):
	@$(MAKE) -C $(SUBDIR)

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(SUBDIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(SUBDIR) fclean

re: fclean all
