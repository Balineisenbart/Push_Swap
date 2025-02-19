
#include "push_swap.h"

int main(int argc, char **argv)
{
    if (argc > 1 && argv[0] != NULL)
    {
        t_node *head_a = NULL;
        t_node *tail_a = NULL;
        t_node *head_b = NULL;
        t_node *tail_b = NULL;
        int stack_len;

        if (parse_input(argc, argv, &head_a, &tail_a))
        {
            if (!needs_sorting(head_a))
                return 0;
            stack_len = stack_length(head_a);
            
            print_stack_a_and_stack_b(head_a, head_b);//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

            if (stack_len <= 3)
                sort_2_or_3_elements(&head_a, &tail_a);
            else if (stack_len == 4 || stack_len == 5)
                sort_4_or_5_elements(&head_a, &tail_a, &head_b, &tail_b);
            else if (stack_len > 5)
                complex_sorting(&head_a, &tail_a, &head_b, &tail_b, stack_len);
        }
       print_stack_a_and_stack_b(head_a, head_b);//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


    }
    return 0;
}