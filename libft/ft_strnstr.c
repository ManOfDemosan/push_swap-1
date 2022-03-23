/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 07:24:41 by hmoon             #+#    #+#             */
/*   Updated: 2022/01/17 16:54:43 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_needle;
	int		cmp;

	if (*needle == '\0')
		return ((char *)haystack);
	len_needle = ft_strlen((char *)needle);
	while (*haystack != 0 && len >= len_needle)
	{
		cmp = ft_memcmp(haystack, needle, len_needle);
		if (*haystack == *needle && cmp == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
