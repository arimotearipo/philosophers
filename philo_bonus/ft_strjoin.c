/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 10:37:42 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/24 15:27:49 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*newsrc;
	unsigned char	*newdst;

	i = 0;
	if (!dst && !src)
		return (NULL);
	newsrc = (unsigned char *)src;
	newdst = (unsigned char *)dst;
	while (i < n)
	{
		newdst[i] = newsrc[i];
		i++;
	}
	return (dst);
}

static char	*ft_strdup(const char *s)
{
	int		count;
	int		i;
	char	*news;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	news = malloc(sizeof(char) * (count + 1));
	if (!news)
		return (NULL);
	i = 0;
	while (i < count)
	{
		news[i] = s[i];
		i++;
	}
	news[i] = '\0';
	return (news);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1len;
	int		s2len;
	char	*finalstr;

	if (!s1 || !s2)
		return (ft_strdup(""));
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	finalstr = malloc(s1len + s2len + 1);
	if (!finalstr)
		return (NULL);
	ft_memcpy(finalstr, s1, s1len);
	finalstr += s1len;
	ft_memcpy(finalstr, s2, s2len + 1);
	return (finalstr - s1len);
}
