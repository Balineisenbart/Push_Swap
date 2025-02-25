
#include "push_swap.h"

void free_stack(t_node **head, t_node **tail)
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

void free_split_array(char **array)
{
    int i = 0;

    if (!array)
        return;

    while (array[i])
    {
        free(array[i]); // Free each substring
        i++;
    }
    free(array); // Free the array itself
}

int find_largest_elements_position(t_node *head)
{
    t_node *current = head;
    t_node *largest_element = head;
    int     index;
    int     largest_position;

    index = 0;
    largest_position = 0;
    while (current->next != head)
    {
        if (current->value > largest_element->value)
        {
            largest_element = current;
            largest_position = index;
        }
        current = current->next;
        index++;
    }
    if (current->value > largest_element->value)
    {
        largest_element = current;
        largest_position= index;
    }
    return largest_position;
}

int find_smallest_elements_position(t_node *head)
{
    t_node *smallest_element = head;
    t_node *current = head;
    int index;
    int smallest_position;

    index = 0;
    smallest_position = 0;
    while(current->next != head)
    {
       if(current->value < smallest_element->value)
       {
        smallest_element = current;
        smallest_position = index;
       }
       current = current->next;
       index++;
    }
    if (current->value < smallest_element->value)
    {
        smallest_element = current;
        smallest_position = index;
    }
    return smallest_position;
}

void bubble_up_a(t_node **head_a, t_node **tail_a)
{
    int stack_len = stack_length(*head_a);
    int smallest_elements_position = find_smallest_elements_position(*head_a);
    int reverse_moves = stack_len - smallest_elements_position;
    
    // Choose shortest route (ra or rra)
    if (smallest_elements_position > stack_len / 2)
    {
        while (reverse_moves--)
            rra(head_a, tail_a, 's');
    }
    else
    {
        while (smallest_elements_position--)
            ra(head_a, tail_a, 's');
    }
}