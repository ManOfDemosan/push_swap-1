/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 03:06:39 by hmoon             #+#    #+#             */
/*   Updated: 2022/03/23 03:16:52 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_stack *a, t_stack *b, enum e_order set)
{
	int	first;
	int	second;

	if (set == sa || set == ss)
	{
		first = pop_back(a);
		second = pop_back(a);
		push_back(a, first);
		push_back(a, second);
	}
	if (set == sb || set == ss)
	{
		first = pop_back(b);
		second = pop_back(b);
		push_back(b, first);
		push_back(b, second);
	}
}


