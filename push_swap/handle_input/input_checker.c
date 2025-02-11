
#include "push_swap.h"

int is_valid(char *numbers)
{
    int i;

    i = 0;
    if (numbers[0] == '-' || numbers[0] == '+')
        i++;
    if (numbers[i] == '\0')
        return 0;
    while (numbers[i] != '\0')
    {
        if (numbers[i] < '0' || numbers[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int has_duplicates(t_node *stack, int input_value)
{
    t_node *start = stack;
    if (stack == NULL)
        return 0;
    while (1) //in the first parsing iteration stack == NULL, need infinite loop and break condition
    {
        if (stack->value == input_value)
            return 1;
        stack = stack->next;
        if (stack == start)
            break;
    }
   return 0; 
}

int needs_sorting(t_node *stack)
{
    t_node *start = stack;
    
    if (stack->next == stack) //single value in list or duplicate??
        return 0;
    while (stack->next != start)
    {
        if (stack->value > stack->next->value)
        {
            return 1;
        }
        stack = stack->next;
    }
    return 0;
}

/*
int is_partially_sorted(t_node *stack)
{
    t_node *current;
    int sections;

    current = *stack;
    sections = 1;
    while (current->next != stack)
    {
        if (current->value > current->next->value)
            sections++;
        current = current->next;
    }
    return sections;
}
*/