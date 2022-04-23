/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 10:37:42 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/23 20:00:04 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
