/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 03:06:39 by hmoon             #+#    #+#             */
/*   Updated: 2022/03/23 03:30:39 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_stack *a, t_stack *b)
{
	int	first;
	int	second;

	first = pop_back(a);
	second = pop_back(a);
	push_back(a, first);
	push_back(a, second);
}

void	push(t_stack *src, t_stac *dest)
{
	int	num;

	num = pop_back(src);
	push_back(dest, num);
}

void	rotate(t_stack *stack)
{
	int	num;

	num = pop_back(stack);
	push_stack(stack, num);
}

void	reverse_rotate(t_stack *stack)
{
	int	num;

	num = pop_stack(stack);
	push_back(stack, num);
}

void	order(t_stack *a, t_stack *b, int print)
{

}

