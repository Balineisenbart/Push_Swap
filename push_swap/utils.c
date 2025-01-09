

void free_stack(stack)
{
    t_node *current;
    t_node *temp;

    if (!head || !*head)
        return;

    current = *head;
    while (current)
    {
        temp = current->next;
        free(current);
        if (temp == *head)
            break ;
        current = temp;
    }
    *head = NULL;
}