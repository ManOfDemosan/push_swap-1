/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 02:10:53 by hmoon             #+#    #+#             */
/*   Updated: 2022/03/23 03:02:23 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->len - 1)
	{
		if (a->data[i] < a->data[i + 1])
			return ;
		i++;
	}
	exit(0);
}

void	make_index(t_stack *a)
{
	int	*temp;
	int	i;
	int	j;

	i = 0;
	temp = (int *)malloc(sizeof(int) * a->len);
	if (temp == NULL)
		print_error();
	while (i < a->len)
	{
		j = 0;
		temp[i] = 0;
		while (j < a->len)
		{
			if (a->data[i] > a->data[j])
				temp[i]++;
			// printf("a->data[%d] == %d\n", i, a->data[i]);
			j++;
		}
		i++;
	}
	free(a->data);
	a->data = NULL;
	a->data = temp;
}

void	make_stack_b(t_stack *b, int size)
{
	b->data = malloc(sizeof(int) * size);
	if (!b->data)
		print_error();
	b->len = 0;
	b->size = size;
}

void	make_stack_a(t_stack *stack, int num)
{
	int	*temp;

	if (stack->len >= stack->size)
	{
		temp = malloc(sizeof(int) * (stack->size << 1));
		if (!temp)
			print_error();
		ft_memcpy(temp, stack->data, (stack->len * sizeof(int)));
		free(stack->data);
		stack->data = temp;
		stack->size <<= 1;
	}
	push_stack(stack, num);
}

void	init_stack(t_stack *stack)
{
	stack->data = malloc(sizeof(int) * 100);
	if (!stack->data)
		print_error();
	stack->len = 0;
	stack->size = 1;
}
