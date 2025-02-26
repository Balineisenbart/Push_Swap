

#include "push_swap.h"

void finish(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b)
{
    t_cheapest cost;
    

    if (!(*head_a) || !(*head_b))
        return;

    while (*head_b)
    {
        cost = return_cheapest_arr(head_b, head_a, tail_a);
        if (cost.move == RX && cost.dir == RB)
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
        else if (cost.move == RRX && cost.dir == RB)
        {
            while (cost.iterations-- > 0)
                rra(head_a, tail_a, 's');
            while (cost.other_r-- > 0)
                rb(head_b, tail_b, 's');
        }

        else if (cost.move == RRX && cost.dir == RRB)
        {
            if (cost.iterations >= cost.other_r) //.iterations = rra; .other_r = rrb
            {
                while (cost.other_r-- > 0)
                {
                    rrr(head_a, tail_a, head_b, tail_b, 'd');
                    cost.iterations--;
                }
                while (cost.iterations-- > 0)
                    rra(head_a, tail_a, 's');
            }
            if (cost.other_r > cost.iterations)
            {
                while (cost.iterations-- > 0)
                {
                    rrr(head_a, tail_a, head_b, tail_b, 'd');
                    cost.other_r--;
                }
                while (cost.other_r-- > 0)
                    rrb(head_b, tail_b, 's');
            }
        }
        else //if RX && RRB
        {
            while (cost.iterations-- > 0)
                ra(head_a, tail_a, 's');
            while (cost.other_r-- > 0)
                rrb(head_b, tail_b, 's');
        }

        pa(head_a, tail_a, head_b, tail_b, 's');
    }
}

t_cheapest *find_cheapest_path_a(t_node **head_b, t_node **head_a, t_node **tail_a)
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
    int total_len;

    candidate = *head_b;
    n = stack_length(*head_b);
    i = 0;
    total_len = stack_length(*head_a) + stack_length(*head_b);
    arr = malloc (n * sizeof(t_cheapest));
    if (!arr)
        return NULL; //here need to free ALL previous allocated memory!!!! ->function
    while (i < n)
    {
        count_rx = 0;
        count_rrx = 0;
        current = *head_a;
        current_tail = *tail_a;
        while (!(candidate->index == current->index - 1 || ((candidate->index == total_len - 1) && current->index == 0)) && count_rx < stack_length(*head_a))
        {
            //printf("INSIDE FORWARD\n");
            //print_stack_a_and_stack_b(*head_a, *head_b);

           
            /*printf(" ... compute all ra ...\n");
            printf("count_rx %d | i %d\n", count_rx, i);*/
            //printf("current_head %d index %d\ncurrent_tail %d index %d\ncandidate %d index %d\n", current->value, current->index, current_tail->value, current_tail->index, candidate->value, candidate->index);


            current_tail = current;
            current = current->next;
            count_rx++;
            if (count_rx == stack_length(*head_a))
                count_rx = INT_MAX;

        }
        current = *head_a;
        current_tail = *tail_a;
        while (!(candidate->index == current->index - 1 || ((candidate->index == total_len - 1) && current->index == 0)) && count_rrx < stack_length(*head_a))
        {
            //printf("INSIDE REVERSE\n");
            //print_stack_a_and_stack_b(*head_a, *head_b);

        
            /*printf(" ... compute all rra ...\n");
            printf("count_rrx %d | i %d\n", count_rrx, i);*/
            //printf("current_head %d index %d\ncurrent_tail %d index %d\ncandidate %d index %d\n", current->value, current->index, current_tail->value, current_tail->index, candidate->value, candidate->index);


            current = current_tail;
            current_tail = current_tail->prev;
            count_rrx++;
            if (count_rrx == stack_length(*head_a))
                count_rrx = INT_MAX;
        }

        if (count_rx <= count_rrx)
        {
            rotation.move = RX;
            rotation.iterations = count_rx; 
            rotation.other_r = i;
            rotation.price = INT_MAX;
            arr[i] = rotation;
        }
        else
        {
            rotation.move = RRX;
            rotation.iterations = count_rrx;
            rotation.other_r = i;
            rotation.price = INT_MAX;
            arr[i] = rotation;
        } 
        i++;
        candidate = candidate->next; //do the same with rrb candidate = candidate->prev
    }

    return arr;
}


