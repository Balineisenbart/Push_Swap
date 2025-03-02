

#include "push_swap.h"

static void RX_RB(t_cheapest cost, t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b)
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

static void RRX_RRB(t_cheapest cost, t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b)
{
    if (cost.iterations >= cost.other_r)
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

static void RRX_RB(t_cheapest cost, t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b)
{
    while (cost.iterations-- > 0)
        rra(head_a, tail_a, 's');
    while (cost.other_r-- > 0)
        rb(head_b, tail_b, 's');
}

static void RX_RRB(t_cheapest cost, t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b)
{
    while (cost.iterations-- > 0)
        ra(head_a, tail_a, 's');
    while (cost.other_r-- > 0)
        rrb(head_b, tail_b, 's');
}

void finish(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b)
{
    t_cheapest cost;
    
    if (!(*head_a) || !(*head_b))
        return;
    while (*head_b)
    {
        cost = return_cheapest_arr(head_b, head_a, tail_a, tail_b);
        if (cost.move == RX && cost.dir == RB)
            RX_RB(cost, head_a, tail_a, head_b, tail_b);
        else if (cost.move == RRX && cost.dir == RB)
            RRX_RB(cost, head_a, tail_a, head_b, tail_b);
        else if (cost.move == RRX && cost.dir == RRB)
            RRX_RRB(cost, head_a, tail_a, head_b, tail_b);
        else
            RX_RRB(cost, head_a, tail_a, head_b, tail_b);
        pa(head_a, tail_a, head_b, tail_b, 's');
    }
}

t_cheapest return_cheapest_arr(t_node **head_b, t_node **head_a, t_node **tail_a, t_node **tail_b)
{

    t_cheapest *arr_a = find_cheapest_path_a(head_b, head_a, tail_a, tail_b);
    t_cheapest *arr_rev = find_cheapest_path_rev_a(head_b, head_a, tail_a, tail_b);
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

static int ft_count_rx(t_node *candidate, t_node **head_a, int total_len)
{
    t_node *current;
    int count_rx;

    current = *head_a;
    count_rx = 0;
    while (!(candidate->index == current->index - 1 || ((candidate->index == total_len - 1) && current->index == 0)) && count_rx < stack_length(*head_a))
    {
        current = current->next;
        count_rx++;
        if (count_rx == stack_length(*head_a))
            count_rx = INT_MAX;
    }
    return count_rx;
}

static int ft_count_rrx(t_node *candidate, t_node **head_a, t_node **tail_a, int total_len)
{
    t_node *current;
    t_node *current_tail;
    int count_rrx;

    current = *head_a;
    current_tail = *tail_a;
    count_rrx = 0;
    while (!(candidate->index == current->index - 1 || ((candidate->index == total_len - 1) && current->index == 0)) && count_rrx < stack_length(*head_a))
    {
        current = current_tail;
        current_tail = current_tail->prev;
        count_rrx++;
        if (count_rrx == stack_length(*head_a))
            count_rrx = INT_MAX;
    }
    return count_rrx;
}

static t_cheapest set_rotation(int count, int i, int move)
{
    t_cheapest rotation;

    rotation.move = move;
    rotation.iterations = count; 
    rotation.other_r = i;
    rotation.price = INT_MAX;
    return rotation;
}

static t_cheapest set_arr(t_node *candidate, t_node **head_a, t_node **tail_a, int total_len, int i)
{
    int count_rx;
    int count_rrx;

    count_rx = ft_count_rx(candidate, head_a, total_len);
    count_rrx = ft_count_rrx(candidate, head_a, tail_a, total_len);
    if (count_rx <= count_rrx)
        return set_rotation(count_rx, i, RX);
    else
        return set_rotation(count_rrx, i, RRX);

}

t_cheapest *find_cheapest_path_a(t_node **head_b, t_node **head_a, t_node **tail_a, t_node **tail_b)
{
    t_node *candidate;
    t_cheapest *arr;
    int i;
    int n;
    int total_len;

    candidate = *head_b;
    i = 0;
    n = stack_length(*head_b);
    total_len = stack_length(*head_a) + stack_length(*head_b);
    arr = malloc (n * sizeof(t_cheapest));
    if (!arr)
        return (free(arr), free_stack(head_a, tail_a), free_stack(head_b, tail_b), NULL);
    while (i < n)
    {
        arr[i] = set_arr(candidate, head_a, tail_a, total_len, i);
        i++;
        candidate = candidate->next;
    }
    return arr;
}


t_cheapest *find_cheapest_path_rev_a(t_node **head_b, t_node **head_a, t_node **tail_a, t_node **tail_b)
{
    t_node *candidate;
    t_cheapest *arr;
    int i;
    int n;
    int total_len;

    candidate = *head_b;
    i = 0;
    n = stack_length(*head_b);
    total_len = stack_length(*head_a) + stack_length(*head_b);
    arr = malloc (n * sizeof(t_cheapest));
    if (!arr)
        return (free(arr), free_stack(head_a, tail_a), free_stack(head_b, tail_b), NULL);
    while (i < n)
    {
        arr[i] = set_arr(candidate, head_a, tail_a, total_len, i);
        i++;
        candidate = candidate->prev;
    }
    return arr;
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

    stack = arr;
    if (arr.iterations >= arr.other_r) 
        stack.price = arr.iterations;
    else 
        stack.price = arr.other_r;
   return stack;
}   

