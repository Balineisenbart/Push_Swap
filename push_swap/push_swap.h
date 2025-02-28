

#ifndef PUSH_SWAP_H
#   define PUSH_SWAP_H

#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <unistd.h>

typedef struct s_node {
    int value;
    struct s_node *next;
    struct s_node *prev;
    int chunk;
    int index;
} t_node;

typedef enum e_move {
    RX,
    RRX
} t_move;

typedef enum e_b_rotation{
    RB,
    RRB
} t_b_rotation;

typedef struct s_cheapest {
    int iterations;
    int other_r;
    int price;
    t_move move;
    t_b_rotation dir;
} t_cheapest;

int	ft_atoi(const char *str);
void free_split_array(char **array);
char **ft_split(const char *str, char delimiter);
int find_largest_elements_position(t_node *head);
int find_smallest_elements_position(t_node *head);
void free_stack(t_node **stack, t_node **tail);
void sort_2_or_3_elements(t_node **head, t_node **tail);
void sort_4_or_5_elements(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b);
void pa(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b, char flag);
void pb(t_node **head_a, t_node**tail_a, t_node **head_b, t_node **tail_b, char flag);
t_node *maintain_circularity(t_node **head, t_node **tail);
void push_to_other_stack(t_node **head_other, t_node **tail_other, t_node *temp);
void ra(t_node **head_a, t_node **tail_a, char flag);
void rb(t_node **head_b, t_node **tail_b, char flag);
void rr(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b, char flag);
void rra(t_node **head_a, t_node **tail_a, char flag);
void rrb(t_node **head_b, t_node **tail_b, char flag);
void rrr(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b, char flag);
void sa(t_node **head_a, t_node **tail_a, char flag);
void add_to_stack(t_node **head, t_node **tail, int input_value);
void bubble_up_a(t_node **head_a, t_node **tail_a);
int has_duplicates(t_node *stack, int input_value);
int is_valid(char *numbers);
int needs_sorting(t_node *stack);
int parse_input(int argc, char **argv, t_node **stack, t_node **tail);
int two_args(char **argv, t_node **stack, t_node **tail);
int more_args(int argc, char **argv, t_node **stack, t_node **tail);
int stack_length(t_node *head);
int find_cheapest_chunk_element(t_node *head, int stack_len);
void index_input(t_node **head_a, int size);
int *sort_arr(int *arr, int size);
void indexing(int *arr, t_node **head_a, int size);
void complex_sorting(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b, int stack_len);
void push_chunk(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b, int length);
bool contains_chunk(t_node *head_a);
int determine_chunk_number(int length);
void define_chunk(t_node **head, int current_chunk, int previous_chunk);

void finish(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b);
t_cheapest *find_cheapest_path_a(t_node **head_b, t_node **head_a, t_node **tail_a);
t_cheapest *find_cheapest_path_rev_a(t_node **head_b, t_node **head_a, t_node **tail_a);
t_cheapest find_cheapest_arr(t_cheapest *arr, t_node **head);
t_cheapest return_cheapest_arr(t_node **head_b, t_node **head_a, t_node **tail_a);
t_cheapest price_calc(t_cheapest cost);

#endif
