BINDIR	:= bin
SRCDIR	:= srcs
OBJDIR	:= objs

FILES	:= main.c
SRCS	:= $(addprefix $(SRCDIR)/, $(FILES))
OBJS	:= $(addprefix $(OBJDIR)/, $(FILES:.c=.o))
DEPS	:= $(addprefix $(OBJDIR)/, $(FILES:.c=.d))

CC		:= cc
RM		:= rm -rf
NAME	:= push_swap
PS		:= $(BINDIR)/push_swap
LIBFT	:= ft_dprintf/lib/libftdprintf.a
INCDIR	:= $(addsuffix includes, ./ft_dprintf/ ./ft_dprintf/libft/ ./)
CFLAGS	:= -Wall -Wextra -Werror -MMD -MP

all: $(LIBFT) $(BINDIR) $(OBJDIR) $(PS)

$(NAME): all

$(PS): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(addprefix -I, $(INCDIR)) -c $< -o $@

$(LIBFT):
	$(MAKE) -C ft_dprintf

$(BINDIR):
	mkdir -p $(BINDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	$(MAKE) -C ft_dprintf clean
	$(RM) $(OBJDIR)

fclean:
	$(MAKE) -C ft_dprintf fclean
	$(RM) $(BINDIR)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re $(PUSH_SWAP)
