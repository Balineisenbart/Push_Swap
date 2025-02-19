
#include "push_swap.h"

void rra(t_node **head_a, t_node **tail_a, char flag)
{
    if (*head_a == *tail_a)
        return;
    else
    {
        *head_a = *tail_a;
        *tail_a = (*tail_a)->prev;

        (*tail_a)->next = *head_a;
        (*head_a)->prev = *tail_a;
    }
    if (flag == 's')
        printf("rra\n");
}

void rrb(t_node **head_b, t_node **tail_b, char flag)
{
    if (*head_b == *tail_b)
        return;
    else
    {
        *head_b = *tail_b;
        *tail_b = (*tail_b)->prev;

        (*tail_b)->next = *head_b;
        (*head_b)->prev = *tail_b;
    }
    if (flag == 's')
        printf("rrb\n");
}

void rrr(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b, char flag)
{
    rra(head_a, tail_a, 'n');
    rrb(head_b, tail_b, 'n');
    if (flag == 'd')
        printf("rrr\n");
}