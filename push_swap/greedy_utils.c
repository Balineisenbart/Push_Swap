
#include "push_swap.h"


int determine_chunk_number(int length)
{
    int max_chunks;
    int chunk_size;

    if (length <= 100)
        max_chunks = 5;
    else if (length > 100 && length <= 500)
        max_chunks = 10;
    else
        max_chunks = 5 + ((length - 100) * 5) / 400;

    chunk_size = length / max_chunks;

    if (chunk_size == 1)
        chunk_size++;

    return chunk_size;
}

void define_chunk(t_node **head, int current_chunk, int previous_chunk)
{
    t_node *current;
    int i;
    int n;
    
    current = *head;
    i = 0;
    n = stack_length(*head);
    while (i < n && current_chunk <= n) 
    {
        if (current->index <= previous_chunk && current->index >= current_chunk)
            current->chunk = 1;
        current = current->next;
        i++;
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
