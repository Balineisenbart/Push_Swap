// pa, pb, sa, sb, ss, ra, rb, rr, rra, rrb, rrr

void    pa(t_node **head_a, t_node **head_b, t_node **tail_a, t_node **tail_b) //does it fulfill doubly and circular linked list?, handled when last node is removed?, handled when input stack is empty?
{
    t_node *temp;

    temp = (*head_a);
    if (*head_a == *tail_a) //this statement could be called elsewhere to save lines
    {
        *head_a = NULL;
        *tail_a == NULL;
    }
    else
    {
        (*head_a) = (*head_a)->next;
        (*tail_a)->next = (*head_a);
    }
    if (head_b == NULL)
   {
        (*head_b) = temp;
        (*tail_b) = temp;
        temp->next = temp;
        temp->prev = temp;
    }
    else
    {
        temp->prev = (*tail_b);
        temp->next = (*head_b);
        (*tail_b)->next = temp;
        (*head_b)->prev = temp;
        (*head_b) = temp;
    }
}