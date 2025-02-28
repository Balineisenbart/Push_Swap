
#include "push_swap.h"

int parse_input(int argc, char **argv, t_node **stack, t_node **tail)
{
    int result;

    if (argc == 2)
        result = two_args(argv, stack, tail);
    else if (argc > 2)
        result = more_args(argc, argv, stack, tail);
    return result;
}

int two_args(char **argv, t_node **stack, t_node **tail)
{
    int i;
    int j;
    int input_value;
    char **numbers;

    i = 1;
    j = 0;
    numbers = ft_split(argv[i], ' ');
    while (numbers[j] != NULL)
    {
        input_value = atoi(numbers[j]); //check for overflow, also free stack if overflow happens
        if (!(is_valid(numbers[j])) || has_duplicates(*stack, input_value))
        {
            free_stack(stack, tail);
            free_split_array(numbers); 
            printf("Error\n");
            return 0;
        }
        add_to_stack(stack, tail, input_value);
        j++;
    }
    free_split_array(numbers);
    return 1;
}

int more_args(int argc, char **argv, t_node **stack, t_node **tail)
{
    int i;
    int input_value;

    i = 1;
    while (i < argc)
    {    
        input_value = atoi(argv[i]); //check if my atoi has overflow handling
        if(!(is_valid(argv[i])) || has_duplicates(*stack, input_value))
        {
            free_stack(stack, tail);
            printf("Error\n");
            return 0;
        }
        if (*argv[i] == ' ')
            i++;
        add_to_stack(stack, tail, input_value);
        i++;
    }
    return 1;
}

void add_to_stack(t_node **head, t_node **tail, int input_value)
{
    t_node *new_node = malloc (sizeof(t_node));
    if (!new_node)
    {
        free (new_node);
        exit (EXIT_FAILURE);
    }
    new_node->value = input_value;
    if (*head == NULL)
    {
        new_node->next = new_node;
        new_node->prev = new_node;
        *head = new_node;
        *tail = new_node;
    }
    else
    {
        new_node->prev = *tail;
        new_node->next = *head;
        (*tail)->next = new_node;
        (*head)->prev = new_node;
        *tail = new_node;
    }
}

t_node **make_array(t_node *head, int size)
{
    int i;
    t_node **arr;
    t_node *current;

    i = 0;
    arr = malloc (size * sizeof(t_node *));
    if (!arr)
        return NULL;
    current = head;
    while (i < size)
    {
        arr[i] = current;
        i++;
        current = current->next;
    }
    return arr;
}