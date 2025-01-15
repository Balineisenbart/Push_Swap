
#include "push_swap.h"

int main(int argc, char **argv)
{
    if (argc > 1 && argv[0] != NULL)
    {
        t_node *head_a = NULL;
        t_node *tail_a = NULL;
//        t_node *head_b = NULL;
//       t_node *tail_b = NULL;

        parse_input(argc, argv, &head_a, &tail_a);
        if (!needs_sorting(head_a))
            return 0;


        //sort 3        if (head_a/b != NULL)
        if (stack_length(head_a) <= 3)
            sort_2_or_3_elements(&head_a, &tail_a);
       /* //sort 5
        else if (stack_length(head_a) == 4 || stack_length(head_a) == 5)
            sort_4_or_5_elements();
        //sort more than 5
        else if (stack_length(head_a) > 5)
            complex_sorting();*/

    }

    return 0;
}