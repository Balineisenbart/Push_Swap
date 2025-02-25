
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
    t_node **arr;
    int *lis;
    int *prev;
    int i;
    int j;
    int max_len;
    int max_index;

    arr = make_array(head, size);
    if (!arr)
        return;
    max_len = 1;
    max_index = 0;

    lis = malloc (size * sizeof(int));
    if (!lis)
        return (free(arr));
    prev = malloc (size * sizeof(int));
    if (!prev)
        return (free(arr), free(lis));
    i = 0;
    while (i < size)
    {
        lis[i] = 1;
        prev[i] = -1;
        i++;
    }

    i = 1;
    while (i < size)
    {
        j = 0;
        while (j < i)
        {
            if (arr[j]->value < arr[i]->value && lis[j] + 1 > lis[i])
            {
                lis[i] = lis[j] + 1;
                prev[i] = j;
            }
            j++;
        }
        if (lis[i] > max_len)
        {
            max_len = lis[i];
            max_index = i;
        }
        i++;
    }

    while (max_index != -1)
    {
        arr[max_index]->is_lis = pass;
        max_index = prev[max_index];
    }

    /*
    printf(":: :: :: :: :: :: :: :: :: :: :: :: :: :: :: \n\n");

    i = 0;
    j = 0;
    printf("lis array :: ");
    while (j < size)
    {
        printf("[%d]", lis[j]);
        j++;
    }
    j = 0;
    printf("\n");
    printf("prev array :: ");
    while (j < size)
    {
        printf("[%d]", prev[j]);
        j++;
    }
    printf("\n\n");
    while (i < size)
    {
        printf("value %d :: %d and is_lis %d\n", i, arr[i]->value, arr[i]->is_lis);
        i++;
    }
    printf("\n:: :: :: :: :: :: :: :: :: :: :: :: :: :: :: \n\n");
    */

    free(lis);
    free(prev);
    free(arr);
}



