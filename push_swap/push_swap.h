

#ifndef PUSH_SWAP_H
#   define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_node {
    int value;
    struct s_node *next;
    struct s_node *prev;
} t_node;

void free_split_array(char **array);
char **ft_split(const char *str, char delimiter);
int find_largest_elements_position(t_node *head);
int find_smallest_elements_position(t_node *head);
void free_stack(t_node **stack, t_node **tail);
void sort_2_or_3_elements(t_node **head, t_node **tail);
void pa(t_node **head_a, t_node **head_b, t_node **tail_a, t_node **tail_b, char flag);
void pb(t_node **head_a, t_node**tail_a, t_node **head_b, t_node **tail_b, char flag);
void ra(t_node **head_a, t_node **tail_a, char flag);
void rb(t_node **head_b, t_node **tail_b, char flag);
void rr(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b, char flag);
void rra(t_node **head_a, t_node **tail_a, char flag);
void rrb(t_node **head_b, t_node **tail_b, char flag);
void rrr(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b, char flag);
void sa(t_node **head_a, t_node **tail_a, char flag);
void sb(t_node **head_b, t_node **tail_b, char flag);
void ss(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b, char flag);
void add_to_stack(t_node **head, t_node **tail, int input_value);
int has_duplicates(t_node *stack, int input_value);
int is_valid(char *numbers);
int needs_sorting(t_node *stack);
int parse_input(int argc, char **argv, t_node **stack, t_node **tail);
int stack_length(t_node *head);


#endif
