
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
    if ((*head_b)->value > (*tail_b)->value)
        rrb(head_b, tail_b, 's');
    else if ((*head_b)->value > (*head_b)->next->value)
        sb(head_b, tail_b, 's');
    else
        printf("nonthing to optimize in stack b\n");
}

bool check_optimal_pa(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b)
{
    if (!(*head_b || *tail_b))
        return 0;
    else if ((*head_a)->index == (*head_b)->index + 1 || (*tail_a)->index == (*head_b)->index - 1)
    {
        (*head_b)->is_lis = 1; 
        printf(">>>Before pa:\n");
        printf("Stack A:\n| %d, is_lis: %d\n| %d, is_lis: %d\n| %d, is_lis: %d\n| %d, is_lis: %d\n| %d, is_lis: %d\n", (*head_a)->value, (*head_a)->is_lis, (*head_a)->next->value, (*head_a)->next->is_lis, (*head_a)->next->next->value, (*head_a)->next->next->is_lis, (*head_a)->next->next->next->value, (*head_a)->next->next->next->is_lis, (*head_a)->next->next->next->next->value, (*head_a)->next->next->next->next->is_lis);
        printf("Stack B head value:\n| %d, is_lis: %d\n| %d, is_lis: %d\n", (*head_b)->value, (*head_b)->is_lis, (*head_b)->next->value, (*head_b)->next->is_lis);

        pa(head_a, tail_a, head_b, tail_b, 's');

        printf(">>>After pa:\n");
        printf("Stack A:\n| %d, is_lis: %d\n| %d, is_lis: %d\n| %d, is_lis: %d\n| %d, is_lis: %d\n| %d, is_lis: %d\n", (*head_a)->value, (*head_a)->is_lis, (*head_a)->next->value, (*head_a)->next->is_lis, (*head_a)->next->next->value, (*head_a)->next->next->is_lis, (*head_a)->next->next->next->value, (*head_a)->next->next->next->is_lis, (*head_a)->next->next->next->next->value, (*head_a)->next->next->next->next->is_lis);
        if (*head_b)
            printf("Stack B head value:\n| %d, is_lis: %d\n| %d, is_lis: %d\n", (*head_b)->value, (*head_b)->is_lis, (*head_b)->next->value, (*head_b)->next->is_lis);
        else
            printf("Stack B is empty\n");

        return 1;
    }
    return 0;

   /* else if ((*head_a)->next->index == (*head_b)->index + 1) //experimentall added, room to improve rrr or ss
    {
        ra(head_a, tail_a, 's');
        pa(head_a, head_b, tail_a, tail_b, 's');
    }
    else if ((*tail_a)->prev->index == (*head_b)->index - 1) //experimentall added, room to improve rrr or ss
    {
        rra(head_a, tail_a, 's');
        pa(head_a, head_b, tail_a, tail_b, 's');
    }        */
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