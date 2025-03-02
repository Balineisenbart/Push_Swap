/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:37:06 by codespace         #+#    #+#             */
/*   Updated: 2025/03/02 16:30:36 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_sorting(t_node **head_a, t_node **tail_a, t_node **head_b,
		t_node **tail_b)
{
	int	stack_len;

	stack_len = stack_length(*head_a);
	if (stack_len <= 3)
		sort_2_or_3_elements(head_a, tail_a);
	else if (stack_len == 4 || stack_len == 5)
		sort_4_or_5_elements(head_a, tail_a, head_b, tail_b);
	else if (stack_len > 5)
		complex_sorting(head_a, tail_a, head_b, tail_b);
}

static int	free_both_stacks(t_node **head_a, t_node **tail_a, t_node **head_b,
		t_node **tail_b)
{
	free_stack(head_a, tail_a);
	free_stack(head_b, tail_b);
	return (0);
}

int	main(int argc, char **argv)
{
	t_node	*head_a;
	t_node	*tail_a;
	t_node	*head_b;
	t_node	*tail_b;

	if (argc < 2 || (argc == 2 && (argv[1][0] == '\0' || argv[1][0] == ' ')))
		write(2, "Error\n", 6);
	else if (argc > 1 && argv[0] != NULL)
	{
		head_a = NULL;
		tail_a = NULL;
		head_b = NULL;
		tail_b = NULL;
		if (parse_input(argc, argv, &head_a, &tail_a))
		{
			if (!needs_sorting(head_a))
				return (free_both_stacks(&head_a, &tail_a, &head_b, &tail_b),
					0);
			do_sorting(&head_a, &tail_a, &head_b, &tail_b);
		}
		free_both_stacks(&head_a, &tail_a, &head_b, &tail_b);
	}
	return (0);
}
