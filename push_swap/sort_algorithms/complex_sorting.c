#include "push_swap.h"

void complex_sorting(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b, int stack_len)
{
    int cheapest;

    find_lis(*head_a, stack_len, 1);
    while (needs_sorting(*head_a))
    {

        cheapest = find_cheapest_non_lis(*head_a, stack_len);
        if (cheapest > 0)
        {
            while (0 < cheapest--)
            {
                ra(head_a, tail_a, 's');
            }
        }
        else
        {
            while (0 > cheapest++)
            {
                rra(head_a, tail_a, 's');
            }
        }
        pb(head_a, tail_a, head_b, tail_b, 's');
        optimize_stack_b(head_b, tail_b);
        check_optimal_pa(head_a, tail_a, head_b, tail_b);
    }
}