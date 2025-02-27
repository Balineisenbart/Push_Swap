
#include "push_swap.h"


int determine_chunk_number(t_node *head, int length)
{
    int max_chunks;
    int chunk_size;

    if (length <= 100)
        max_chunks = 5;
    else if (length <= 500)
        max_chunks = 10;
    else
        max_chunks = = 5 + ((stack_len - 100) * 5) / 400;

    chunk_size = length / max_chunks;

    return chunk_size;
}

void define_chunk(t_node **head, int current_chunk, int previous_chunk)
{
    t_node *current;
    int i;
    int n;
    
    current = head;
    i = 0;
    n = stack_length(head);
    while (i < n && current_chunk <= n) 
    {
        if (current->index <= current_chunk && current->index > previous_chunk)
            current->chunk = 1;
        current = current->next;
    }
}


int find_cheapest_chunk_element(t_node *head, int stack_len)
{
    t_node *top;
    t_node *bottom;
    int top_steps;
    int bottom_steps;

    top = head;
    bottom = head->prev;
    top_steps = 0;
    bottom_steps = 0;

    while (!(top->chunk) && top_steps < stack_len)
    {
        top = top->next;
        top_steps++;
    }
    while (!(bottom->chunk) && bottom_steps < stack_len)
    {
        bottom = bottom->prev;
        bottom_steps++;
    }
    bottom_steps++;

    if (top_steps < bottom_steps)
        return top_steps;
    else
        return bottom_steps *= -1;
}

void optimize_stack_b(t_node **head_b, t_node **tail_b)
{
    if (stack_length(*head_b) == 1)
        return ;
    if ((*head_b)->value > (*tail_b)->value)
        rb(head_b, tail_b, 's');
    else if ((*head_b)->value > (*head_b)->next->value)
        sb(head_b, tail_b, 's');

}

bool check_optimal_pa(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b)
{
    if (!(*head_b || *tail_b))
        return 0;
    else if ((*head_a)->index == (*head_b)->index + 1)
    {
        (*head_b)->is_lis = 1; 

        pa(head_a, tail_a, head_b, tail_b, 's');
        
        
        return 1;
    }

    return 0;
}

bool contains_chunk(t_node *head_a)
{
    t_node *current;
    int n;
    int i;

    current = head_a;
    n = stack_length(head_a);
    i = 0;
    while (i < n)
    {
        if (current->chunk)
            return true;
        current = current->next;
        i++;
    }
    return false;
}
