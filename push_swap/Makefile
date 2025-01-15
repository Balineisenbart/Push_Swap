CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = .
HANDLEDIR = $(SRCDIR)/handle_input
OPSDIR = $(SRCDIR)/operations
SORTDIR = $(SRCDIR)/sort_algorithms

SRCS = 	$(SRCDIR)/main.c $(SRCDIR)/utils.c \
		$(HANDLEDIR)/input_checker.c $(HANDLEDIR)/parse_input.c $(HANDLEDIR)/stack_length.c $(HANDLEDIR)/ft_split.c\
		$(OPSDIR)/push.c $(OPSDIR)/reverse_rotate.c $(OPSDIR)/rotate.c $(OPSDIR)/swap.c \
		$(SORTDIR)/sort_2_or_3_elements.c

OBJS = $(SRCS:.c=.o)

TARGET = push_swap

all:	$(TARGET)

$(TARGET):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o:	%.c
	$(CC) $(CFLAGS) -I$(SRCDIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re:	fclean all
