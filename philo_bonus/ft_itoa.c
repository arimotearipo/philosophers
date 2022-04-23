/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:26:08 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/23 19:44:16 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static	int	countdigits(long int n)
{
	int	digits;

	if (n == 0)
		return (1);
	digits = 0;
	if (n < 0)
	{
		digits++;
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	char			*num;
	int				size;
	long int		newn;

	newn = n;
	size = countdigits(newn) + 1;
	if (newn < 0)
		newn = newn * -1;
	num = malloc(size);
	if (!num)
		return (NULL);
	num[size - 1] = '\0';
	size = size - 2;
	while (size >= 0)
	{
		num[size] = newn % 10 + '0';
		newn = newn / 10;
		size--;
		if (newn == 0)
			break ;
	}
	if (n < 0)
		num[size] = '-';
	return (num);
}
