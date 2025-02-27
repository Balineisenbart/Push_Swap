
#include "push_swap.h"

void return_chunk(t_node **head_a, t_node **head_b, int length)
{

    position_a(head_a, head_b);
    while (head_b)
    {
        largest_bubble_up(head_b, length);
        pa(head_a, tail_a, head_b, tail_b, 's');
    }
}

void position_a(t_node **head_a, t_node **head_b)
{
    

}

void largest_bubble_up(t_node *head_b, int length)
{
    int largest_element;
    int count;

    largest_element = find_largest_elements_position(*head_b);
    if (largest_element > length / 2)
        count = length - largest_element;
    if (largest_element > length / 2)
    {
        while (count-- > 0)
            rrb(head_b, tail_b, 's'); //here i could already position stack a with rrr
    }
    else
    {
        while (largest_element-- > 0)
            rb(head_b, tail_b, 's'); //here i could already position stack a with rr
    }
}