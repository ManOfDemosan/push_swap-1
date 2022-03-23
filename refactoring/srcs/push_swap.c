/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 23:03:55 by hmoon             #+#    #+#             */
/*   Updated: 2022/03/23 17:04:13 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 3)
		return (0);
	init_stack(&a);
	parse_num(&a, argv);
	is_duplicate(&a);
	is_sorted(&a);
	make_index(&a);
	make_stack_b(&b, a.len);
	push_swap(&a, &b);
	free(a.data);
	free(b.data);
	return (0);
}