t_cheapest *find_cheapest_path_rev_a(t_node **head_b, t_node **head_a, t_node **tail_a)
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
    int total_len;

    candidate = *head_b;
    n = stack_length(*head_b);
    i = 0;
    total_len = stack_length(*head_a) + stack_length(*head_b);
    arr = malloc (n * sizeof(t_cheapest));
    if (!arr)
        return NULL; //here need to free ALL previous allocated memory!!!! ->function
    while (i < n)
    {
        count_rx = 0;
        count_rrx = 0;
        current = *head_a;
        current_tail = *tail_a;
        while (!(candidate->index == current->index - 1 || ((candidate->index == total_len - 1) && current->index == 0)) && count_rx < stack_length(*head_a))
        {
            //printf("INSIDE FORWARD\n");
            //print_stack_a_and_stack_b(*head_a, *head_b);

           
            /*printf(" ... compute all ra ...\n");
            printf("count_rx %d | i %d\n", count_rx, i);*/
            //printf("current_head %d index %d\ncurrent_tail %d index %d\ncandidate %d index %d\n", current->value, current->index, current_tail->value, current_tail->index, candidate->value, candidate->index);


            current_tail = current;
            current = current->next;
            count_rx++;
            if (count_rx == stack_length(*head_a))
                count_rx = INT_MAX;

        }
        current = *head_a;
        current_tail = *tail_a;
        while (!(candidate->index == current->index - 1 || ((candidate->index == total_len - 1) && current->index == 0)) && count_rrx < stack_length(*head_a))
        {
            //printf("INSIDE REVERSE\n");
            //print_stack_a_and_stack_b(*head_a, *head_b);

        
            /*printf(" ... compute all rra ...\n");
            printf("count_rrx %d | i %d\n", count_rrx, i);*/
            //printf("current_head %d index %d\ncurrent_tail %d index %d\ncandidate %d index %d\n", current->value, current->index, current_tail->value, current_tail->index, candidate->value, candidate->index);


            current = current_tail;
            current_tail = current_tail->prev;
            count_rrx++;
            if (count_rrx == stack_length(*head_a))
                count_rrx = INT_MAX;
        }

        if (count_rx <= count_rrx)
        {
            rotation.move = RX;
            rotation.iterations = count_rx; 
            rotation.other_r = i;
            rotation.price = INT_MAX;
            arr[i] = rotation;
        }
        else
        {
            rotation.move = RRX;
            rotation.iterations = count_rrx;
            rotation.other_r = i;
            rotation.price = INT_MAX;
            arr[i] = rotation;
        } 
        i++;
        candidate = candidate->prev;
    }
    return arr;
}

t_cheapest return_cheapest_arr(t_node **head_b, t_node **head_a, t_node **tail_a)
{

    t_cheapest *arr_a = find_cheapest_path_a(head_b, head_a, tail_a);
    t_cheapest *arr_rev = find_cheapest_path_rev_a(head_b, head_a, tail_a);
    t_cheapest cheapest;
    t_cheapest cheapest1;
    t_cheapest cheapest2;

    cheapest1 = find_cheapest_arr(arr_a, head_b);
    cheapest2 = find_cheapest_arr(arr_rev, head_b);

    if (cheapest1.price <= cheapest2.price)
    {
       cheapest = cheapest1;
       cheapest.dir = RB;
    }
    else
    {
       cheapest = cheapest2;
       cheapest.dir = RRB;
    }
    
    return cheapest;
}

t_cheapest find_cheapest_arr(t_cheapest *arr, t_node **head)
{
    t_cheapest smallest;
    int size;
    int i;

    size = stack_length(*head);
    i = 0;

    while (i < size)
    {
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

