/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:08:47 by hmoon             #+#    #+#             */
/*   Updated: 2022/03/17 21:10:29 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_possible(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != 0)
	{
		j = 0;
		while (str[i][j] != 0)
		{
			if (!((str[i][j] >= '0' && str[i][j] <= '9') || \
			(str[i][j] == '+' || str[i][j] == '-')))
			{
				write(1, "Error\n", 6);
				exit(0);
			}
			if (j > 0 && (str[i][j] == '+' || str[i][j] == '-'))
			{
				write(1, "Error\n", 6);
				exit(0);
			}
			j++;
		}
		i++;
	}
}