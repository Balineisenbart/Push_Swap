

#include "push_swap.h"

void index_input(t_node **head_a, int size)
{
    t_node *current;
    int *arr;
    int i;
    int j;
    int temp;

    arr = malloc (size * sizeof(int));
    if (!arr)
        return;
    current = *head_a;
    i = 0;

    while (i != size) //values of list stored in arr
    {
        arr[i] = current->value;
        current = current->next;
        i++;
    }

    i = 0;
    while (i < size - 1) //sort array ascending - bubble up
    {
        j = i + 1;
        while (j < size)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            j++;
        }
        i++;
    }

    current = *head_a;

    j = 0;
    while (j < size) //assign indexing to nodes
    {
        i = 0;
        while (i < size)
        {
            if (current->value == arr[i])
            {
                current->index = i;
                break;
            }
            i++;
        }
        j++;
        current = current->next;
    }
    free(arr);
}