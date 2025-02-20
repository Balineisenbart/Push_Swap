
#include "push_swap.h"

void finish(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b)
{
    char stack_to_rotate;
    t_cheapest cost;
    
    // While there are nodes in stack B:
    while (*head_b)
    {
        // Decide which stack to rotate based on our cost simulation.
        stack_to_rotate = cheapest_path(*head_a, *head_b);
        
        if (stack_to_rotate == 'a')
        {
            // Get cost to rotate A optimally for insertion.
            cost = find_cheapest_rotation(*head_b, *head_a);
            // Perform the rotations on A:
            if (cost.move == RX)
                while (cost.iterations-- > 0)
                {
                    printf("Stack A:\n| %d, is_lis: %d\n| %d, is_lis: %d\n| %d, is_lis: %d\n| %d, is_lis: %d\n| %d, is_lis: %d\n| %d, is_lis: %d\n", (*head_a)->value, (*head_a)->is_lis, (*head_a)->next->value, (*head_a)->next->is_lis, (*head_a)->next->next->value, (*head_a)->next->next->is_lis, (*head_a)->next->next->next->value, (*head_a)->next->next->next->is_lis, (*head_a)->next->next->next->next->value, (*head_a)->next->next->next->next->is_lis, (*head_a)->next->next->next->next->next->value, (*head_a)->next->next->next->next->next->is_lis);

                    ra(head_a, tail_a, 's');
                }
            else
                while (cost.iterations-- > 0)
                    rra(head_a, tail_a, 's');
        }
        else if (stack_to_rotate == 'b')
        {
            // Get cost to rotate B optimally for insertion.
            cost = find_cheapest_rotation(*head_a, *head_b);
            // Perform the rotations on B:
            if (cost.move == RX)
                while (cost.iterations-- > 0)
                    rb(head_b, tail_b, 's');
            else
                while (cost.iterations-- > 0)
                    rrb(head_b, tail_b, 's');
        }
        
        // Now, if the top of B fits exactly between two nodes in A, do pa:
        // (You can also check a condition here if necessary.)
        printf("Stack A:\n| %d, is_lis: %d\n| %d, is_lis: %d\n| %d, is_lis: %d\n| %d, is_lis: %d\n| %d, is_lis: %d\n| %d, is_lis: %d\n", (*head_a)->value, (*head_a)->is_lis, (*head_a)->next->value, (*head_a)->next->is_lis, (*head_a)->next->next->value, (*head_a)->next->next->is_lis, (*head_a)->next->next->next->value, (*head_a)->next->next->next->is_lis, (*head_a)->next->next->next->next->value, (*head_a)->next->next->next->next->is_lis, (*head_a)->next->next->next->next->next->value, (*head_a)->next->next->next->next->next->is_lis);

        pa(head_a, tail_a, head_b, tail_b, 's');
    }
}


t_cheapest find_cheapest_rotation(t_node *head_to_push, t_node *head_compare)
{
    t_cheapest rotation;
    int count_rx = 0;
    int count_rrx = 0;
    t_node *candidate = head_to_push;   // the node we want to push
    t_node *current;
    
    // Simulate forward rotations (rx) on head_compare:
    current = head_compare;
    while (!(candidate->index == (current->index - 1)) &&
           count_rx < stack_length(head_compare))  // avoid infinite loop
    {
        current = current->next;
        count_rx++;
    }
    
    // Simulate reverse rotations (rrx) on head_compare:
    current = head_compare;
    while (!(candidate->index == (current->index - 1)) &&
           count_rrx < stack_length(head_compare))
    {
        current = current->prev;
        count_rrx++;
    }
    
    // Choose the cheaper rotation:
    if (count_rx <= count_rrx)
    {
        rotation.iterations = count_rx;
        rotation.move = RX;
    }
    else
    {
        rotation.iterations = count_rrx;
        rotation.move = RRX;
    }
    
    return rotation;
}

char cheapest_path(t_node *head_a, t_node *head_b)
{
    t_cheapest cost_a = find_cheapest_rotation(head_b, head_a);
    t_cheapest cost_b = find_cheapest_rotation(head_a, head_b);
    
    // Here we decide which rotation is cheaper.
    // For example, if cost_a.iterations is greater, it might be cheaper to rotate stack B.
    if (cost_a.iterations > cost_b.iterations)
        return 'b';  // rotate B
    else
        return 'a';  // rotate A
}
