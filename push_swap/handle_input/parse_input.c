/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:36:14 by codespace         #+#    #+#             */
/*   Updated: 2025/03/02 16:37:10 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_input(int argc, char **argv, t_node **stack, t_node **tail)
{
	int	result;

	if (argc == 2)
		result = two_args(argv, stack, tail);
	else if (argc > 2)
		result = more_args(argc, argv, stack, tail);
	return (result);
}

int	two_args(char **argv, t_node **stack, t_node **tail)
{
	int		i;
	int		j;
	long	input_value;
	char	**numbers;

	i = 1;
	j = 0;
	numbers = ft_split(argv[i], ' ');
	while (numbers[j] != NULL)
	{
		input_value = ft_atoi(numbers[j]);
		if (!(is_valid(numbers[j])) || has_duplicates(*stack, input_value))
		{
			free_stack(stack, tail);
			free_split_array(numbers);
			write(2, "Error\n", 6);
			return (0);
		}
		add_to_stack(stack, tail, input_value);
		j++;
	}
	free_split_array(numbers);
	return (1);
}

int	more_args(int argc, char **argv, t_node **stack, t_node **tail)
{
	int		i;
	long	input_value;

	i = 1;
	while (i < argc)
	{
		input_value = ft_atoi(argv[i]);
		if (!(is_valid(argv[i])) || has_duplicates(*stack, input_value))
		{
			free_stack(stack, tail);
			write(2, "Error\n", 6);
			return (0);
		}
		if (*argv[i] == ' ')
			i++;
		add_to_stack(stack, tail, input_value);
		i++;
	}
	return (1);
}

static void	init_new_node(t_node *new_node, int input_value)
{
	new_node->chunk = 0;
	new_node->index = 0;
	new_node->value = input_value;
	new_node->next = NULL;
	new_node->prev = NULL;
}

void	add_to_stack(t_node **head, t_node **tail, int input_value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
	{
		free(new_node);
		free_stack(head, tail);
		exit(EXIT_FAILURE);
	}
	init_new_node(new_node, input_value);
	if (*head == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*head = new_node;
		*tail = new_node;
	}
	else
	{
		new_node->prev = *tail;
		new_node->next = *head;
		(*tail)->next = new_node;
		(*head)->prev = new_node;
		*tail = new_node;
	}
}
