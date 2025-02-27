#include "push_swap.h"

void complex_sorting(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b, int stack_len)
{
    int cheapest;
    int length;
    int chunk_size;
    static int current_chunk;
    static int previous_chunk;

    length = stack_length(head_a);
    chunk_size = determine_chunk_number(head, length);
    current_chunk = length - chunk_size;
    previous_chunk = length;

    index_input(head_a, stack_len);

    print_stack_a_and_stack_b(*head_a, *head_b);   //!!!!!!!!!!
    

    while (needs_sorting(*head_a))
    {


        //find chunk elementsn-> use indexing and update after each round -> start with largest chunk
        //push chunk elements to b
        //push back starting with largest element -> rotate stack a to find good insertion point
        define_chunk(head_a, current_chunk, previous_chunk);

        while (contains_chunk)
        {
            if ((*head_a)->chunk)
            {
                pb(head_a, tail_a, head_b,  tail_b, 's');
                //if (*head_b)
                //    optimize_stack_b(head_b, tail_b);
            }
            else
            {
                cheapest = find_cheapest_chunk_element(*head_a, length);
                while (cheapest-- > 0)
                    ra(head_a, tail_a, 's');
                while (cheapest++ < 0)
                    rra(head_a, tail_a, 's');
            }
            previous_chunk = current_chunk;
            current_chunk -= chunk_size;   
        }
        return_chunk(head_a, head_b, length); 
     
    }
    if (needs_sorting(*head_a))
        bubble_up_a(head_a, tail_a);

}