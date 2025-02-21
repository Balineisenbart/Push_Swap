

#include "push_swap.h"

void finish(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b)
{
    t_cheapest cost;
    char stack_to_rotate;

    while (*head_b)
    {
        //find if it is cheaper to rotate stack a or stack b
        stack_to_rotate = find_cheaper_stack(*head_a, *tail_a, *head_b, *tail_b);
        if (stack_to_rotate == 'a')
        {
            cost = find_cheapest_rotation(*head_b, *head_a, *tail_a); //stack a is cheaper to rotate, compare to b
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
        printf("Stack A:\n| %d, is_lis: %d\n| %d, is_lis: %d\n| %d, is_lis: %d\n| %d, is_lis: %d\n| %d, is_lis: %d\n| %d, is_lis: %d\n", (*head_a)->value, (*head_a)->is_lis, (*head_a)->next->value, (*head_a)->next->is_lis, (*head_a)->next->next->value, (*head_a)->next->next->is_lis, (*head_a)->next->next->next->value, (*head_a)->next->next->next->is_lis, (*head_a)->next->next->next->next->value, (*head_a)->next->next->next->next->is_lis, (*head_a)->next->next->next->next->next->value, (*head_a)->next->next->next->next->next->is_lis);
        printf("Stack A:\n| %d, is_lis: %d\n| %d, is_lis: %d\n| %d, is_lis: %d\n| %d, is_lis: %d\n| %d, is_lis: %d\n| %d, is_lis: %d\n", (*head_b)->value, (*head_b)->is_lis, (*head_b)->next->value, (*head_b)->next->is_lis, (*head_b)->next->next->value, (*head_b)->next->next->is_lis, (*head_b)->next->next->next->value, (*head_b)->next->next->next->is_lis, (*head_b)->next->next->next->next->value, (*head_b)->next->next->next->next->is_lis, (*head_b)->next->next->next->next->next->value, (*head_b)->next->next->next->next->next->is_lis);

        pa(head_a, tail_a, head_b, tail_b, 's');
    }
}

t_cheapest find_cheapest_rotation(t_node *head_to_push, t_node *head_to_compare, t_node *tail_to_compare)
{
    t_cheapest rotation;
    t_node *current;
    t_node *current_tail;
    t_node *candidate;
    int count_rx;
    int count_rrx;

    candidate = head_to_push;
    current = head_to_compare;
    current_tail = tail_to_compare;
    while (!(candidate->index == current->index - 1 && candidate->index == current_tail->index + 1) && count_rx < stack_length(head_to_compare))
    {
        current = current->next;
        count_rx++;
    }
    while (!(candidate->index == current->index - 1 && candidate->index == current_tail->index + 1) && count_rrx < stack_length(head_to_compare))
    {
        current = current->next;
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

    cost_a = find_cheapest_rotation(head_b, head_a, tail_a);
    cost_b = find_cheapest_rotation(head_a, head_b, tail_b);

    if (cost_a.iterations < cost_b.iterations)
        return 'a';
    else
        return 'b';
}