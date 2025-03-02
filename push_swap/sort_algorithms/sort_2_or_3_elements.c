/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_or_3_elements.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:36:50 by codespace         #+#    #+#             */
/*   Updated: 2025/03/02 12:28:44 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void sort_2_or_3_elements(t_node **head, t_node **tail)
{
    while(needs_sorting(*head))
    {
        if (find_largest_elements_position(*head) == stack_length(*head) - 1)
            sa(head, tail, 's');
        else if (find_largest_elements_position(*head) == 0)
            ra(head, tail, 's');
        else
        {
            if (find_smallest_elements_position(*head) == stack_length(*head) - 1)
                rra(head, tail, 's');
            else
            {
                rra(head, tail, 's');
                sa(head, tail, 's');
            }
        }
    }
}
