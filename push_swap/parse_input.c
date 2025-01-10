

void parse_input(int argc, char **argv, t_node **stack)
{
    int i;
    int j;
    int value;
    char **numbers;

    i = 1;
    j = 0;

    if (argc == 2) //split both if statements argc >/=2 to separate functions for norm conformity
    {
        numbers = ft_split(argv[i], ' ');
        while (numbers[j] != NULL)
        {
            value = atoi(numbers[j]) //checl for overflow, also free stack if overflow happens
            if (!(is_valid(numbers[j])) || has_duplicate(*stack, value))
            {
                free_stack(stack);
                free_split_array(numbers); //take from ft_split main
                return (error\n);
            }
            add_to_stack(stack, value);
            j++;
        }
        free_split_array(numbers);
    }
    else if (argc > 2) // possible case where input arguments are hybrid of string and single numbers. can add separate chceker, then call argc == 2
    {
        while (i <= argc)
        {    
            value = atoi(argv[i]) //check if my atoi has overflow handling
            if(!(is_valid(argv[i], i)) || has_duplicate(*stack, value))
            {
                free_stack(stack);
                return (error\n);
            }
            if (argv[i] == ' ')
                i++;
            add_to_stack(stack, value);
            i++;
        }
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
