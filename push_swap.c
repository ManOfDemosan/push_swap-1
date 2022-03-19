/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:39:26 by hmoon             #+#    #+#             */
/*   Updated: 2022/03/19 20:50:42 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_num(t_stack *stack, char **argv)
{
	size_t	i;
	size_t	j;
	char	**arr;

	i = 1;
	while (argv[i] != 0)
	{
		j = 0;
		arr = ft_split(argv[i++], 32);
		is_possible(arr);
		if (arr)
		{
			while (arr[j] != 0)
				make_stack(stack, ft_atoi(arr[j++]));
			ft_split_free(arr);
		}
		else
			print_error();
	}
	is_duplicate(stack);
	rotate_a(stack);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		print_error();
	init_stack(&a);
	init_stack(&b);
	parse_num(&a, argv);
	push_swap(&a, &b);
	free(a.data);
	free(b.data);
	return (0);
}

