

void parse_input(int argc, char **argv, t_node **stack)
{
    int i;
    int value;

    i = 1;
    while (i <= argc)
    {    
        value = atoi(argv[i])
        if(!(is_valid(argv[i]) || has_duplicate(stack, value)))
        {
            free_stack(stack);
            return (ERROR);// or exit_error
        }
        add_to_stack(stack, value);
        i++;
    }
}

void add_to_stack(t_node **head, int value)
{
    t_node *new_node = malloc sizeof(t_node);
    if (!new_node)
        return NULL;

    new_node->value = value;

    if (*head == NULL)
    {
        new_node->next = new_node;
        new_node->prev = new_node;
        *head = new_node;
    }
    else
    {
        t_node *tail = (*head)->prev;
        new_node->prev = tail; //makes doubly
        new_node->next = *head;
        tail->next = new_node; //makes circular
        (*head)->prev = new_node;
    }
}
