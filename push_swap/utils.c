
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
    t_node *largest_element = head->next;
    int     index;
    int     largest_position;

    index = 1;
    largest_position = 0;
    while (current != head)
    {
        if (current->value > largest_element->value)
        {
            largest_element = current;
            largest_position = index;
        }
        current = current->next;
        index++;
    }
    return largest_position;
}

int find_smallest_elements_position(t_node *head)
{
    t_node *smallest_element = head;
    t_node *current = head->next;
    int index;
    int smallest_position;

    index = 1;
    smallest_position = 0;
    while(current != head)
    {
       if(current->value < smallest_element->value)
       {
        smallest_element = current;
        smallest_position = index;
       }
       current = current->next;
       index++;
    }
    return smallest_position;
}

void bubble_up_a(t_node **head_a, t_node **tail_a)
{
    int reverse_counter = 0;
    int smallest_elements_position = find_smallest_elements_position(*head_a);
    t_node *current = *head_a;

    // Find smallest element's positiona
    while (smallest_elements_position > 0)
    {
        current = current->next;
        smallest_elements_position--;
        reverse_counter++;
    }
    smallest_elements_position = reverse_counter;

    // Choose shortest route (ra or rra)
    if (smallest_elements_position > stack_length(*head_a) / 2)
    {
        while (reverse_counter--)
            rra(head_a, tail_a, 's');
    }
    else
    {
        while (smallest_elements_position--)
            ra(head_a, tail_a, 's');
    }
}