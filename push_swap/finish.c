

#include "push_swap.h"

void finish(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b)
{
    t_cheapest cost;
    char stack_to_rotate;

    while (*head_b)
    {
        printf(" +++    INSIDE FINISH    +++ \n");

        //find if it is cheaper to rotate stack a or stack b
        stack_to_rotate = find_cheaper_stack(*head_a, *tail_a, *head_b, *tail_b);
        if (stack_to_rotate == 'a')
        {
            cost = find_cheapest_rotation(*head_b, *head_a, *tail_a); //stack a is cheaper to rotate, compare to b
            cost.iterations++;
            printf("Stack A is cheaper\ncost.iterations %d\n", cost.iterations);
            if (cost.move == RX)
            {
                while (cost.iterations-- > 0)
                {
                    ra(head_a, tail_a, 's');
                }
            }
            else
            {
                while (cost.iterations-- > 0)
                {
                    rra(head_a, tail_a, 's');
                }
            }
        }
        if (stack_to_rotate == 'b')
        {
            cost = find_cheapest_rotation(*head_a, *head_b, *tail_b); //stack b is cheaper to rotate, compare to a
            printf("Stack B is cheaper\ncost.iterations %d\n", cost.iterations);
            if (cost.move == RX)
            {
                while (cost.iterations-- > 0)
                {
                    rb(head_b, tail_b, 's');
                }
            }
            else
            {
                while (cost.iterations-- > 0)
                {
                    rrb(head_b, tail_b, 's');
                }
            }
        }
        print_stack_a_and_stack_b(*head_a, *head_b);//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

        pa(head_a, tail_a, head_b, tail_b, 's');
    }
    printf(" +++    EXIT FINISH    +++ \n");

}

t_cheapest find_cheapest_rotation(t_node *head_to_push, t_node *head_to_compare, t_node *tail_to_compare)
{
    t_cheapest rotation;
    t_node *current;
    t_node *current_tail;
    t_node *candidate;
    int count_rx;
    int count_rrx;

    count_rx = 0;
    count_rrx = 0;
    candidate = head_to_push;
    current = head_to_compare;
    current_tail = tail_to_compare;
    while (!(candidate->index == current->index - 1 || candidate->index == current_tail->index + 1) && count_rx < stack_length(head_to_compare))
    {
        printf("candidate: value: %d, index %d")
        current = current->next;
        count_rx++;
    }
    current = head_to_compare;
    current_tail = tail_to_compare;
    while (!(candidate->index == current->index - 1 || candidate->index == current_tail->index + 1) && count_rrx < stack_length(head_to_compare))
    {
        current = current->prev;
        count_rrx++;
    }

    if (count_rx <= count_rrx)
    {
        rotation.move = RX;
        rotation.iterations = count_rx;
    }
    else
    {
        rotation.move = RRX;
        rotation.iterations = count_rrx; 
    }
    return rotation;
}

char find_cheaper_stack(t_node *head_a, t_node *tail_a, t_node *head_b, t_node *tail_b)
{
    //find out which move is cheaper rx or rrx
    t_cheapest cost_a;
    t_cheapest cost_b;

    cost_a.iterations = INT_MAX;
    cost_b.iterations = INT_MAX;

    if (!(stack_length(head_a) == 1))
        cost_a = find_cheapest_rotation(head_b, head_a, tail_a);
    if (!(stack_length(head_b) == 1))
        cost_b = find_cheapest_rotation(head_a, head_b, tail_b);

    printf("cost_a.iterations %d\ncost_a.move %d\n", cost_a.iterations, cost_a.move);
    printf("cost_b.iterations %d\ncost_b.move %d\n", cost_b.iterations, cost_b.move);

    if (cost_a.iterations < cost_b.iterations)
        return 'a';
    else
        return 'b';
}