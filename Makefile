BINDIR	:= bin
SRCDIR	:= srcs
OBJDIR	:= objs

CPATHS	:= $(shell find $(SRCDIR) -type f -name '*.c' -not -path '$(SRCDIR)/checker/*.c')
SRCDIRS	:= $(dir $(CPATHS))
OBJDIRS	:= $(subst $(SRCDIR), $(OBJDIR), $(SRCDIRS))

FILES	:= $(notdir $(CPATHS))
SRCS	:= $(join $(SRCDIRS), $(FILES))
OBJS	:= $(join $(OBJDIRS), $(FILES:.c=.o))
DEPS	:= $(join $(OBJDIRS), $(FILES:.c=.d))

CC		:= cc
RM		:= rm -rf
NAME	:= push_swap
PS		:= $(BINDIR)/push_swap
LIBFT	:= ft_dprintf/lib/libftdprintf.a
INCDIRS	:= $(addsuffix includes, ./ft_dprintf/ ./ft_dprintf/libft/ ./)
CFLAGS	:= -Wall -Wextra -Werror -MMD -MP
DEVFLAG	:=

ifdef WITH_CHECKER
	CPATHS	:= $(shell find $(SRCDIR) -type f -name '*.c' -not -path '$(SRCDIR)/push_swap.c')
	SRCDIRS	:= $(dir $(CPATHS))
	OBJDIRS	:= $(subst $(SRCDIR), $(OBJDIR), $(SRCDIRS))

	FILES	:= $(notdir $(CPATHS))
	SRCS	:= $(join $(SRCDIRS), $(FILES))
	OBJS	:= $(join $(OBJDIRS), $(FILES:.c=.o))
	DEPS	:= $(join $(OBJDIRS), $(FILES:.c=.d))

	PS		:= $(BINDIR)/checker
	DEVFLAG += -fsanitize=address -g
endif

ifdef DEBUG
	DEVFLAG += -fsanitize=address -g
endif

all: $(LIBFT) $(BINDIR) $(sort $(OBJDIRS)) $(PS)

$(NAME): all

$(PS): $(OBJS) $(LIBFT)
	$(CC) $(DEVFLAG) $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(addprefix -I, $(INCDIRS)) -c $< -o $@

$(LIBFT):
	$(MAKE) -C ft_dprintf

$(BINDIR):
	mkdir -p $(BINDIR)

$(sort $(OBJDIRS)):
	mkdir -p $@

clean:
	$(MAKE) -C ft_dprintf clean
	$(RM) $(OBJDIR)

fclean: clean
	$(MAKE) -C ft_dprintf fclean
	$(RM) $(BINDIR)

re: fclean all

bonus:
	@make WITH_CHECKER=1

-include $(DEPS)

.PHONY: all clean fclean re bonus
