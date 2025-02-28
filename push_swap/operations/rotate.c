
#include "push_swap.h"

void ra(t_node **head_a, t_node **tail_a, char flag) //call only when !NULL && !(*head_a)->next = *head_a
{
    if (*head_a == *tail_a)
        return;
    else
    {
        *tail_a = *head_a;
        *head_a = (*head_a)->next;

        (*tail_a)->next = *head_a;
        (*head_a)->prev = *tail_a;
    }
    if (flag == 's')
        write(1, "ra\n", 3);
}

void rb(t_node **head_b, t_node **tail_b, char flag)
{
    if(*head_b == *tail_b)
        return;
    else
    {
        *tail_b = *head_b;
        *head_b = (*head_b)->next;

        (*tail_b)->next = *head_b;
        (*head_b)->prev = *tail_b;
    }
    if (flag == 's')
        write(1, "rb\n", 3);
}

void rr(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b, char flag)
{
    ra(head_a, tail_a, 'n');
    rb(head_b, tail_b, 'n');
    if (flag == 'd')
        write(1, "rr\n", 3);
}