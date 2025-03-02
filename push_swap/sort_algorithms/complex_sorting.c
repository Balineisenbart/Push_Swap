/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sorting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:36:42 by codespace         #+#    #+#             */
/*   Updated: 2025/03/02 12:28:51 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void complex_sorting(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b, int length)
{
    int        chunk_size;
    static int current_chunk;
    static int previous_chunk;

    chunk_size = determine_chunk_number(length);
    previous_chunk = length - 1;
    current_chunk = previous_chunk - chunk_size + 1;
    index_input(head_a, length);
    while (needs_sorting(*head_a))
    {
        define_chunk(head_a, current_chunk, previous_chunk);
        while (contains_chunk(*head_a))
            push_chunk(head_a, tail_a, head_b, tail_b, length);
        previous_chunk = current_chunk - 1;
        current_chunk = previous_chunk - chunk_size + 1;
        finish(head_a, tail_a, head_b, tail_b);
    }
    if (needs_sorting(*head_a))
        bubble_up_a(head_a, tail_a);
}
void push_chunk(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b, int length)
{
    int cheapest;

    if ((*head_a)->chunk)
    {
        (*head_a)->chunk = 0;
        pb(head_a, tail_a, head_b, tail_b, 's');
    }
    else
    {
        cheapest = find_cheapest_chunk_element(*head_a, length);
        while (cheapest > 0)
        {
            ra(head_a, tail_a, 's');
            cheapest--;
        }
        while (cheapest < 0)
        {
            rra(head_a, tail_a, 's');
            cheapest++;
        }
    }
}
