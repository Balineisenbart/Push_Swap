/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:36:18 by codespace         #+#    #+#             */
/*   Updated: 2025/03/02 16:36:06 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_length(t_node *head)
{
	t_node	*temp;
	int		i;

	temp = head;
	i = 0;
	while (temp->next != head)
	{
		i++;
		temp = temp->next;
	}
	i++;
	return (i);
}

long	ft_atoi(const char *str)
{
	long	res;
	int		isnegative;
	int		i;

	res = 0;
	i = 0;
	isnegative = 0;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
		i++;
	if (str[i] == '-')
		isnegative = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		res *= 10;
		res += ((int)str[i] - 48);
		i++;
	}
	if (isnegative)
		return (-res);
	else
		return (res);
}
