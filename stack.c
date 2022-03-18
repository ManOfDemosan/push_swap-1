/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 21:19:24 by hmoon             #+#    #+#             */
/*   Updated: 2022/03/18 22:30:45 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_stack(t_stack *stack, int num)
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
	stack->data[(stack->len)++] = num;
}

void	init_stack(t_stack *stack)
{
	stack->data = malloc(sizeof(int));
	if (!stack->data)
		print_error();
	stack->len = 0;
	stack->size = 1;
}
