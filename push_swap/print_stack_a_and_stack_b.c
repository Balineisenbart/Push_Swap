#include "push_swap.h"

void print_stack_a_and_stack_b(t_node *head_a, t_node *head_b)
{
    t_node *current_a = head_a;
    t_node *current_b = head_b;
    int max_height = 0, count_a = 0, count_b = 0;

    if (!head_b)

    // Count elements in Stack A
    if (head_a)
    {
        do {
            count_a++;
            head_a = head_a->next;
        } while (head_a != current_a);
    }

    // Count elements in Stack B
    if (head_b)
    {
        do {
            count_b++;
            head_b = head_b->next;
        } while (head_b != current_b);
    }

    max_height = (count_a > count_b) ? count_a : count_b;
    
    printf("\n   ___     ___  \n");
    printf("    A       B  \n\n");

    for (int i = 0; i < max_height; i++)
    {
        if (current_a && count_a > 0)
        {
            printf("  %3d  ", current_a->value);
            current_a = (current_a->next == head_a) ? NULL : current_a->next;
            count_a--;
        }
        else
            printf("       ");

        printf("   ");

        if (current_b && count_b > 0)
        {
            printf("%3d", current_b->value);
            current_b = (current_b->next == head_b) ? NULL : current_b->next;
            count_b--;
        }
        else
            printf("   ");

        printf("\n");
    }
    printf("\n");
}
