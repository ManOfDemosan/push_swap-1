/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 23:15:44 by hmoon             #+#    #+#             */
/*   Updated: 2022/03/23 03:17:43 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	pop_back(t_stack *stack)
{
	stack->len--;
	return (stack->data[stack->len]);
}

void	push_back(t_stack *stack, int num)
{
	stack->data[stack->len] = num;
	stack->len++;
}

int pop_stack(t_stack *stack)
{
	int	num;
	int	i;

	num = stack->data[0];
	i = 0;
	stack->len--;
	while (i < stack->len)
	{
		stack->data[i] = stack->data[i + 1];
		i++;
	}
	return (num);
}

void	push_stack(t_stack *stack, int num)
{
	int	i;

	i = stack->len;
	while (i > 0)
	{
		stack->data[i] = stack->data[i - 1];
		i--;
	}
	stack->data[0] = num;
	stack->len++;
}
