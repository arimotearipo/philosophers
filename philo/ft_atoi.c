/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:01:30 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/19 18:11:56 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *s)
{
	int			i;
	long int	neg;
	long int	sum;

	i = 0;
	sum = 0;
	neg = 1;
	while (s[i] == 32 || (s[i] > 7 && s[i] < 14))
	{
		i++;
	}
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			neg = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		sum = sum * 10 + s[i] - '0';
		i++;
	}
	return (sum * neg);
}
