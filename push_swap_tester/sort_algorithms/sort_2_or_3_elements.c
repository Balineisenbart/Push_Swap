
#include "push_swap.h"

void sort_2_or_3_elements(t_node **head, t_node **tail)
{
    //if largest_value = stack_length: sa
    //if largest_value = 0: ra & sa()
    //else 
    // --if smallest value = stack_length: rra
    // --else: rra & sa
    //after each operation print & check if needs sorting
    //  1   1   2   3   2   3
    //  2   3   3   2   1   1
    //  3   2   1   1   3   2
    while(needs_sorting(*head))
    {
        if (find_largest_elements_position(*head) == stack_length(*head) - 1)
            sa(head, tail, 's');
        else if (find_largest_elements_position(*head) == 0)
            ra(head, tail, 's');
        else
        {
            if (find_smallest_elements_position(*head) == stack_length(*head) - 1)
                rra(head, tail, 's');
            else
            {
                rra(head, tail, 's');
                sa(head, tail, 's');
            }
        }
    }
}