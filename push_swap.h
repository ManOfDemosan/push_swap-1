/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:21:50 by hmoon             #+#    #+#             */
/*   Updated: 2022/03/18 22:25:19 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	int			*data;
	size_t		len;
	size_t		size;
}				t_stack;

void	*ft_memcpy(void *dst, void *src, size_t n);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
void	is_possible(char **str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split_free(char **ret);
void	print_error(void);
void	init_stack(t_stack *stack);
void	make_stack(t_stack *stack, int num);
void	is_duplicate(t_stack *stack);

#endif
