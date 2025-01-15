

void free_stack(t_node **stack, t_node **tail)
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
    *tail = NULL;
}

int find_largest_elements_position(t_node **head, t_node **tail)
{
    int index;
    int largest_position;
    t_node *largest_element = *head;

    index = 0;
    largest_position = 0;
    while(largest_element != largest_element->next = *head)
    {
        if(largest_element->value < largest_element->next->value)
            largest_position = index;
        largest_element = largest_element->next;
        index++;
    }
    return largest_position;
}

int find_smallest_elements_position(t_node **head, t_node **tail)
{
    int index;
    int smallest_position;
    t_node *smallest_element = *head;

    index = 0;
    smalest_position = 0;
    while(smallest_element != smallest_element->next = *head)
    {
        if(smalles_element->value > smallest_element->next->value)
            smallest_position = index;
        smallest_element = smallest_element->next;
        index++;
    }
    return smallest_position;
}