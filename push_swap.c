/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:39:26 by hmoon             #+#    #+#             */
/*   Updated: 2022/03/18 22:27:59 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**numarr;
	int	i;
	int	j;
	size_t	idx;
	t_stack	a;
	i = 1;
	idx = 0;
	if (argc < 2)
		exit(0);
	init_stack(&a);
	while (argv[i] != 0)
	{
		j = 0;
		numarr = ft_split(argv[i++], 32);
		is_possible(numarr);
		while (numarr[j] != 0)
			make_stack(&a, ft_atoi(numarr[j++]));
		if (numarr)
			ft_split_free(numarr);
	}
	is_duplicate(&a);
	while (idx < a.len)
		printf("%d\n", a.data[idx++]);
	free(a.data);
	return (0);
}
