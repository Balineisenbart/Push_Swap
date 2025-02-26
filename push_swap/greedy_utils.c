
#include "push_swap.h"

int find_cheapest_non_lis(t_node *head, int stack_len)
{
    t_node *top;
    t_node *bottom;
    int top_steps;
    int bottom_steps;

    top = head;
    bottom = head->prev;
    top_steps = 0;
    bottom_steps = 0;

    while (top->is_lis && top_steps < stack_len)
    {
        top = top->next;
        top_steps++;
    }
    while (bottom->is_lis && bottom_steps < stack_len)
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

bool all_lis(t_node *head_a)
{
    t_node *current;

    current = head_a;
    while (current->next != head_a)
    {
        if (!current->is_lis)
            return false;
        current = current->next;
    }
    return current->is_lis;
}
