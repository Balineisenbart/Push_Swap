

void    pa(t_node **head_a, t_node **head_b, t_node **tail_a, t_node **tail_b)
{
    t_node *temp;

    temp = (*head_a);
    if (*head_a == *tail_a)
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
    ft_printf("%s\n", pa);
}

void pb(t_node **head_a, t_node**tail_a, t_node **head_b, t_node **tail_b)
{
    t_node *temp;

    temp = *head_b;
    if (*head_b == *tail_b) //rule can be implemented elsewhere
    {
        *head_b = NULL;
        *tail_b = NULL;
    }
    else
    {
        *head_b = (*head_b)->next;
        (*tail_b)->next = *head_b;
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
        (*head_a)->prev = *tail_a; //can be omitted
        (*tail_a)->next = *head_a; //can be omitted
        *head_a = temp;
    }
    ft_printf("%s\n", pb);
}