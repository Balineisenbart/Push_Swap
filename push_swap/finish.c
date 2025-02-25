

#include "push_swap.h"

void finish(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b)
{
    t_cheapest cost;
    char stack_to_rotate;

    if (!(*head_a) || !(h*head_b))
        return;

    while (*head_b)
    {
        printf(" +++    INSIDE FINISH    +++ \n");

        //find if it is cheaper to rotate stack a or stack b
        stack_to_rotate = find_cheaper_stack(*head_a, *tail_a, *head_b, *tail_b);
        if (stack_to_rotate == 'a')
        {
            cost = find_cheapest_arr(find_cheapest_path_a(*head_b, *head_a, *tail_a), *head_b);
            printf("Stack A is cheaper\ncost.price %d\ncost.iterations %d\ncost.other_r %d\ncost.move %d\n", cost.price, cost.iterations, cost.other_r, cost.move);
            if (cost.move == RX)
            {
                if (cost.iterations >= cost.other_r)
                {    
                    while (cost.other_r-- > 0)
                    {
                        rr(head_a, tail_a, head_b, tail_b, 'd');
                        cost.iterations--;
                    }
                    while (cost.iterations-- > 0)
                        ra(head_a, tail_a, 's');
                }
                if (cost.other_r > cost.iterations)
                {
                    while (cost.iterations-- > 0)
                    {
                        rr(head_a, tail_a, head_b, tail_b, 'd');
                        cost.other_r--;
                    }
                    while (cost.other_r-- > 0)
                        rb(head_b, tail_b, 's');
                }
            }
            else
            {
                while (cost.iterations-- > 0)
                {
                    rra(head_a, tail_a, 's');
                }
                while (cost.other_r-- > 0)
                    rb(head_b, tail_b, 's');
            }
        }
        else if (stack_to_rotate == 'b')
        {
            cost = find_cheapest_arr(find_cheapest_path_b(*head_a, *head_b, *tail_b), *head_a);
            printf("Stack B is cheaper\ncost.iterations %d\n", cost.iterations);
            if (cost.iterations == 0) // needed for discrepancy between source and destination stack???
                ra(head_a, tail_a, 's');
            if (cost.move == RX)
            {
                if (cost.iterations >= cost.other_r)
                {    
                    while (cost.other_r-- > 0)
                    {
                        rr(head_a, tail_a, head_b, tail_b, 'd');
                        cost.iterations--;
                    }
                   while (cost.iterations-- >0)
                        rb(head_b, tail_b, 's');
                }
                if (cost.other_r > cost.iterations)
                {
                    while (cost.iterations-- > 0)
                    {
                        rr(head_a, tail_a, head_b, tail_b, 'd');
                        cost.other_r--;
                    }
                    while (cost.other_r-- > 0)
                        ra(head_a, tail_a, 's');
                }
            }
            else
            {
                while (cost.iterations-- > 0)
                {
                    rrb(head_b, tail_b, 's');
                }
                while (cost.other_r-- > 0)
                    ra(head_a, tail_a, 's');
            }
        }
        print_stack_a_and_stack_b(*head_a, *head_b);//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

        pa(head_a, tail_a, head_b, tail_b, 's');

        print_stack_a_and_stack_b(*head_a, *head_b);//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    }
    printf(" +++    EXIT FINISH    +++ \n");

}

t_cheapest *find_cheapest_path_a(t_node *head_b, t_node *head_a, t_node *tail_a)
{
    t_cheapest rotation;
    t_cheapest *arr;
    t_node *current;
    t_node *candidate;
    t_node *current_tail;
    int count_rx;
    int count_rrx;
    int n;
    int i;


    candidate = head_b;
    n = stack_length(head_b);
    i = 0;
    arr = malloc (n * sizeof(t_cheapest));
    if (!arr)
        return NULL; //here need to free ALL previous allocated memory!!!! ->function
    while (i < n)
    {
        count_rx = 0;
        count_rrx = 0;
        current = head_a;
        current_tail = tail_a;
        while (!(candidate->index == current->index - 1 || candidate->index == current_tail->index + 1) && count_rx < stack_length(head_a))
        {
            
            current_tail = current;
            current = current->next;
            count_rx++;

            printf(" ... compute all rx ...\n");
            printf("count_rx %d | i %d\n", count_rx, i);
            printf("current_head %d\ncurrent_tail %d\ncandidate(head of B) %d\n", current->value, current_tail->value, candidate->value);


        }
        current = head_a;
        current_tail = tail_a;
        while (!(candidate->index == current->index - 1 || candidate->index == current_tail->index + 1) && count_rrx < stack_length(head_a))
        {
            current = current_tail;
            current_tail = current_tail->prev;
            count_rrx++;

            printf(" ... compute all rrx ...\n");
            printf("count_rrx %d | i %d\n", count_rrx, i);
            printf("current_head %d\ncurrent_tail %d\ncandidate(head of B) %d\n", current->value, current_tail->value, candidate->value);

        }

        if (count_rx <= count_rrx)
        {
            printf(">>> RX cheaper <<<\n");
            rotation.move = RX;
            rotation.iterations = count_rx; 
            rotation.other_r = i;
            arr[i] = rotation;
        }
        else
        {
            printf(">>> RRX cheaper <<<\n");
            rotation.move = RRX;
            rotation.iterations = count_rrx;
            rotation.other_r = i;
            arr[i] = rotation;
        } 
        i++;
        candidate = candidate->next; //do the same with rrb head_b->prev (x)
    }

    return arr;
}

t_cheapest *find_cheapest_path_b(t_node *head_a, t_node *head_b, t_node *tail_b)
{
    t_cheapest rotation;
    t_cheapest *arr;
    t_node *current;
    t_node *candidate;
    t_node *current_tail;
    int count_rx;
    int count_rrx;
    int n;
    int i;


    candidate = head_a;
    n = stack_length(head_a);
    i = 0;
    arr = malloc (n * sizeof(t_cheapest));
    if (!arr)
        return NULL; //here need to free ALL previous allocated memory!!!!
    while (i < n)
    {
        count_rx = 0;
        count_rrx = 0;
        current = head_b;
        current_tail = tail_b;
        while (!(candidate->index == current->index - 1 || candidate->index == current_tail->index + 1) && count_rx < stack_length(head_b))
        {
            current_tail = current;
            current = current->next;
            count_rx++;
        }
        current = head_b;
        current_tail = tail_b;
        while (!(candidate->index == current->index - 1 || candidate->index == current_tail->index + 1) && count_rrx < stack_length(head_b))
        {
            current = current_tail;
            current_tail = current_tail->prev;
            count_rrx++;
        }

        if (count_rx <= count_rrx)
        {
            rotation.move = RX; 
            rotation.iterations = count_rx;
            rotation.other_r = i;
            arr[i] = rotation;
        }
        else
        {
            rotation.move = RRX;
            rotation.iterations = count_rrx; 
            rotation.other_r = i;
            arr[i] = rotation;
        } 
        i++;
        candidate = candidate->next; //do the same with rrb head_b->prev (x)
    }
    return arr;
}

char find_cheaper_stack(t_node *head_a, t_node *tail_a, t_node *head_b, t_node *tail_b)
{
    //find out which move is cheaper rx or rrx
    t_cheapest cost_a;
    t_cheapest cost_b;

    //printf(" +++    INSIDE CHEAPER STACK   +++ \n");

    cost_a.price = INT_MAX;
    cost_b.price = INT_MAX;

    if (!(stack_length(head_a) == 1))
        cost_a = find_cheapest_arr(find_cheapest_path_a(head_b, head_a, tail_a), head_b); //!!switched sized - size is passed to arr[i] it is the maximum number of opposite stack rotations
    if (!(stack_length(head_b) == 1))
        cost_b = find_cheapest_arr(find_cheapest_path_b(head_a, head_b, tail_b), head_a);

    //printf("lowest.price %d\ncost_a.iterations %d\ncost_a.other_r %d\n", cost_a.price, cost_a.iterations, cost_a.other_r);
    //printf("lowest.price %d\ncost_a.iterations %d\ncost_a.other_r %d\n", cost_b.price, cost_b.iterations, cost_b.other_r);

    //printf(" +++    EXIT CHEAPER STACK   +++ \n");



    if (cost_a.price < cost_b.price)
        return 'a';
    else
        return 'b';
}

t_cheapest price_calc(t_cheapest arr)
{
    t_cheapest stack;

    //printf(" +++    INSIDE BEST PRICE   +++ \n");

    stack = arr;
    if (arr.iterations >= arr.other_r) 
        stack.price = arr.iterations;
    else 
        stack.price = arr.other_r;

    //printf("lowest.price %d\nstack.iterations %d\nstack.other_r %d\n", stack.price, stack.iterations, stack.other_r);

    //printf(" +++    EXIT BEST PRICE   +++ \n");
   return stack;
}   

t_cheapest find_cheapest_arr(t_cheapest *arr, t_node *head)
{
    t_cheapest smallest;
    int size;
    int i;

    size = stack_length(head);
    i = 0;

    while (i < size)
    {
        printf("arr[%d]\nsize: %d", i, size);
        arr[i] = price_calc(arr[i]);
        i++;
    }
    i = 0;
    smallest = arr[0];
    while (i < size)
    {
        if (arr[i].price < smallest.price)
        {
            smallest = arr[i];
        }
        i++;
    }
    free(arr);

    return smallest;
}