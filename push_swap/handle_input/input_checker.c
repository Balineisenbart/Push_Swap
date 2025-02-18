
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

void find_lis(t_node *head, int size, int pass) //!NORM! pass one variable e.g. j
{
    t_node *current;
    t_node *compare;
    int *lis;
    int *prev;
    int j;
    int count;

    j = -1;
    count = 1;
    lis = malloc (size * sizeof(int));
    if (!lis)
        return;
    prev = malloc (size * sizeof(int));
    if (!prev)
        return;
    current = head->next;
    compare = head;

    while (size > j++) //initialize backtrackers
    {
        lis[j] = 1;
        prev[j] = -1;
    }

    j = 0;
    while (size > count) //find all possible LIS
    {
        current = current->next;
        while (count > j)
        {
           /* if (pass == 2 && compare->is_lis == 1)
            {
                printf("%i 3 :: inside if pass\n", pass);
                continue;
            }*/
            compare = compare->next;
            if (compare->value < current->value && lis[j] + 1 > lis[count])
            {
                lis[count] = lis[j] + 1;
                prev[count] = j;
            }
            j++;
        }
        count++;
    }

    count = 0;
    current = head;
    while (size > count++) //backtrack LIS and remove marker - after pushing
    {
        current = current->next;
        current->is_lis = 0;
    }

    j = -1;
    count = 0;
    while (size > count++) //find LIS max length
    {
        if (j == -1 || lis[count] > lis[j])
            j = count;
    }
    
    while (j >= 0) //mark LIS
    {
        current = head;
        while (j > count++)
            current = current->next;
        current->is_lis = pass;
        j = prev[j];
    }

    free(lis);
    free(prev);

    /*if (pass == 1)
        find_lis(head, size, 2);*/
}