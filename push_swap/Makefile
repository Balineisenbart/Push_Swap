CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
SRCDIR = .
HANDLEDIR = $(SRCDIR)/handle_input
OPSDIR = $(SRCDIR)/operations
SORTDIR = $(SRCDIR)/sort_algorithms

SRCS = 	$(SRCDIR)/main.c $(SRCDIR)/utils.c $(SRCDIR)/greedy_utils.c $(SRCDIR)/print_stack_a_and_stack_b.c $(SRCDIR)/finish.c \
		$(HANDLEDIR)/input_checker.c $(HANDLEDIR)/parse_input.c $(HANDLEDIR)/stack_length.c $(HANDLEDIR)/ft_split.c $(HANDLEDIR)/index_input.c \
		$(OPSDIR)/push.c $(OPSDIR)/reverse_rotate.c $(OPSDIR)/rotate.c $(OPSDIR)/swap.c \
		$(SORTDIR)/sort_2_or_3_elements.c $(SORTDIR)/sort_4_or_5_elements.c $(SORTDIR)/complex_sorting.c

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
