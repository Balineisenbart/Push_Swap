
#include "push_swap.h"

void    pb(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b, char flag)
{
    t_node *temp;

    if (!*head_a)
        return;

    temp = *head_a;
    if (*head_a == *tail_a)
    {
        *head_a = NULL;
        *tail_a = NULL;
    }
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        *head_a = temp->next;
    }
    if (*head_b == NULL)
    {
        temp->next = temp->prev = temp;
        *head_b = temp;
        *tail_b = temp;
    }
    else
    {
        temp->next = *head_b;
        temp->prev = *tail_b;
        (*head_b)->prev = temp;
        (*tail_b)->next = temp;
        *head_b = temp;
    }
    temp = NULL;
    if (flag == 's')
        printf("pb\n");
}

void pa(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b, char flag)
{
    t_node *temp;

    if (!*head_b)
        return;
    temp = *head_b;
    if (*head_b == *tail_b)
    {
        *head_b = NULL;
        *tail_b = NULL;
    }
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        *head_b = temp->next;
    }
        if (!*head_a)
    {
        temp->next = temp->prev = temp;
        *head_a = temp;
        *tail_a = temp;
    }
    else
    {
        temp->next = *head_a;
        temp->prev = *tail_a;
        (*tail_a)->next = temp;
        (*head_a)->prev = temp;
        *head_a = temp;
    }
    temp = NULL;
    if (flag == 's')
        printf("pa\n");
}
