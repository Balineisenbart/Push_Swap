#include "push_swap.h"

void complex_sorting(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b, int stack_len)
{
    int cheapest;

    index_input(head_a, stack_len);
    find_lis(*head_a, stack_len, 1);

    printf("Stack A:\n| %d, is_lis: %d\n| %d, is_lis: %d\n| %d, is_lis: %d\n| %d, is_lis: %d\n| %d, is_lis: %d\n| %d, is_lis: %d\n", (*head_a)->value, (*head_a)->is_lis, (*head_a)->next->value, (*head_a)->next->is_lis, (*head_a)->next->next->value, (*head_a)->next->next->is_lis, (*head_a)->next->next->next->value, (*head_a)->next->next->next->is_lis, (*head_a)->next->next->next->next->value, (*head_a)->next->next->next->next->is_lis, (*head_a)->next->next->next->next->next->value, (*head_a)->next->next->next->next->next->is_lis);
    
    if (*head_b)
        printf("Stack B head value:\n| %d, is_lis: %d\n| %d, is_lis: %d\n", (*head_b)->value, (*head_b)->is_lis, (*head_b)->next->value, (*head_b)->next->is_lis);
   
    while ((!all_lis(*head_a)) || !(needs_sorting(*head_a)))
    {
        cheapest = find_cheapest_non_lis(*head_a, stack_len);
        if (cheapest > 0)
        {
            while (0 < cheapest--)
            {
                ra(head_a, tail_a, 's'); //possibly rr
                check_optimal_pa(head_a, tail_a, head_b, tail_b);
            }
        }
        else
        {
            while (0 > cheapest++)
            {
                printf("1) head A value: %d, is_lis%d\n", (*head_a)->value, (*head_a)->is_lis);
                rra(head_a, tail_a, 's'); //possibly rrr
                if (*head_b)
                    printf("2) head b value: %d, is_lis%d\n", (*head_b)->value, (*head_b)->is_lis);
                if (check_optimal_pa(head_a, tail_a, head_b, tail_b))
                    break;
            }
        }
        if (!(*head_a)->is_lis)
        {
            printf("3) head a value: %d, is_lis%d\n", (*head_a)->value, (*head_a)->is_lis);
            pb(head_a, tail_a, head_b,  tail_b, 's');
        }
        optimize_stack_b(head_b, tail_b);
    }

    finish(head_a, tail_a, head_b, tail_b);
       //rotate through stack & stack b
       //whenever index of head B fits between head a & tail a pa
       //calculate costs for optimal rotations


    printf("end of complex sorting:\n");
        printf("Stack A head value: %d, is_lis: %d, index: %d\n", (*head_a)->value, (*head_a)->is_lis, (*head_a)->index);
        printf("Stack A value: %d, is_lis: %d, index: %d\n", (*head_a)->next->value, (*head_a)->next->is_lis, (*head_a)->next->index);
        printf("Stack A value: %d, is_lis: %d\n", (*head_a)->next->next->value, (*head_a)->next->next->is_lis);
        printf("Stack A value: %d, is_lis: %d\n", (*head_a)->next->next->next->value, (*head_a)->next->next->next->is_lis);
        printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        if (*head_b)
        {
            printf("Stack B head value: %d, is_lis: %d\n", (*head_b)->value, (*head_b)->is_lis);
            printf("Stack B value: %d, is_lis: %d\n", (*head_b)->next->value, (*head_b)->next->is_lis);
            printf("Stack B value: %d, is_lis: %d\n", (*head_b)->next->next->value, (*head_b)->next->next->is_lis);
            printf("Stack B value: %d, is_lis: %d\n", (*head_b)->next->next->next->value, (*head_b)->next->next->next->is_lis);
        }

}