#include "push_swap.h"

void sort_4_or_5_elements(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b)
{
    while (needs_sorting(*head_a))
    {
        while (stack_length(*head_a) != 3)
        {
            bubble_up(head_a, tail_a, head_b, tail_b);
            //pa(&head_a, &tail_a, &head_b, &tail_b, 's');
        }
        sort_2_or_3_elements(head_a, tail_a);
        pb(head_a, tail_a, head_b, tail_b, 's');
        pb(head_a, tail_a, head_b, tail_b, 's');
    }
}