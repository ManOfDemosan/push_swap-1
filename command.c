/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:08:10 by hmoon             #+#    #+#             */
/*   Updated: 2022/03/19 21:40:47 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a, int print)
{
	int	temp;
	int	idx;

	idx = a->len - 1;
	if (a->len >= 2)
	{
		temp = a->data[idx];
		a->data[idx] = a->data[idx - 1];
		a->data[idx - 1] = temp;
	}
	if (print == 0)
		write(1, "sa\n", 3);
}

void	sb(t_stack *b, int print)
{
	int	temp;
	int	idx;

	idx = b->len - 1;
	if (b->len >= 2)
	{
		temp = b->data[idx];
		b->data[idx] = b->data[idx - 1];
		b->data[idx - 1] = temp;
	}
	if (print == 0)
		write(1, "sb\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->len >= 1)
	{
		a->len++;
		a->data[a->len - 1] = b->data[b->len - 1];
		b->len--;
	}
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	make_stack(b, a->data[a->len - 1]);
	a->len--;
	write(1, "pb\n", 3);
}

void	ra(t_stack *a, int print)
{
	int		temp;
	int	idx;

	idx = 0;
	temp = a->data[0];
	if (a->len > 1)
	{
		while (idx < a->len)
		{
			a->data[idx] = a->data[idx + 1];
			idx++;
		}
		a->data[idx] = temp;
	}
	if (print == 0)
		write(1, "ra\n", 3);
}

void	rb(t_stack *b, int print)
{
	int		temp;
	int	idx;

	idx = 0;
	temp = b->data[0];
	if (b->len > 1)
	{
		while (idx < b->len)
		{
			b->data[idx] = b->data[idx + 1];
			idx++;
		}
		b->data[idx] = temp;
	}
	if (print == 0)
		write(1, "rb\n", 3);
}

void	rra(t_stack *a, int print)
{
	int	temp;
	int	idx;

	idx = 0;
	temp = a->data[a->len - 1];
	if (a->len > 1)
	{
		while (idx < a->len)
		{
			a->data[a->len - 1 - idx] = a->data[a->len - 2 - idx];
			idx++;
		}
		a->data[0] = temp;
	}
	if (print == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *b, int print)
{
	int	temp;
	int	idx;

	idx = 0;
	temp = b->data[b->len - 1];
	if (b->len > 1)
	{
		while (idx < b->len)
		{
			b->data[b->len - 1 - idx] = b->data[b->len - 2 - idx];
			idx++;
		}
		b->data[0] = temp;
	}
	if (print == 0)
		write(1, "rrb\n", 4);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a, 1);
	sb(b, 1);
	write(1, "ss\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a, 1);
	rb(b, 1);
	write(1, "rr\n", 3);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a, 1);
	rrb(b, 1);
	write(1, "rrr\n", 4);
}
