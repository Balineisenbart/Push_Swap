
void ra(t_node **head_a, t_node **tail_a) //call only when !NULL && !(*head_a)->next = *head_a
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
}

void rb(t_node **head_b, t_node **tail_b)
{
    if(*head_b == *tail_b)
        return;
    else
    {
        *tail_b = *head_b;
        *head_b = (*head_b)->next;

        (*tail_b)->next = *head_b;
        (*head_b)->next = *tail_b;
    }
}

void rr(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b)
{
    ra(*head_a, *tail_a);
    rb(*head_b, *tail_b);
}