/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:36:18 by codespace         #+#    #+#             */
/*   Updated: 2025/03/02 12:31:20 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_length(t_node *head)
{
    t_node *temp = head;
    int     i;

    i = 0;
    while(temp->next != head)
    {
        i++;
        temp = temp->next;
    }
    i++;
    return i;
}
