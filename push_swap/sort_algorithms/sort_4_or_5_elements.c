/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4_or_5_elements.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:36:58 by codespace         #+#    #+#             */
/*   Updated: 2025/03/02 12:28:38 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_4_or_5_elements(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b)
{
    int i;

    i = 0;
    if (needs_sorting(*head_a))
    {
        while (stack_length((*head_a)) != 3)
        {
            bubble_up_a(head_a, tail_a);
            pb(head_a, tail_a, head_b, tail_b, 's');
            i++;
        }
        sort_2_or_3_elements(head_a, tail_a);
        while (i != 0)
        {
            pa(head_a, tail_a, head_b, tail_b, 's');
            i--;
        }
    }
}
