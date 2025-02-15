
#include "push_swap.h"

void    pb(t_node **head_a, t_node **head_b, t_node **tail_a, t_node **tail_b, char flag)
{
    t_node *temp;

    temp = *head_a;
    if (*head_a == *tail_a)
    {
        *head_a = NULL;
        *tail_a = NULL;
    }
    else
    {
        *head_a = (*head_a)->next;
        (*tail_a)->next = *head_a;
        (*head_a)->prev = *tail_a;
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
        (*tail_b)->next = temp;
        (*head_b)->prev = temp;
        *head_b = temp;
    }
    if (flag == 's')
        printf("pb\n");
}

void pa(t_node **head_a, t_node**tail_a, t_node **head_b, t_node **tail_b, char flag)
{
    t_node *temp;

    temp = *head_b;
    if (*head_b == *tail_b)
    {
        *head_b = NULL;
        *tail_b = NULL;
    }
    else
    {
        *head_b = (*head_b)->next;
        (*tail_b)->next = *head_b;
        (*head_b)->prev = *tail_b;
    }
    if (*head_a == NULL)
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
    if (flag == 's')
        printf("pa\n");
}