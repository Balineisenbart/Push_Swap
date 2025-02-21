

#include "push_swap.h"

void finish(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b)
{
    t_cheapest cost;
    char stack_to_rotate;
    int size_a;
    int size_b;

    size_a = stack_length(*head_b);
    size_b = stack_length(*head_a);

    while (*head_b)
    {
        printf(" +++    INSIDE FINISH    +++ \n");

        //find if it is cheaper to rotate stack a or stack b
        stack_to_rotate = find_cheaper_stack(*head_a, *tail_a, *head_b, *tail_b);
        if (stack_to_rotate == 'a')
        {
            cost = find_cheapest_arr(find_cheapest_path_a(*head_b, *head_a, *tail_a), size_a);
            printf("Stack A is cheaper\ncost.iterations %d\n", cost.iterations);
            if (cost.move == RX) //currently other stack only forward rotated. thus here always rr
            {
                while (cost.iterations-- > 0)
                {
                    rr(head_a, tail_a, head_b, tail_b, 'd');
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
        else if (stack_to_rotate == 'b')
        {
            cost = find_cheapest_arr(find_cheapest_path_a(*head_a, *head_b, *tail_b), size_b);
            printf("Stack B is cheaper\ncost.iterations %d\n", cost.iterations);
            if (cost.iterations == 0)
                ra(head_a, tail_a, 's');
            if (cost.move == RX)
            {
                while (cost.iterations-- > 0)
                {
                    rr(head_a, tail_a, head_b, tail_b, 'd');
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
        }
        current = head_a;
        current_tail = tail_a;
        while (!(candidate->index == current->index - 1 || candidate->index == current_tail->index + 1) && count_rrx < stack_length(head_a))
        {
            current = current_tail;
            current_tail = current_tail->prev;
            count_rrx++;
        }

        if (count_rx <= count_rrx)
        {
            rotation.move = RX;
            rotation.iterations = count_rx - i; //deduct here i from count ->need to implement rr
            rotation.other_r = i;
            arr[i] = rotation;
        }
        else
        {
            rotation.move = RX; //when i == count ->only rr; when count > i, need additional ra, when i > count, need additional rb
            rotation.iterations = count_rx + i;
            rotation.other_r = i;
            arr[i] = rotation;
        } 
        i++;
        candidate = head_b->next; //equals one rb ?? do the same with rrb head_b->prev (x)
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
            rotation.move = RX; //when i == count ->only rr; when count > i, need additional ra, when i > count, need additional rb
            rotation.iterations = count_rx - i;
            rotation.other_r = i;
            arr[i] = rotation;
        }
        else
        {
            rotation.move = RRX;
            rotation.iterations = count_rrx + i; //deduct here i from count if other stack was backwards rotated. see next comment (x)
            arr[i] = rotation;
        } 
        i++;
        candidate = head_b->next; //equals one rb ?? do the same with rrb head_b->prev (x)
    }
    return arr;
}

char find_cheaper_stack(t_node *head_a, t_node *tail_a, t_node *head_b, t_node *tail_b)
{
    //find out which move is cheaper rx or rrx
    t_cheapest cost_a;
    t_cheapest cost_b;
    int size_a;
    int size_b;

    cost_a.iterations = INT_MAX;
    cost_b.iterations = INT_MAX;
    size_a = stack_length(head_a);
    size_b = stack_length(head_b);


    if (!(stack_length(head_a) == 1))
        cost_a = find_cheapest_arr(find_cheapest_path_a(head_b, head_a, tail_a), size_a);
    if (!(stack_length(head_b) == 1))
        cost_b = find_cheapest_arr(find_cheapest_path_b(head_a, head_b, tail_b), size_b);

    printf("cost_a.iterations %d\ncost_a.move %d\n", cost_a.iterations, cost_a.move);
    printf("cost_b.iterations %d\ncost_b.move %d\n", cost_b.iterations, cost_b.move);

    if (cost_a.iterations < cost_b.iterations)
        return 'a';
    else
        return 'b';
}

t_cheapest find_cheapest_arr(t_cheapest *arr, int size)
{
    t_cheapest smallest;
    int i;

    smallest = arr[0];
    i = 0;

    while (i < size)
    {
        if (arr[i].iterations < smallest.iterations)
        {
            smallest = arr[i];
        }
        i++;
    }
    return smallest;
}