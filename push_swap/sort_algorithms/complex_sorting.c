#include "push_swap.h"

void complex_sorting(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b, int stack_len)
{
    int cheapest;

    index_input(head_a, stack_len);
    find_lis(*head_a, stack_len, 1);
    while (!all_lis(*head_a))
    {
        cheapest = find_cheapest_non_lis(*head_a, stack_len);
        if (cheapest > 0)
        {
            while (0 < cheapest--)
            {
                ra(head_a, tail_a, 's'); //possibly rr
                check_optimal_pa(head_a, tail_a, head_b, tail_b);
                printf("upper cheapest\n");
            }
        }
        else
        {
            while (0 > cheapest++)
            {
                printf("value%d, is_lis%d\n", (*head_a)->value, (*head_a)->is_lis);
                rra(head_a, tail_a, 's'); //possibly rrr
                printf("value%d, is_lis%d\n", (*head_a)->value, (*head_a)->is_lis);
                if (check_optimal_pa(head_a, tail_a, head_b, tail_b))
                    break;
                printf("lower cheapest\n");
            }
        }
        if (!(*head_a)->is_lis)
        {
            printf("value%d, is_lis%d\n", (*head_a)->value, (*head_a)->is_lis);
            pb(head_a, head_b, tail_a, tail_b, 's');
        }
        optimize_stack_b(head_b, tail_b);
    }
    printf("after is lis:\n");
    print_stack_a_and_stack_b(*head_a, *head_b);//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}