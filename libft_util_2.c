/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_util_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:18:50 by hmoon             #+#    #+#             */
/*   Updated: 2022/03/18 22:05:58 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	unsigned char	*temp;

	temp = dst;
	if (!dst && !src)
		return (0);
	while (n--)
	{
		*temp++ = *(unsigned char *)src++;
	}
	return (dst);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] && i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s1)
{
	char		*temp;
	size_t		i;

	i = 0;
	temp = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	while (s1[i] != '\0')
	{
		temp[i] = s1[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != 0)
	{
		len++;
	}
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	len_s;

	if (!s || !len || ft_strlen(s) <= start)
		return (ft_strdup(""));
	len_s = ft_strlen(s);
	if (len_s + start < len)
		len = len_s - start;
	ret = (char *)malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	if (len_s > start)
		ft_strlcpy(ret, s + start, len + 1);
	return (ret);
}
