
void sort_2_or_3_elements(t_node **head, t_node **tail)
{
    //if largest_value = stack_length: sa
    //if largest_value = 0: ra & sa()
    //else 
    // --if smallest value = stack_length: rra
    // --else: rra & sa
    //after each operation print & check if needs sorting

    if (find_largest_elements_position(head) == stack_length(head))
        sa(head);
    else if (find_largest_elements_position(head) == 0)
        ra(*head, *tail);
    else
    {
        if (find_smallest_element(head) == stack_length(head))
            rra(*head, *tail)
        else
        {
            rra(*head, *tail);
            sa(*head, *tail);
        }
    }

}