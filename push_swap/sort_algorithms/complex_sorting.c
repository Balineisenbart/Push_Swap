#include "push_swap.h"

void complex_sorting(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b, int stack_len)
{
    int cheapest;

    index_input(head_a, stack_len);
    find_lis(*head_a, stack_len, 1);
    printf(" +++    INSIDE COMPLEX SORTING     +++ \n");

    
    print_stack_a_and_stack_b(*head_a, *head_b);//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    

    while ((!all_lis(*head_a)) || (needs_sorting(*head_a)))
    {
        printf("inside while loop\n");
        print_stack_a_and_stack_b(*head_a, *head_b);//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

        cheapest = find_cheapest_non_lis(*head_a, stack_len);
        if (cheapest > 0)
        {
            while (0 < cheapest--)
            {
                ra(head_a, tail_a, 's'); //possibly rr
                //check_optimal_pa(head_a, tail_a, head_b, tail_b);
            }
        }
        else
        {
            while (0 > cheapest++)
            {
                rra(head_a, tail_a, 's'); //possibly rrr in combintion with check_optimal_pa?
                //if (check_optimal_pa(head_a, tail_a, head_b, tail_b))
                //    break;
            }
        }
        if (!(*head_a)->is_lis)
        {
            pb(head_a, tail_a, head_b,  tail_b, 's');
        }
        if (*head_b)
            optimize_stack_b(head_b, tail_b);
        print_stack_a_and_stack_b(*head_a, *head_b);//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    }
    if (*head_b)
        finish(head_a, tail_a, head_b, tail_b);
    if (needs_sorting(*head_a))
        bubble_up_a(head_a, tail_a);
 printf(" +++    EXIT COMPLEX SORTING     +++ \n");

}