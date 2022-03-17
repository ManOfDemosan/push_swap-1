/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:39:26 by hmoon             #+#    #+#             */
/*   Updated: 2022/03/17 21:12:36 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**numarr;
	int		num;
	int	i;
	int	j;
	i = 1;
	if (argc < 2)
		exit(0);
	while (argv[i] != 0)
	{
		j = 0;
		numarr = ft_split(argv[i++], 32);
		is_possible(numarr);
		while (numarr[j] != 0)
			printf("%d\n", num = ft_atoi(numarr[j++]));
		if (numarr)
			ft_split_free(numarr, j);
	}
	return (0);
}
