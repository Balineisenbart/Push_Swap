
#include "push_swap.h"

int main(int argc, char **argv)
{
    if (argc > 1 && argv[0] != NULL)
    {
        t_node *head_a = NULL;
        t_node *tail_a = NULL;
        t_node *head_b = NULL;
        t_node *tail_b = NULL;

        if (parse_input(argc, argv, &head_a, &tail_a))
        {
            if (!needs_sorting(head_a))
                return 0;
                
            if (stack_length(head_a) <= 2)
                sort_2_or_3_elements(&head_a, &tail_a);
            else if (stack_length(head_a) == 3 || stack_length(head_a) == 4)
                sort_4_or_5_elements(&head_a, &tail_a, &head_b, &tail_b);
            printf("end of sort_4_or_5_elements\n");
                /*
            //sort more than 5
            else if (stack_length(head_a) > 5)
                complex_sorting();
                */
        }
    }

    return 0;
}