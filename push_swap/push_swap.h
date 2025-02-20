

#ifndef PUSH_SWAP_H
#   define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_node {
    int value;
    struct s_node *next;
    struct s_node *prev;
    int is_lis;
    int index;
} t_node;

void free_split_array(char **array);
char **ft_split(const char *str, char delimiter);
int find_largest_elements_position(t_node *head);
int find_smallest_elements_position(t_node *head);
void free_stack(t_node **stack, t_node **tail);
void sort_2_or_3_elements(t_node **head, t_node **tail);
void sort_4_or_5_elements(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b);
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
void bubble_up_a(t_node **head_a, t_node **tail_a);
int has_duplicates(t_node *stack, int input_value);
int is_valid(char *numbers);
int needs_sorting(t_node *stack);
int parse_input(int argc, char **argv, t_node **stack, t_node **tail);
int stack_length(t_node *head);
void find_lis(t_node *head, int size, int pass);
int find_cheapest_non_lis(t_node *head, int stack_len);
void index_input(t_node **head_a, int size);
void optimize_stack_b(t_node **head_b, t_node **tail_b);
bool check_optimal_pa(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b);
void complex_sorting(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b, int stack_len);
bool all_lis(t_node *head_a);
t_node **make_array(t_node *head, int size);

void print_stack_a_and_stack_b(t_node *head_a, t_node *head_b);



#endif
