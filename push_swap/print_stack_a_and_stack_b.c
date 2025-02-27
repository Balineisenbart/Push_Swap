#include "push_swap.h"
#include <stdio.h>

void print_stack_a_and_stack_b(t_node *head_a, t_node *head_b)
{
    t_node *cur_a = head_a;
    t_node *cur_b = head_b;
    int total_a = 0, total_b = 0;

    if (head_a) {
        do {
            total_a++;
            head_a = head_a->next;
        } while (head_a != cur_a);
    }

    if (head_b) {
        do {
            total_b++;
            head_b = head_b->next;
        } while (head_b != cur_b);
    }

    int max_height = (total_a > total_b) ? total_a : total_b;

    printf("\n   ___     ___  \n");
    printf("      A       B  \n\n");

    for (int i = 0; i < max_height; i++)
    {
        if (cur_a && total_a > 0)
        {
            printf(" %2d - %d", cur_a->value, cur_a->chunk);
            cur_a = cur_a->next;
            total_a--;
        }
        else
            printf("       ");

        printf("   ");

        if (cur_b && total_b > 0)
        {
            printf("%2d - %d", cur_b->value, cur_b->chunk);
            cur_b = cur_b->next;
            total_b--;
        }
        else
            printf("   ");

        printf("\n");
    }
    printf("\n");
}
