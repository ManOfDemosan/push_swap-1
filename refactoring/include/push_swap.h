/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 23:11:46 by hmoon             #+#    #+#             */
/*   Updated: 2022/03/23 03:12:01 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

# define TRUE 1
# define FALSE 0

# define INT_MAX 2147483647LL
# define INT_MIN -2147483648LL

typedef struct s_stack
{
	int			*data;
	int			len;
	int			size;
}				t_stack;

enum	e_order
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
};

void		is_sorted(t_stack *a);
void		init_stack(t_stack *stack);

void		make_stack_b(t_stack *b, int size);
void		make_stack_a(t_stack *stack, int num);
void		make_index(t_stack *a);

void		push_back(t_stack *stack, int num);
void		pop_back(t_stack *stack);
void		push_stack(t_stack *stack, int num);


void		print_error();
void		parse_num(t_stack *stack, char **argv);

#endif
