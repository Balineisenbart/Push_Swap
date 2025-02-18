
#include "push_swap.h"

int find_cheapest_non_lis(t_node **head, int stack_len)
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

    if (top < bottom)
        return top;
    else
        return bottom *= -1;
}

void optimize_stack_b(t_node **head_b, t_node **tail_b)
{
    if (head_b->value > tail_b->value)
        rrb(head_b, tail_b, 's');
    else if (head_b->value > head_b->next-value)
        sb(head_b, tail_b, 's');
}

void check_optimal_pa(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b)
{
    if (head_a->index == head_b->index + 1 || tail_a->index == head_b->index - 1)
    {
        head_b->is_lis = 3; //mark newly pushed element as part of lis to prevent pushing back;
        pa(head_a, head_b, tail_a, tail_b, 's');
    }
}