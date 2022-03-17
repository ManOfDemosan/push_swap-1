/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_util_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:16:43 by hmoon             #+#    #+#             */
/*   Updated: 2022/03/17 21:10:44 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	size_t	cset(char const *s, char c, size_t *count)
{
	size_t	cnt;

	*count = 0;
	cnt = 0;
	while (*s != 0)
	{
		if (*s != c)
		{
			*count += 1;
			cnt++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (cnt);
}

char	**ft_split_free(char **ret, size_t i)
{
	while (i >= 0)
	{
		free(ret[i]);
		ret[i] = NULL;
		if (i == 0)
			break ;
		i--;
	}
	free(ret);
	ret = NULL;
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	size;
	size_t	index;
	size_t	count;

	if (!s)
		return (NULL);
	ret = (char **)malloc(sizeof(char *) * (cset(s, c, &count) + 1));
	if (!ret)
		return (NULL);
	index = 0;
	while (index < count)
	{
		size = 0;
		while (*s == c && *s != '\0')
			s++;
		while (s[size] != c && s[size] != '\0')
			size++;
		ret[index++] = ft_substr(s, 0, size);
		if (!ret)
			return (ft_split_free(ret, index - 1));
		s += size;
	}
	ret[index] = 0;
	return (ret);
}

static	int	is_white_minus(const char *str, int *minus)
{
	int	i;

	i = 0;
	*minus = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*minus *= -1;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	long long	ret;
	long long	tmp;
	int			minus;
	int			i;

	ret = 0;
	i = is_white_minus(str, &minus);
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp = ret * 10 + str[i] - '0';
		if (tmp < ret)
			return ((minus + 1) / -2);
		ret = tmp;
		i++;
	}
	return ((int)ret * minus);
}
