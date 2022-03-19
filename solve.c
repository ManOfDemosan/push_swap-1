/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:15:22 by hmoon             #+#    #+#             */
/*   Updated: 2022/03/19 21:36:20 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_chunks(t_stack *a, t_stack *b, int step)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (i < a->len)
	{
		if (a->data[a->len - 1] <= num)
		{
			pb(a, b);
			rb(a, 0);
			num++;
		}
		else if (a->data[a->len - 1] <= num + step)
		{
			pb(a, b);
			num++;
		}
		else
			ra(a, 0);
		i++;
	}
}

static void	put_num_to_top_b(t_stack *b, int num)
{
	int	index;

	index = 0;
	while (index < b->len && b->data[index] != num)
		index++;
	while (index < b->len / 2 && index >= 0)
	{
		rrb(b, 0);
		index--;
	}
	while (index >= b->len / 2 && index < b->len - 1)
	{
		rb(b, 0);
		index++;
	}
}

static void	sorting_back(t_stack *a, t_stack *b)
{
	int	num;
	int	i;

	num = b->len;
	i = 0;
	while (i < b->len)
	{
		num--;
		put_num_to_top_b(b, num);
		pa(a, b);
		i++;
	}
}

static void	sort(t_stack *a, t_stack *b)
{
	int	step;

	step = 15;
	if (a->size > 250)
		step += 15;
	push_chunks(a, b, step);
	sorting_back(a, b);
}

void	push_swap(t_stack *a, t_stack *b)
{
		sort(a, b);
}
