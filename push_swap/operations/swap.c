
#include "push_swap.h"

void sa(t_node **head_a, t_node **tail_a, char flag) //call only when !NULL && !(*head_a)->next = *head_a
{
    t_node *temp;

    if ((*head_a)->next == *tail_a)
    {
        temp = *tail_a;
        *tail_a = *head_a;
        *head_a = temp;
    }
    else
     {   
        temp = *head_a;
        *head_a = (*head_a)->next;
        temp->next = (*head_a)->next;
        (*head_a)->next->prev = temp;
        (*head_a)->next = temp;
        temp->prev = *head_a;

        (*tail_a)->next = *head_a;
        (*head_a)->prev = *tail_a;
    }
    if (flag == 's')
        write(1, "sa\n", 3);
}